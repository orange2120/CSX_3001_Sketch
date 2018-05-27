/*
*P55-2
*設計Arduino 程式，接收電腦訊息控制LED 移位方向。按R 鍵則LED 單燈閃爍右移；
*按L 鍵則LED 單燈閃爍左移；按F 鍵則LED 同時閃爍；按S 鍵則關閉所有LED。
*/

#define BLINK_INTERVAL 200 //ms，LED同時blink的間隔
#define SHIFT_INTERVAL 500 //ms，LED shift的間隔
#define SHIFT_BLINK_INTERVAL 100 //ms，LED shift時blink的間隔

const uint8_t led[4] = {10,11,12,13};
                        //左              右
bool led_blink_state = 0;
unsigned long last_blink = 0;

int i = 0; //LED shift index
unsigned long last_shift = 0;
unsigned long last_shift_blink = 0;
bool led_shift_blink_state = 0;

char c = 'S';

void setup()
{
	Serial.begin(9600);

	for(int j=0;j<4;j++) pinMode(led[j], OUTPUT);
	for(int j=0;j<4;j++) digitalWrite(led[j], LOW);
}

void loop()
{
	if(Serial.available() > 0)
	{
		c = Serial.read();
		for(int j=0;j<4;j++) digitalWrite(led[j], LOW);
	}
	
	unsigned long now = millis();
	
	switch(c)
	{
		case 'R':
			if(now-last_shift >= SHIFT_INTERVAL)
			{	
				digitalWrite(led[i], LOW);
				i++;
				if(i > 3) i = 0;       //避免LED index 超出邊界
				else if(i < 0) i = 3;
				last_shift = now;
			}
			if(now-last_shift_blink >= SHIFT_BLINK_INTERVAL) //每隔固定時間檢查是否需要閃爍
			{
				led_shift_blink_state = !led_shift_blink_state;
				last_shift_blink = now;
				digitalWrite(led[i], led_shift_blink_state);
			}
		break;
		case 'L':
			if(now-last_shift >= SHIFT_INTERVAL)
			{	
				digitalWrite(led[i], LOW);
				i--;
				if(i > 3) i = 0;       //避免LED index 超出邊界
				else if(i < 0) i = 3;
				digitalWrite(led[i], HIGH);
				last_shift = now;
			}
			if(now-last_shift_blink >= SHIFT_BLINK_INTERVAL) //每隔固定時間檢查是否需要閃爍
			{
				led_shift_blink_state = !led_shift_blink_state;
				last_shift_blink = now;
				digitalWrite(led[i], led_shift_blink_state);
			}
		break;
		case 'F':
			if(now-last_blink >= BLINK_INTERVAL)
			{
				for(int j=0;j<4;j++) digitalWrite(led[j], led_blink_state);
				led_blink_state = !led_blink_state;
				last_blink = now;
			}
		break;
		case 'S':
			for(int j=0;j<4;j++) digitalWrite(led[j], LOW);
		break;
	}
}