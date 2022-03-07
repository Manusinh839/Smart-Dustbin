#include<Servo.h>
Servo srv;
long duration1;
int distance1;
#define echoPin1 5
#define trigPin1 6
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  srv.attach(7);
  delay(1000);
  srv.write(0);
}

void loop()
{

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  if (distance1 < 30)
  {
    srv.write(90);
    delay(1000);
  }
  else
  {
    delay(1000);
    srv.write(0);
    delay(1000);
  }
}
