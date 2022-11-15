// page 204 시프트 레지스터

const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, MSBFIRST, B00000001);
  digitalWrite(LATCH, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
