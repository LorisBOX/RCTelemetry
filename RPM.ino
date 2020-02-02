void rpmsensor()
{
  count++;
  if ( interruptCalled ) {
    currTime = micros();
    timeDiff = currTime - lastTime;
    DATA2.rpm = ((interruptCount) * (60)) / 2 * 10;
    interruptCalled = false;
    interruptCount = 0;
    lastTime = currTime;
  }

  // CALCUL VITESSE
  DATA2.spd = (DATA2.rpm / ratio) * tire * 0.0001885;

}

void rpmcount()
{
  interruptCount++;
  interruptCalled = true;
}
