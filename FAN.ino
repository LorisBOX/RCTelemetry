void fan()
{
  if (TELEM.rpm > 1000)
  digitalWrite(FAN_PIN, HIGH);
  else
  digitalWrite(FAN_PIN, LOW);  
}
