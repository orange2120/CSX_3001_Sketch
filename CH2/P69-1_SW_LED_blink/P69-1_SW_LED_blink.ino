/*
*P69-1
*設計Arduino 程式，使用一個指撥開關控制一個LED，當開關接通(ON)時，LED 閃爍，當開關斷開(OFF)時，LED 關閉。
*/

const uint8_t led = 13;
const uint8_t sw = 10; //宣告開關輸入腳位

#define BLINK_INTERVAL 200 //ms，LED閃爍間隔
unsigned long last_blink = 0;
bool led_state = 0;

void setup()
{
	pinMode(led, OUTPUT);
	pinMode(sw, INPUT_PULLUP); //使用內建上拉電阻
}

void loop()
{
	unsigned long now = millis();
	if(now-last_blink >= BLINK_INTERVAL) //每隔固定時間檢查是否需要閃爍
	{
		digitalWrite(led, led_state & !digitalRead(sw)); //只有在led_state和sw都是1的時候才閃爍
		last_blink = now; //更新最後一次執行時間
		led_state = !led_state; //LED狀態反轉
	}
}