
//3.1절 가변저항값 읽기임p70

const int POT = 0;
int val = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);
  Serial.println(val);
  delay(500);
}
