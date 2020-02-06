void current()
{
    int miliVoltsPerAmp = 40;
    int acOffset = 2500;
    int rawSense = analogRead(CUR_PIN);
    float voltageValue = (rawSense / 1023.0) * 5000;
    TELEM.curr = ((voltageValue - acOffset)/miliVoltsPerAmp); 
    TELEM.curr = 0;
}
