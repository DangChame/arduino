// page 48
const int LED = 11;

void setup() {
  // put your setup code here, to run once:

  // 디지털 핀들의 입출력을 지정해준다. 전원을 출력해야하므로 OUTPUT으로 지정해주었음.
  pinMode(LED, OUTPUT);
}


// analogWrite는 아날로그 출력을 위한?  왜 256개인 0~255이냐? 2^8이라
void loop() {
  for (int i = 0; i < 256; i++)
  {
    // HIGH = 5V, LOW = 0V 를 인가한다.
    analogWrite(LED, i);
    delay(10);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        );
  }
  for (int i = 255; i >= 0; i--)
  {
    // HIGH = 5V, LOW = 0V 를 인가한다.
    analogWrite(LED, i);
    delay(10);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        );
  }
}
