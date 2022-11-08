// 시리얼 포트 데이터를 익어 응용 프로그램 창의 배경색을 변경하는 프로세싱 스케치다.

//p. 178

import processing.serial.*;
Serial port;

float brightness = 0;

void setup()
{
  size(500, 500);
  port = new Serial(this, "/dev/cu.usbmodem143201", 9600);
  port.bufferUntil('\n');
}

void draw()
{
  background(0, 0, brightness);
}

void serialEvent (Serial port)
{
  brightness = float(port.readStringUntil('\n'));
}
