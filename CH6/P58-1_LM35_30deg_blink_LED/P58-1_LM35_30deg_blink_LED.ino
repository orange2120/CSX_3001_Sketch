/*
*P58-1
*設計Arduino 程式，使用Arduino 板配合LM35 溫度感測器測量環境溫度，
*以Serial Monitor 視窗顯示環境溫度，當環境溫度大於30°C 時，閃爍LED。
*/

#define BLINK_INTERVAL 200
#define SEND_INTERVAL 500 //ms，interval between sending serial data

const byte lm35_pin = A0;

const uint8_t led = 13;

uint32_t last_send = 0;
uint32_t last_blink = 0;
bool led_state = 0;

long temperature = 0;

void setup()
{
	Serial.begin(9600);
	
	pinMode(led, OUTPUT);
}

void loop()
{
	uint32_t now = millis();
	
	temperature = get_temp(lm35_pin);
	
	if(now-last_send >= SEND_INTERVAL)
	{
		Serial.print(temperature);
		Serial.println(" degC");
		last_send = now;
	}
	
	if(now-last_blink >= BLINK_INTERVAL && temperature > 30)
	{
		digitalWrite(led, led_state);
		led_state = !led_state;
		last_blink = now;
	}
}

long get_temp(byte pin)
{
	int val;
	val = analogRead(pin);
	return (long)val*500/1024;
}