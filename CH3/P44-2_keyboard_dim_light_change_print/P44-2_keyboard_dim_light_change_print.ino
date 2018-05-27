/*
*P44-2
*設計Arduino 程式，接收電腦鍵盤輸入鍵值來控制LED 並顯示提示訊息。輸入0 鍵
*則LED 暗，輸入1 鍵則LED 亮，輸入2 鍵則LED 快閃，輸入3 鍵則LED 慢閃。
*/

#define SLOW_BLINK_INTERVAL 1000 //ms 慢閃間隔
#define FAST_BLINK_INTERVAL 200  //ms 快閃間隔

const int led = 13;

char c = '0';
int n = 0;

unsigned long last_blink = 0;
bool led_state = 0;

void setup()
{
	Serial.begin(9600);
	
	pinMode(led, OUTPUT);
}

void loop()
{
	if(Serial.available() > 0)
	{
		c = Serial.read();
		switch(c)
		{
			case '0': //關閉
				Serial.println("OFF");
			break;
			case '1': //關閉
				Serial.println("ON");
			break;
			case '2': //關閉
				Serial.println("Fast blink");
			break;
			case '3': //關閉
				Serial.println("Slow blink");
			break;
		}
	}
	
	unsigned long now = millis();
	
	switch(c)
	{
		case '0': //關閉
			digitalWrite(led, LOW);
		break;
		case '1': //開啟
			digitalWrite(led, HIGH);
		break;
		case '2': //快閃
			if(now-last_blink > FAST_BLINK_INTERVAL) //每隔固定時間檢查是否超過閃爍的interval
			{
				digitalWrite(led, led_state);
				last_blink = now; //更新最後一次執行時間
				led_state = !led_state; //LED狀態反轉
			}
		break;
		case '3': //慢閃
			if(now-last_blink > SLOW_BLINK_INTERVAL)
			{
				digitalWrite(led, led_state);
				last_blink = now;
				led_state = !led_state;
			}
		break;
	}
}