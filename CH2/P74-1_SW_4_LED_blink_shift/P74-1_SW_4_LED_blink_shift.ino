/*
*P74-1
*設計Arduino 程式，使用一個指撥開關控制四個LED 移位方向。當開關斷開（OFF）時，LED 單燈閃爍右移；當開關接通（ON）時，LED 單燈閃爍左移。
*/

const uint8_t led[4] = {10,11,12,13};
                        //左              右
const uint8_t sw = 9; //宣告開關輸入腳位

#define BLINK_INTERVAL 100 //ms，LED閃爍的間隔
#define SHIFT_INTERVAL 500 //ms，LED shift的間隔

unsigned long last_blink = 0;
unsigned long last_shift = 0;
bool led_state = 0;
int i = 0; //LED index

void setup()
{
	pinMode(sw, INPUT_PULLUP); //使用內建上拉電阻
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
	unsigned long now = millis();
	if(now-last_shift >= SHIFT_INTERVAL)
	{
		digitalWrite(led[i], LOW);
		if(digitalRead(sw)) i++;
		else i--;
		if(i > 3) i = 0;       //避免LED index 超出邊界
		else if(i < 0) i = 3;
		last_shift = now;
	}

	if(now-last_blink >= BLINK_INTERVAL) //每隔固定時間檢查是否需要閃爍
	{
		digitalWrite(led[i], led_state);
		last_blink = now; //更新最後一次執行時間
		led_state = !led_state; //LED狀態反轉
	}
}