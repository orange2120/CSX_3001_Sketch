/*
*P26-2
*設計Arduino 程式，利用Arduino 板播放鋼琴入門音樂—小星星（Little Star）。
*小星星簡譜如表11-3 所示，每一段有4 小節，每小節有4 拍，演奏速度是每分鐘120 拍。
*使用6 個LED 顯示C、D、E、F、G、A 等6 個目前正在播放的音符
*/

const int led[] = {5, 6, 7, 8, 9, 10}; //define LED pins

const int speaker_pin = 11;
const char toneName[] = "CDEFGA";
const int tones[] = {262, 294, 330, 349, 392, 440};
                   //c    d    e    f    g    a

char starTone[] = "CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";
//                                                     |       |        |       |         |      |         |      |         |       |        |
uint8_t starBeat[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2};
int starLen=sizeof(starTone);

unsigned long tempo = 120; //beats per minute

void setup()
{
	pinMode(speaker_pin, OUTPUT);
	for(int i=0;i<6;i++) pinMode(led[i], OUTPUT);
}

void loop()
{
	for(int i=0;i<starLen;i++)
	{
		playTone(starTone[i], starBeat[i]);
	}
	delay(5000); //Repeat after  5 seconds
}

void playTone(char toneNo, uint8_t beatNo)
{
	unsigned long duration=beatNo*60000/tempo;
	for(int j=0;j<=6;j++)
	{
		if(toneNo == toneName[j])
		{
			tone(speaker_pin, tones[j]);
			digitalWrite(led[j], HIGH);
			delay(duration);
		}
		noTone(speaker_pin);
		digitalWrite(led[j], LOW);
	}
}