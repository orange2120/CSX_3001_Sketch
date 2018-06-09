/*
*設計Arduino 程式，使用Arduino 板讀取類比電壓值0~5V，並以10 個LED 排閃爍
*顯示對應的類比電壓值，每個LED 代表0.5V 電壓刻度。
*/

#define BLINK_SPEED 100 //ms

const byte input = A0;
const uint8_t led[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int vol_index = 0; //voltage index from 0 to 9
int val = 0; //analogRead value

unsigned long last_blink = 0;
bool led_state = 0;

void setup()
{
	for(int i=0;i<10;i++)
	{
		pinMode(led[i], OUTPUT);
	}
}

void loop()
{
	unsigned long now = millis();

	val = analogRead(input);
	vol_index = map(val, 0, 1023, 0, 9);
	
	if(now-last_blink > BLINK_SPEED) //每隔固定時間檢查是否超過閃爍的interval
	{
		for(int i=0;i<=vol_index;i++)
		{
			digitalWrite(led[i], led_state);
		}
		for(int i=vol_index+1;i<10;i++)
		{
			digitalWrite(led[i], LOW);
		}
		last_blink = now; //更新最後一次執行時間
		led_state = !led_state; //LED狀態反轉
	}
}