/*
*P38-3
*�qArduino�O�����Ǹ��ǰe���T���A�é�Serial Monitor������ܩұ������Ʀr
*���i�����P��� -32768�H�W��32767�H�U���Ʀr�C
*/

/*
*!!!!!!�@�w�n�� \n ����!!!!!!*
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
		while((c = Serial.read())!= '\n') //�P�_�O�_�w������J
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