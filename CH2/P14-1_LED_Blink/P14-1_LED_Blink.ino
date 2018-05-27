/*
*P14-1
*設計Arduino 程式，控制一個LED 閃爍，0.5 秒亮、0.5 秒暗。
*/

const int led = 13;

void setup()
{
	pinMode(led, OUTPUT);
}

void loop()
{
	digitalWrite(led, HIGH);
	delay(500);
	digitalWrite(led, LOW);
	delay(500);
}