/*
*P14-1
*設計Arduino 程式，使用Arduino 板讀取兩個類比電壓值，並顯示於Serial Monitor視窗。
*/

const byte in_1 = A0;
const byte in_2 = A1;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.print(analogRead(in_1)/1024.0*5.0, 2);
	Serial.print(',');
	Serial.println(analogRead(in_2)/1024.0*5.0, 2);
	delay(100);
}