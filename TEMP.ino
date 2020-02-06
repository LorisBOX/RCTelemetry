void temp()

{

  // TEMPERATURE MOTEUR (Capteur TMP36)
  float tempmotvoltage = analogRead(TEMPMOT_PIN) * refVcc;
  tempmotvoltage /= 1024.0;
  TELEM.tmot = (tempmotvoltage - 0.5) * 100;

  // TEMPERATURE ESC (Capteur TMP36)
  float tempescvoltage = analogRead(TEMPESC_PIN) * refVcc;
  tempescvoltage /= 1024.0;
  TELEM.tesc = (tempescvoltage - 0.5) * 100;
  

  if (TELEM.tmot > 60)
    tempalarm = true;

  if (TELEM.tesc > 60)
    tempalarm = true;

}
