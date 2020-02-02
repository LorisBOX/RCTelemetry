void temp()

{

  // TEMPERATURE MOTEUR (Capteur TMP36)
  float tempmotvoltage = analogRead(TEMPMOT_PIN) * refVcc;
  tempmotvoltage /= 1024.0;
  DATA2.tmot = (tempmotvoltage - 0.5) * 100;

  // TEMPERATURE ESC (Capteur TMP36)
  float tempescvoltage = analogRead(TEMPESC_PIN) * refVcc;
  tempescvoltage /= 1024.0;
  DATA2.tesc = (tempescvoltage - 0.5) * 100;

  if (DATA2.tmot > 60)
    tempalarm = true;

  if (DATA2.tesc > 60)
    tempalarm = true;

}
