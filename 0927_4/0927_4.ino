//p79 포토레지스터 이용한~~~ 

const int WLED = 9;
const int LIGHT = 0;
const int MIN_LIGHT = 200;
const int MAX_LIGHT = 900;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(WLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(LIGHT);
  // 책에는 18번줄 맵의 인자가 255, 0순서임. 왜 이렇게했냐면 우리가사용한 led가 전원이 거끄로라서.
  val = map(val, MIN_LIGHT, MAX_LIGHT, 0, 255);
  val = constrain(val, 0, 255);
  analogWrite(WLED, val);
}
