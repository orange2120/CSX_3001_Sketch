/*
*P81-1 回家作業
*利用一個 按鍵開關控制四利用一個 按鍵開關控制四LED 移位方向。每按一下按鍵開關， LED的移動方向改變。
*若LED 原來移動方向為左，按一下鍵開關時改變為右。
*若LED 原來移動方向為右，按一下鍵開關時改變為左。
*/

const uint8_t led[4] = {6,9,10,11};
                      //左                右
const uint8_t sw = 12; //宣告開關輸入腳位

#define SHIFT_INTERVAL 200 //ms，LED shift的間隔
#define DEBOUNCE_INTERVAL 10 //ms，開關去彈跳的間隔

unsigned long last_shift = 0;
int i = 0; //LED index
int dir = 1; //1代表向右，-1代表向左

bool temp_state = 0;
bool sw_state = 0;

void setup()
{
	pinMode(sw, INPUT_PULLUP); //使用內建上拉電阻
	for(int i=0;i<4;i++) pinMode(led[i], OUTPUT);
	for(int i=0;i<4;i++) digitalWrite(led[i], LOW);
}

void loop() //每隔500ms左移一個LED，至最左邊則重新開始
{
	unsigned long now = millis();
	temp_state = digitalRead(sw);
	if(!temp_state)               //開關去彈跳
	{
		delay(DEBOUNCE_INTERVAL);
		while(!digitalRead(sw));
		sw_state = !sw_state;
		if(sw_state) dir = 1; //判斷位移方向
		else dir = -1;
	}
	
	if(now-last_shift >= SHIFT_INTERVAL)
	{
		digitalWrite(led[i], LOW);
		i+=dir;
		if(i > 3) i = 0;       //避免LED index 超出邊界
		else if(i < 0) i = 3;
		digitalWrite(led[i], HIGH);
		last_shift = now;
	}
}