void volts()
{
  volt = analogRead(VOLT_PIN) * refVcc / 1024 * cells;
  TELEM.bat = (volt * 10);
  
  //
  uint8_t fuelmap = map(TELEM.bat, 65, 86, 0, 100);
  uint8_t fuel = constrain(fuelmap, 0, 100);
  //
  
  if (volt < voltmin)
  voltalarm = true;
  else
  voltalarm = false;
}
