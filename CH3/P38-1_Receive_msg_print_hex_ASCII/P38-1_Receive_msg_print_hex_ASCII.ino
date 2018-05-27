/*
*P38-1
*設計Arduino 程式，從Arduino 板接收電腦傳送的訊息，並於Serial Monitor 視窗顯
*示其16 進制ASCII 碼。
*/

char c = '\n';

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	if(Serial.available() > 0)
	{
		c = Serial.read();
		Serial.print("Received:");
		Serial.println(c,HEX);
	}
}