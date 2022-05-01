// Boucing LED for PIC16F18313 by KENKEN

#include "mcc_generated_files/mcc.h"

#define LED_NUM 144  //LEDの総数
#define REVERSE //有効にすると逆向きに落下

#define BLOCK 8 //LEDブロックの長さ
#define BRIGHT 60 //明るさ
#define GRAVITY 20 //重力加速度

//最下点での跳ね返り係数＝R1/R2
#define R1 3 //跳ね返り係数1
#define R2 5 //跳ね返り係数2
#define REFMINV -80 //跳ね返り最小速度

// Timer0 Interrupt
volatile uint16_t delaycounter=0;
void one_ms_interrupt(void){
	delaycounter++;
}
void delayms(uint16_t t){
	while(delaycounter<t)
		asm("SLEEP"); // Go to Idle mode
	delaycounter=0;
}

uint8_t	LEDs[LED_NUM]; //LED色配列　0（消灯）, 1（赤）～8（緑）～16（青）～24（赤）
uint8_t col=1; //落下中のLEDブロックの色

void LEDshow(void){
	// NeoPixelにLEDs配列を出力
	uint8_t c;
	for(uint8_t i=0;i<LED_NUM;i++){
#ifdef REVERSE
		c=LEDs[LED_NUM-1-i];
#else
		c=LEDs[i];
#endif
		if(c==0){
			SPI1_Exchange8bit(0);
			SPI1_Exchange8bit(0);
			SPI1_Exchange8bit(0);
		}
		else if(c<=8){
			SPI1_Exchange8bit((uint16_t)c*BRIGHT>>3);
			SPI1_Exchange8bit((uint16_t)(8-c)*BRIGHT>>3);
			SPI1_Exchange8bit(0);
		}
		else if(c<=16){
			SPI1_Exchange8bit((uint16_t)(16-c)*BRIGHT>>3);
			SPI1_Exchange8bit(0);
			SPI1_Exchange8bit((uint16_t)(c-8)*BRIGHT>>3);
		}
		else if(c<=24){
			SPI1_Exchange8bit(0);
			SPI1_Exchange8bit((uint16_t)(c-16)*BRIGHT>>3);
			SPI1_Exchange8bit((uint16_t)(24-c)*BRIGHT>>3);
		}
		else return;
	}
}

void set_block(uint16_t y,uint8_t c){
	//LEDブロック表示
	//y 表示するLEDブロックの先頭位置
	//c 表示色 0（消灯）, 1（赤）～8（緑）～16（青）～24（赤）

	for(uint8_t i=0;i<BLOCK;i++){
		LEDs[y]=c;
		if(y==0) break;
		y--;
	}
}

void main(void)
{
	// initialize the device
	SYSTEM_Initialize();
	TMR0_SetInterruptHandler(one_ms_interrupt);

	// Enable the Global Interrupts
	INTERRUPT_GlobalInterruptEnable();

	// Enable the Peripheral Interrupts
	INTERRUPT_PeripheralInterruptEnable();

	CPUDOZE=0x80; // Idle Enable

	int32_t y; //LEDブロック先頭位置（0が一番上）
	int32_t v; //落下速度
	int32_t h; //最下点位置
	while (1){
		//跳ねるLEDのループ
		h=(int32_t)LED_NUM<<8;
		do{
			//LEDブロック初期位置、初期速度設定
			y=0;
			v=0;
			do{
				set_block((uint16_t)(y>>8),col); //LEDブロック表示
				LEDshow();
				delayms(10);
				set_block((uint16_t)(y>>8),0); //LEDブロック消去
				v=v+GRAVITY; //落下速度更新
				y=y+v; //LEDブロック先頭位置更新
				if(y>=h){ //最下点に衝突の場合
					y=h-256; //衝突位置に戻す
					v=-v*R1/R2; //跳ね返り
					if(v>REFMINV){ //ある一定値より跳ね返り速度が小さい場合に停止
						set_block((uint16_t)(h>>8)-1,col); //現在の最下点の上にLEDブロックを固定表示
						h=h-(int32_t)(BLOCK*256); //最下点を1ブロック分上げる
						col=col+19;//次の色に変更
						if(col>=25) col-=24;
					}
				}
			} while(y<h); //LEDブロックの先頭が最下点より上にある間繰り返す
		} while(h>=256); //最下点が1未満になるまで繰り返す
		LEDshow();
		delayms(500);

		//接続されたLED全体の落下
		y=0; //接続されて落下するLEDの最後尾の位置
		v=0; //全体の落下速度
		do{
			y=y+v; //最後尾位置更新
			v=v+GRAVITY/2; //落下速度更新（摩擦を考慮）
			for(int16_t i=LED_NUM-1;i>=(int16_t)(y>>8);i--){
				int32_t y1=((int32_t)i<<8)+(y&0xff)-v; //LED番号iの位置に次に落ちて来るLEDの現在位置
				if(y1>=y){
					//y1の位置のLEDの色をLED番号iにコピー
					LEDs[i]=LEDs[(uint8_t)(y1>>8)];
				}
				else{
					//最後尾より上はLED消灯
					LEDs[i]=0;
				}
			}
			LEDshow();
			delayms(10);
		}while(y<(int32_t)LED_NUM<<8); //最後尾がLED総数を超えるまで繰り返し
		delayms(500);
	}
}
