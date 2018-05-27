/*
*P27-2
*設計Arduino 程式，以Arduino 板透過串列埠傳送26個大寫英文字母及其16 進制ASCII 碼訊息至電腦中。
*/

void setup()
{
	Serial.begin(9600);
	for(int i=0;i<26;i++)
	{
		Serial.print(i+1);
		Serial.print(':');
		Serial.write('A'+i);
		Serial.print(',');
		Serial.print('A'+i, HEX);
		Serial.print('\n');
	}
}

void loop()
{

}