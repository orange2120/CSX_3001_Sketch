/*
*P27-3
*設計Arduino 程式，使用Arduino 板透過串列埠傳送26個小寫英文字母及其10進制ASCII 碼訊息至電腦中。
*/

void setup()
{
	Serial.begin(9600);
	for(int i=0;i<26;i++)
	{
		Serial.print(i+1);
		Serial.print(':');
		Serial.write('a'+i);
		Serial.print(',');
		Serial.print('a'+i);
		Serial.print('\n');
	}
}

void loop()
{

}