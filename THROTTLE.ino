void throttle()


{
  if (bNewThrottleSignal)
  {
    bNewThrottleSignal = false;
  }

  TELEM.rad = radio_thr;

  

}


void calcInput()
{

  // if the pin is high, its the start of an interrupt
  if (digitalRead(THR_PIN) == HIGH)
  {
    // get the time using micros - when our code gets really busy this will become inaccurate, but for the current application its
    // easy to understand and works very well
    ulStartPeriod = micros();
  }
  else
  {
    // if the pin is low, its the falling edge of the pulse so now we can calculate the pulse duration by subtracting the
    // start time ulStartPeriod from the current time returned by micros()
    if (ulStartPeriod && (bNewThrottleSignal == false))
    {
      radio_thr = (int)(micros() - ulStartPeriod);
      ulStartPeriod = 0;

      // tell loop we have a new signal on the throttle channel
      // we will not update nThrottleIn until loop sets
      // bNewThrottleSignal back to false
      bNewThrottleSignal = true;
    }
  }
}


// Code repris de https://rcarduino.blogspot.com/2012/01/how-to-read-rc-receiver-with.html
