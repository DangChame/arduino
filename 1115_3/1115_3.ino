// page 211   거리센서이용~~

const int SER = 8;
const int LATCH = 9;
const int CLK = 10;
const int DIST = 0;

int vals[9] = {0, 1, 3, 7, 15, 31, 63, 127, 255};

int maxVal = 500;
int minVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = analogRead(DIST);
  distance = map(distance, minVal, maxVal, 0, 8);
  distance = constrain(distance, 0, 8);
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, MSBFIRST, vals[distance]);
  digitalWrite(LATCH, HIGH);
  delay(10);
}
