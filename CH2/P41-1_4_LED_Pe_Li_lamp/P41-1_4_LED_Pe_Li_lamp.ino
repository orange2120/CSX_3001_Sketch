/*
*P41-1
*設計Arduino 程式，控制四個LED 執行霹靂燈閃爍移位變化。
*/

#define SHIFT_INTERVAL 200 //ms

const uint8_t led[4] = {10,11,12,13};
//                  最左      最右
uint8_t i = 0; //Current LED index
int dir = 1; //1右，-1向左

void setup()
{
	pinMode(led[0], OUTPUT);
	pinMode(led[1], OUTPUT);
	pinMode(led[2], OUTPUT);
	pinMode(led[3], OUTPUT);
	
	digitalWrite(led[0], LOW);
	digitalWrite(led[1], LOW);
	digitalWrite(led[2], LOW);
	digitalWrite(led[3], LOW);
	}

void loop()
{
	for(uint8_t j=0;j<4;j++) digitalWrite(led[j], LOW); //shift後全數關閉LED
	if(i>=3) dir = -1;     //LED index >= 3 則切換方向向左
	else if(i<=0) dir = 1; //LED index <= 0 則切換方向向右
	digitalWrite(led[i], HIGH);
	delay(SHIFT_INTERVAL); //每隔固定時間進行shift
	i += dir;              //LED index+方向
}
