/*
*P30-1
*設計Arduino 程式，使用Arduino 板配合CDS 元件偵測光線的強弱，
*並以LED 指示光線的強弱。當光線轉暗時，閃爍LED，當光線轉強時，關閉LED。
*/

#define BLINK_SPEED 100 //ms
#define THRESHOLD 512 //The threshold to turn off/on LED ,from 0~1023

const byte cds = A0; //CDS sensor pin
const uint8_t led = 13;

unsigned long last_blink = 0;
bool led_state = 0;
bool over_threshold = 0;

void setup()
{
	pinMode(led, OUTPUT);
}

void loop()
{
	unsigned long now = millis();
	
	if(analogRead(cds)>THRESHOLD) over_threshold = false;
	else over_threshold = true;

	if(now-last_blink > BLINK_SPEED) //每隔固定時間檢查是否超過閃爍的interval
	{
		digitalWrite(led, led_state & !over_threshold);
		last_blink = now; //更新最後一次執行時間
		led_state = !led_state; //LED狀態反轉	
	}
}