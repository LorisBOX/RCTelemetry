void current()
{
    int miliVoltsPerAmp = 40;
    int acOffset = 2500;
    int rawSense = analogRead(CUR_PIN);
    float voltageValue = (rawSense / 1023.0) * 5000;
    DATA2.curr = ((voltageValue - acOffset)/miliVoltsPerAmp); 
}
