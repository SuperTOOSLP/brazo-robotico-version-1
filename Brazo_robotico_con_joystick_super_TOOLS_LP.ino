
//Super TOOLS LP//

#include<Servo.h>
Servo servo_x;
Servo servo_y;
Servo servo_z;

int pul = 7;

int joy_x = A0;
int joy_y = A1;
int x;
int y;

void setup ()
{
  Serial.begin(9600);
  servo_x.attach(5);
  servo_y.attach(6);
  servo_z.attach(9);
  pinMode(pul, INPUT_PULLUP);
  
}
void loop()
{
  int lector_x = analogRead(joy_x); /////////para el servo base
  x = map(lector_x, 0, 1023, 0, 180);
  servo_x.write(x);
  delay(10);

  int lector_y = analogRead(joy_y); //////// para el servo que sube y baja
  y = map(lector_y, 0, 1023, 0, 180);
  servo_y.write(y);

  if(digitalRead(pul) == HIGH) ///////////// para el servo que agarra
  {
    servo_z.write(0);
  }
  else
  {
    servo_z.write(40);
  }
}
