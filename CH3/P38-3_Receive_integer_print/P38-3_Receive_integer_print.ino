/*
*P38-
*從Arduino板接收傳腦傳送的訊息，並於Serial Monitor視窗顯示所接收的數字
*須可接收與顯示 -32768以上到32767以下的數字。
*/

char c = '\n';
int n = 0;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	if(Serial.available() > 0)
	{
		if(c != '\r')
		{
			c = Serial.read();
			Serial.print("Received:");
			Serial.println(c);
		}
		Serial.print("Total:");
		Serial.println(n);
	}
	
}