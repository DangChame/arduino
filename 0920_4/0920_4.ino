// page 54
const int LED = 9;
const int button = 2;
boolean lastbutton = LOW;
boolean currentbutton = LOW;
boolean ledOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  
}

/*디바운싱 함수 버튼의 이전 상태를 매개변수로 전달하면 디바운싱된 버튼의 현재 상태를 얻을 수 이땅
*/

boolean debounce(boolean last)
{
  boolean current = digitalRead(button);
  if (last != current)
  {
    delay(5);
    current = digitalRead(button);
    
  }
  return (current);
  
}
/*
//디바운싱이 없는 함수로 만들어봄. 실행해보면 불안정하기때문에 버튼의 눌림을 제대로 인식하지 못하는걸 관측 가능하다.
boolean debounce(boolean last)
{
  boolean current = digitalRead(button);
  if (last != current)
  {
    current = digitalRead(button);
    
  }
  return (current);
  
}
*/


void loop() {
  currentbutton = debounce(lastbutton);
  if (lastbutton == LOW && currentbutton == HIGH)
  {
    ledOn = !ledOn;
  }
  lastbutton = currentbutton;
  digitalWrite(LED, ledOn);

}
