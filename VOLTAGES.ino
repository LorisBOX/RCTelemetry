void volts()
{
  volt = analogRead(VOLT_PIN) * refVcc / 1024 * cells;
  uint8_t voltint = (volt * 10);
  Volt.addValue(voltint);
  DATA2.bat = Volt.getAverage();
  
  //
  uint8_t fuelmap = map(DATA2.bat, 65, 86, 0, 100);
  fuel = constrain(fuelmap, 0, 100);
  //
  
  if (DATA2.bat < voltmin * 10)
  voltalarm = true;
  else
  voltalarm = false;
}
