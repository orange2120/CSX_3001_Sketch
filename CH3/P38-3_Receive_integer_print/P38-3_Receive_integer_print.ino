/*
*P38-3
*從Arduino板接收傳腦傳送的訊息，並於Serial Monitor視窗顯示所接收的數字
*須可接收與顯示 -32768以上到32767以下的數字。
*/

/*
*!!!!!!一定要用 \n 結尾!!!!!!*
*/

char c = '0';
int n = 0;

bool negative = 0; //

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	if(Serial.available() > 0)
	{
		while((c = Serial.read())!= '\n') //判斷是否已結束輸入
		{
			Serial.print("Received:");
			Serial.println(c);
			if(c == '-')
			{
				negative = 1;
				c = '0'; //drop '-' operator
			}
			n = n*10+(int)(c-'0');
			delay(10);
		}
		if(negative)
		{
			n *= -1;
			negative = 0;
		}
		Serial.print("Total:");
		Serial.println(n);
		n = 0;
	}
	
}