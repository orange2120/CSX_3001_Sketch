/*
*P45-2
*設計Arduino 程式，使用Arduino 板配合超音波距離感測器測量物體的距離
*（單位：公分），以Serial Monitor 視窗顯示距離，並控制一個LED 閃爍速度及一個蜂鳴器嗶聲，
*距離愈近，則LED 閃爍速度愈快且蜂鳴器嗶聲愈急促。
*/

#define TRIG_PIN 2
#define ECHO_PIN 3

#define FREQ 523 //Hz, frequency of speaker

const uint8_t led = 13;
const uint8_t speaker_pin = 11;

int blink_speed = 100; //Default 100 ms
unsigned long last_blink = 0;
bool led_state = 0;

void setup()
{
	Serial.begin(9600);

	pinMode(led, OUTPUT);
	pinMode(speaker_pin, OUTPUT);
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
}

void loop()
{
	unsigned long now = millis();
	long dist = ping();

	blink_speed = dist*10; //換算距離與閃爍時間間隔

	Serial.println(dist);

	if(now-last_blink >= blink_speed)
	{
		digitalWrite(led, led_state);
		
		if(led_state) tone(speaker_pin, FREQ);
		else noTone(speaker_pin);
		
		led_state = !led_state;
		last_blink = now;
	}
}

long ping(void)
{
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN ,HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);
	return pulseIn(ECHO_PIN, HIGH)/58;
}
