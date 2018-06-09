/*
*P19-1
*設計Arduino 程式，使用Arduino 板讀取類比電壓值，控制LED 閃爍速度。
*當類比電壓值愈小時，LED 閃爍速度愈快，當類比電壓值愈大時，LED 閃爍速度愈慢。
*/

#define MIN_BLINK_SPEED 10 //ms
#define MAX_BLINK_SPEED 2000 //ms

const byte input = A0;
const uint8_t led = 13;

int blink_speed = 100; //default speed

unsigned long last_blink = 0;
bool led_state = 0;

void setup()
{
	pinMode(led, OUTPUT);
}

void loop()
{
	unsigned long now = millis();

	blink_speed = map(analogRead(input), 0, 1023, MIN_BLINK_SPEED, MAX_BLINK_SPEED);
	
	if(now-last_blink >= blink_speed) //每隔固定時間檢查是否超過閃爍的interval
	{
		digitalWrite(led, led_state);
		last_blink = now; //更新最後一次執行時間
		led_state = !led_state; //LED狀態反轉
	}
}