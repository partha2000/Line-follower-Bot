//LINE FOLLWER BOT

//******************************
int lm1 = 5, lm2 = 6, rm1 = 9, rm2 = 10;      //lm1+  lm2-  rm1+  rm2-
int l1 = 3, l2 = 4, l3 = A0, cl = A1, cr = A2, r3 = A3, r2 = A4, r1 = A5;
int ir1 = 12, ir2 = 8, ir3 = 7;
int a, b, c, d, e, f, g, h, x;
//remove pin 1 and 2 l belled cable tx/rx while programming
void forward()

{
  analogWrite(lm1, 120);
  analogWrite(lm2, 0);
  analogWrite(rm1, 120);
  analogWrite(rm2, 0);
}
void slowForward()
{
  analogWrite(lm1, 100);
  analogWrite(lm2, 0);
  analogWrite(rm1, 100);
  analogWrite(rm2, 0);
}
void back()
{
  analogWrite(lm2, 160);
  analogWrite(lm1, 0);
  analogWrite(rm2, 160);
  analogWrite(rm1, 0);
}


void right()
{
  analogWrite(lm1, 150);
  analogWrite(lm2, 0);
  analogWrite(rm1, 0);
  analogWrite(rm2, 150);
}
void left()
{
  analogWrite(lm1, 0);
  analogWrite(lm2, 150);
  analogWrite(rm1, 150);
  analogWrite(rm2, 0);
}
void softRight()
{
  analogWrite(lm1, 170);
  analogWrite(lm2, 0);
  analogWrite(rm1, 0);
  analogWrite(rm2, 40);
}
void softLeft()
{
  analogWrite(lm1, 0);
  analogWrite(lm2, 40);
  analogWrite(rm1, 170);
  analogWrite(rm2, 0);
}

void setup()
{ pinMode(l1, INPUT);
  pinMode(l2, INPUT);
  pinMode(l3, INPUT);
  pinMode(cl, INPUT);
  pinMode(cr, INPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  pinMode(r3, INPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  Serial.begin(9600);
  x = 0;
}
void loop()
{
  a = digitalRead(l1);
  b = digitalRead(l2);
  c = digitalRead(l3);
  d = digitalRead(cl);
  e = digitalRead(cr);
  f = digitalRead(r3);
  g = digitalRead(r2);
  h = digitalRead(r1);
  /*Serial.print(a);
    Serial.print(b);
    Serial.print(c);
    Serial.print(d);
    Serial.print(e);
    Serial.print(f);
    Serial.print(g);
    Serial.print(h);
    Serial.println();
    delay(500);
  */
  /*code for two IR sensors
    if (cl == 1 && cr==1)
    forward();
    else if (cl==1 && cr==0)
    left();
    else if (cl==0 && cr==1)
    right();
    else if (cl==0 && cr==0)
    forward();
  */
  // Tht code above is for two IR senosrs based bot

  
  if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 1 && g == 1 && h == 1)
    forward();
  if (a == 0 && b == 0 && c == 0 && d == 1 && e == 1 && f == 0 && g == 0 && h == 0)
    forward();
  else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 1 && g == 1 && h == 1)
    softLeft();
  else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0 && g == 1 && h == 1)
    softRight();
  else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 1 && g == 1 && h == 1)
    left();
  else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0)
    right();
  else if (a == 1 && b == 0 && c == 0 && d == 0 && e == 0 && f == 1 && g == 1 && h == 1)
    left();
  else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0 && g == 0 && h == 1)
    right();
  //    else if (a == 0 && b == 0 && c == 0 && d == 1 && e == 1 && f == 1 && g == 0&& h == 0)
  //    softRight();
  //   else if (a == 0 && b == 0 && c == 1 && d == 1 && e == 1 && f == 0 && g == 0 && h == 0)
  //   softLeft();
  //   else if (a == 0 && b == 0 && c == 0&& d == 1 && e == 1 && f == 1 && g == 1 && h == 0)
  //right();
  //else if (a ==0 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0 && g == 0 && h == 0)
  //left();
  else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0 && g == 0 && h == 0)
    right();
  else if (a == 0 && b == 0 && c == 0 && d == 1 && e == 1 && f == 1 && g == 1 && h == 1)
    left();
  else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 1 && g == 1 && h == 1)
  {
    slowForward();
  }
  else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0)
  {
    slowForward();
  }
  //   else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 1)
  //   softRight();
  //   else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 1 && h == 1)
  //   softRight();
  //   else if (a == 1 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0)
  //   softLeft();
  //   else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0)    //I had added this parts to make sure that in case the bot gets out of the track it can make comeback.
  //   softLeft();                                                                                // you can add that if you wish.
  else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 1 && f == 1 && g == 1 && h == 1)
    softLeft();
  else if (a == 0 && b == 0 && c == 1 && d == 1 && e == 1 && f == 1 && g == 1 && h == 1)
    softLeft();
  else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 1 && g == 1 && h == 0)
    softRight();
  else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 1 && g == 0 && h == 0)
    softRight();
  else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 1 && f == 1 && g == 1 && h == 1)
    softLeft();
  else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0 && g == 1 && h == 1)
    softRight();
  else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0)
  {

    right();
  }
  else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 1 && h == 1)
  {

    left();
  }
  else
  {
    forward();
    //delay(250);
  }
}
