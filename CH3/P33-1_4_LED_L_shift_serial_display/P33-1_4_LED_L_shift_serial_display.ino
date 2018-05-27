/*
*P33-1
*設計Arduino 程式，使用Arduino 板控制LED 單燈左移，同時將LED 目前狀態傳送至電腦中。
*當LED 亮時，狀態為HIGH；當LED 暗時，狀態為LOW。
*/

const uint8_t led[4] = {10,11,12,13};
                       //左                  右

#define SHIFT_INTERVAL 500 //ms，LED shift的間隔
unsigned long last_shift = 0;
int i = -1;

bool led_state[4] = {0,0,0,0};

void setup()
{
	for(int i=0;i<4;i++) pinMode(led[i], OUTPUT);
	for(int i=0;i<4;i++) digitalWrite(led[i], LOW);
	
	Serial.begin(9600);
}

void loop()
{
	unsigned long now = millis();
	if(now-last_shift >= SHIFT_INTERVAL)
	{
		digitalWrite(led[i], LOW);
		led_state[i] = false;
		i--;
		if(i < 0) i = 3;       //避免LED index 超出邊界
		digitalWrite(led[i], HIGH);
		led_state[i] = true;
		print_LED_state();
		last_shift = now;
	}
}

void print_LED_state(void)
{
	for(int i=0;i<4;i++) Serial.print(led_state[i]);
	Serial.println();
}