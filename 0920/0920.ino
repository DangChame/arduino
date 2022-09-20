// page 45
const int LED = 12;

void setup() {
  // put your setup code here, to run once:

  // 디지털 핀들의 입출력을 지정해준다. 전원을 출력해야하므로 OUTPUT으로 지정해주었음.
  pinMode(LED, OUTPUT);
}


// LED는 긴다리가 +극이므로 아두이노 +에서 출발한 도선은 긴다리로 연결.
void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 100; i <= 1000; i += 100)
  {
    // HIGH = 5V, LOW = 0V 를 인가한다.
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW);
    delay(i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          );
  }
}
