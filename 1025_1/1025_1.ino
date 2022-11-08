const int POT = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(POT);
  int per = map(val, 0, 1023, 0, 100);
  Serial.print("Analog Reading: ");
  Serial.print(val);
  Serial.print(" Percentage: ");
  Serial.print(per);
  Serial.println("%");
  delay(1000);
}
