#include <Servo.h>

const int SERVO = 9;
const int POT = 0;

Servo myservo;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);
  val = map(val, 0, 1023, 0, 179); //가변저항값을 각도로 변환한것임
  myservo.write(val);
  delay(15);
}
