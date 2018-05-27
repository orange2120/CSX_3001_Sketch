/*
*P47-2
*設計Arduino 程式，從Arduino 板接收電腦訊息控制LED 閃爍與暗。按鍵a、b、c、d
*分別控制四個LED 狀態在閃爍與暗之間變化。
*/

#define BLINK_INTERVAL 200 //ms

const uint8_t led[4] = {10,11,12,13};
                        //左              右
bool led_state[4] = {0,0,0,0}; //分別紀錄4個LED狀態
bool led_blink_state = 0;
unsigned long last_blink = 0;

void setup()
{
	Serial.begin(9600);

	for(int i=0;i<4;i++) pinMode(led[i], OUTPUT);
	for(int i=0;i<4;i++) digitalWrite(led[i], LOW);
}

void loop()
{
	if(Serial.available() > 0)
	{
		char c = Serial.read();
		int n = (int)(c-'a');
		if(n>=0 && n<=3) led_state[n] = !led_state[n];
	}
	
	unsigned long now = millis();
	if(now-last_blink > BLINK_INTERVAL) //每隔固定時間檢查是否超過閃爍的interval
	{
		for(int i=0;i<4;i++) digitalWrite(led[i], led_blink_state & led_state[i]);
		last_blink = now; //更新最後一次執行時間
		led_blink_state = !led_blink_state; //LED狀態反轉
	}
}