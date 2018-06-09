/*
*P30-2
*設計Arduino 程式，使用Arduino 板配合CDS 元件偵測光線的強弱，
*並以三個LED指示光線的強弱。當光線轉暗時，只有LED1 亮；
*當光線介於全暗與全亮之間時，只有LED2 亮；
*當光線轉強時，只有LED3 亮。
*/

#define DIM_THRESHOLD 341 //Thre threshold of "Dim"
#define BRIGHT_THRESHOLD 682 //The threshold of "Bright"

const byte cds = A0; //CDS sensor pin
const uint8_t led[3] = {11, 12, 13};

int val = 0;

void setup()
{
	pinMode(led[0], OUTPUT);
	pinMode(led[1], OUTPUT);
	pinMode(led[2], OUTPUT);
}

void loop()
{
	val = analogRead(cds);
	if(val > BRIGHT_THRESHOLD)
	{
		digitalWrite(led[0], LOW);
		digitalWrite(led[1], LOW);
		digitalWrite(led[2], HIGH);
	}
	else if(val > DIM_THRESHOLD)
	{
		digitalWrite(led[0], LOW);
		digitalWrite(led[1], HIGH);
		digitalWrite(led[2], LOW);
	}
	else
	{
		digitalWrite(led[0], HIGH);
		digitalWrite(led[1], LOW);
		digitalWrite(led[2], LOW);
	}
}
