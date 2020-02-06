void screen()
{

  u8x8.setCursor(0, 0);
  u8x8.print("RPM");
  u8x8.setCursor(10, 0);
  if (TELEM.rpm < 10)
    u8x8.print('0');
  if (TELEM.rpm < 100)
    u8x8.print('0');
  if (TELEM.rpm < 1000)
    u8x8.print('0');
  if (TELEM.rpm < 10000)
    u8x8.print('0');
  u8x8.print(TELEM.rpm);

  u8x8.setCursor(0, 1);
  u8x8.print("RADIO");
  u8x8.setCursor(10, 1);
  if (radio_thr < 1000)
    u8x8.print('0');
  u8x8.print(radio_thr);

  u8x8.setCursor(0, 2);
  u8x8.print("BATTERY");
  u8x8.setCursor(10, 2);
  u8x8.print(volt);

  u8x8.setCursor(0, 3);
  u8x8.print("CURRENT");
  u8x8.setCursor(10, 3);
  if (TELEM.curr < 100)
    u8x8.print('0');
  u8x8.print(TELEM.curr);

  u8x8.setCursor(0, 4);
  u8x8.print("SPD");
  u8x8.setCursor(10, 4);
  if (TELEM.spd < 10)
    u8x8.print('0');
  u8x8.print(TELEM.spd);

  u8x8.setCursor(0, 5);
  u8x8.print("KV");
  u8x8.setCursor(10, 5);
  if (kv < 1000)
    u8x8.print('0');
  if (kv < 100)
    u8x8.print('0');
  if (kv < 10)
    u8x8.print('0');
  u8x8.print(kv);

  /*
    u8x8.setCursor(0, 4);
    u8x8.print("THR");
    u8x8.setCursor(10, 4);
    if (thr < 100)
    u8x8.print('0');
    if (thr < 10)
    u8x8.print('0');
    u8x8.print(thr);

    u8x8.setCursor(0, 5);
    u8x8.print("BRK");
    u8x8.setCursor(10, 5);
    if (brk < 100)
    u8x8.print('0');
    if (brk < 10)
    u8x8.print('0');
    u8x8.print(brk);
  */

  u8x8.setCursor(0, 6);
  u8x8.print("MOT TEMP");
  u8x8.setCursor(10, 6);
  if (TELEM.tmot < 10)
    u8x8.print('0');
  u8x8.print(TELEM.tmot);

  u8x8.setCursor(0, 7);
  u8x8.print("ESC TEMP");
  u8x8.setCursor(10, 7);
  if (TELEM.tesc < 10)
    u8x8.print('0');
  u8x8.print(TELEM.tesc);
}
