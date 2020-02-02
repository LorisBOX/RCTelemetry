#include <Wire.h> 
#include <U8x8lib.h>
#include <Servo.h>
#include <EasyTransfer.h>
#include <RunningAverage.h>

// Ports
#define RPM_PIN 2          // Capteur RPM (Interrupt 1, Digital Pin 2) / OrangeRX RPM sensor
#define THR_PIN 3          // Signal THR (Interrupt 0, Digital Pin 3) / Sur voie 2 du recepteur
#define ESC_PIN 4          // Sortie ESC
#define FAN_PIN 5          // Ventilateur Moteur
#define VOLT_PIN A0        // Capteur Tension (Diviseur)
#define CUR_PIN A1         // Capteur de courant ACS758
#define TEMPMOT_PIN A2     // Capteur Temperature Moteur TMP36
#define TEMPESC_PIN A3     // Capteur Temperature Variateur TMP36
#define LED_PIN 13         // LED interne

// Variables Utilisateur
const uint8_t mod = 1;            // Modele 1
const float refVcc = 5.0;         // Tension de reference de l'arduino
const uint8_t cells = 2;          // Nombre de d'elements de la batterie
float cellvolt = 3.2;
float voltmin = 6.5;
const float ratio = 5.1;          // Ratio final transmission
const uint8_t tire = 65;          // Diametre pneus (en mm)
const int NEUTRAL_THR = 1500;     // Signal RC THR Neutre
const int MIN_THR = 1100;         // Signal RC THR minimum
const int MAX_THR = 1900;         // Signal RC THR maximum
const int RPMLIMIT = 15000;       // Limiteur RPM

// Valeurs lissées avec la librairie RunningAverage
RunningAverage Volt(100);


// Variables Diverses (Hors Structure ET)
float volt = 0.00;
uint8_t fuel = 0;
uint16_t previousMillis = 0;
bool voltalarm = false;
bool tempalarm = false;
bool motalarm = false;

// Variables capteur RPM
bool interruptCalled = false;
int count;
int interruptCount;
int lastTime = 0;
int currTime = 0;
int timeDiff = 0;

//Variables Voies RC
volatile int radio_thr = NEUTRAL_THR; // volatile, we set this in the Interrupt and read it in loop so it must be declared volatile
volatile unsigned long ulStartPeriod = 0; // set in the interrupt
volatile bool bNewThrottleSignal = false; // set in the interrupt and read in the loop

// Ecran
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

// Sortie ESC
Servo esc;

// Structures de données envoi et réception
EasyTransfer ETin, ETout;

struct RECEIVE_DATA_STRUCTURE {
};

struct SEND_DATA_STRUCTURE {
  uint8_t mod;
  uint16_t rad;
  uint16_t rpm;
  uint8_t spd;
  uint8_t bat;
  uint8_t curr;
  uint8_t tmot;
  uint8_t tesc;
};

RECEIVE_DATA_STRUCTURE DATA1;
SEND_DATA_STRUCTURE DATA2;


void setup()
{
  digitalWrite(LED_PIN, HIGH);
  attachInterrupt(digitalPinToInterrupt(RPM_PIN), rpmcount, CHANGE);
  attachInterrupt(digitalPinToInterrupt(THR_PIN), calcInput, CHANGE);
  pinMode(RPM_PIN, INPUT);
  pinMode(THR_PIN, INPUT);
  pinMode(ESC_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(VOLT_PIN, INPUT);
  pinMode(CUR_PIN, INPUT);
  pinMode(TEMPMOT_PIN, INPUT);
  pinMode(TEMPESC_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  esc.attach(ESC_PIN, 1000, 2000);
  Serial.begin(9600);
  ETin.begin(details(DATA1), &Serial);
  ETout.begin(details(DATA2), &Serial);
  Volt.clear();
  Wire.begin();
  u8x8.begin();
  u8x8.clear();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  uint16_t currentMillis = millis();
  
  // Execution sans delai
  throttle();
  fan();
  
  // Execution toutes les 100ms
  if (currentMillis - previousMillis >= 100) {
    previousMillis = currentMillis;

    rpmsensor();
    volts();
    current();
    datasend();
    screen();
    temp();
  }
    

  }
