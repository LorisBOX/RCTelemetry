void rpmsensor()
{
  TELEM.rpm = 0;
  count++;
  if ( interruptCalled ) {
    currTime = micros();
    timeDiff = currTime - lastTime;
    TELEM.rpm = ((interruptCount) * (60)) / 2 * 10;
    interruptCalled = false;
    interruptCount = 0;
    lastTime = currTime;
  }


  // CALCUL VITESSE
  TELEM.spd = (TELEM.rpm / ratio) * tire * 0.0001885;

  // CALCUL KV
  kv = (TELEM.rpm / volt);

}

void rpmcount()
{
  interruptCount++;
  interruptCalled = true;
}
