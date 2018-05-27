/*
*P36-2
*設計Arduino 程式，控制四個LED 單燈閃爍左移。
*/

#define blink_interval 100 //ms，LED閃爍的間隔
#define duration 500 //ms，切換LED的間隔

const int led_1 = 10; //最左
const int led_2 = 11;
const int led_3 = 12;
const int led_4 = 13; //最右

void setup()
{
	pinMode(led_1, OUTPUT);
	pinMode(led_2, OUTPUT);
	pinMode(led_3, OUTPUT);
	pinMode(led_4, OUTPUT);
	
	digitalWrite(led_1, LOW);
	digitalWrite(led_2, LOW);
	digitalWrite(led_3, LOW);
	digitalWrite(led_4, LOW);
}

void loop() //輪流呼叫閃爍副函式
{
	blink_LED(led_4);
	blink_LED(led_3);
	blink_LED(led_2);
	blink_LED(led_1);
}

void blink_LED(int pin)
{
	bool led_state = 0;
	unsigned long start_time = millis();
 	unsigned long last_time = 0;
	while(millis()-start_time <= duration) //當現在時間減掉開始時間小(等)於設定的期間，則持續執行
	{
		if(millis()-last_time >= blink_interval) //檢查時間是否已經超過閃爍間隔
		{
			digitalWrite(pin, led_state);
			led_state = !led_state; //狀態反轉
			last_time = millis(); //紀錄切換後當前的時間
		}
	}
	digitalWrite(pin, LOW); //結束前關閉LED
}