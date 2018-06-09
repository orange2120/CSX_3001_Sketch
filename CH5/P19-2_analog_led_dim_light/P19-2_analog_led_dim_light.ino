/*
*P19-2
*設計Arduino 程式，使用Arduino 板讀取類比電壓值，控制LED 亮度。
*當類比電壓值愈小時，LED 較暗，當類比電壓值愈大時，LED 較亮。
*/

const byte input = A0;
const uint8_t led = 11;

int val = 0;

void setup()
{
}

void loop()
{
	val = analogRead(input);
	analogWrite(led, map(val, 0, 1023, 0, 255));
}