/*
*P38-
*�qArduino�O�����Ǹ��ǰe���T���A�é�Serial Monitor������ܩұ������Ʀr
*���i�����P��� -32768�H�W��32767�H�U���Ʀr�C
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