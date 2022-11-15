// page 208   라이트 라이더~~

const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

int seq[14] = {1, 2, 4, 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2};
void setup() {
  // put your setup code here, to run once:
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 14; i++)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLK, MSBFIRST, seq[i]);
    digitalWrite(LATCH, HIGH);
    delay(100);
  }
}
