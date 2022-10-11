const int motor = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i++)
  {
    analogWrite(motor, i);
    delay(10);
  }
  delay(2000);
  for(i = 255; i >= 0; i--)
  {
    analogWrite(motor, i);
    delay(10);

  }
  delayI(2000);
}
