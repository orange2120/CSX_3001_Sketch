/*
*P24-3
*請設計一電路，可量一3號電池之電壓，以5顆LED顯示其剩餘電量(電壓)。
*/

const byte input = A0;
const uint8_t led[5] = {7, 8, 9, 10, 11};

int vol_index = 0; //voltage index from 0 to 9
int val = 0; //alalogRead value

void setup()
{
	for(int i=0;i<5;i++)
	{
		pinMode(led[i], OUTPUT);
	}
}

void loop()
{
	val = analogRead(input);
	if(val >= 307) val = 307;
	vol_index = map(val, 0, 307, 0, 4);
	
	for(int i=0;i<=vol_index;i++)
	{
		digitalWrite(led[i], HIGH);
	}
	for(int i=vol_index+1;i<5;i++)
	{
		digitalWrite(led[i], LOW);
	}
}