void fan()
{
  if (DATA2.rpm > 1000)
  digitalWrite(FAN_PIN, HIGH);
  else
  digitalWrite(FAN_PIN, LOW);  
}
