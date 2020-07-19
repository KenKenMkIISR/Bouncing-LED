// 跳ねるLED by KenKen
// Arduino版

#include <Adafruit_NeoPixel.h>

#define PIN 6 //信号端子のピン番号
#define LED_NUM 144  //LEDの総数

#define BLOCK 8 //LEDブロックの長さ
#define BRIGHT 60 //明るさ
#define GRAVITY 20 //重力加速度

//最下点での跳ね返り係数＝R1/R2
#define R1 3 //跳ね返り係数1
#define R2 5 //跳ね返り係数2
#define REFMINV -80 //跳ね返り最小速度

Adafruit_NeoPixel LED = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

void set_block(uint16_t y,uint8_t c){
  //LEDブロック表示
  //y 表示するLEDブロックの先頭位置
  //c 表示色 0（消灯）, 1（赤）～8（緑）～16（青）～24（赤）
  uint32_t rgb;
  if(c==0) rgb=LED.Color(0,0,0);
  else if(c<=8)  rgb=LED.Color((uint16_t)(8-c)*BRIGHT>>3 ,(uint16_t)c*BRIGHT>>3, 0);
  else if(c<=16) rgb=LED.Color(0, (uint16_t)(16-c)*BRIGHT>>3 ,(uint16_t)(c-8)*BRIGHT>>3);
  else if(c<=24) rgb=LED.Color((uint16_t)(c-16)*BRIGHT>>3 ,0, (uint16_t)(24-c)*BRIGHT>>3);
  else return;

  for(uint8_t i=0;i<BLOCK;i++){
    if(y<0) break;
    LED.setPixelColor(y--,rgb);
  }
}

void setup() {
  // LED初期化、全体消去
  LED.begin();
  LED.show();
}
 
uint8_t col=1; //落下中のLEDブロックの色

void loop() {
  int32_t y; //LEDブロック先頭位置（0が一番上）
  int32_t v; //落下速度
  int32_t h=(int32_t)LED_NUM<<8; //最下点位置
  //跳ねるLEDのループ
  do{
    //LEDブロック初期位置、初期速度設定
    y=0;
    v=0;
    do{
      set_block((uint16_t)(y>>8),col); //LEDブロック表示
      LED.show();
      delay(10);
      set_block((uint16_t)(y>>8),0); //LEDブロック消去
      v=v+GRAVITY; //落下速度更新
      y=y+v; //LEDブロック先頭位置更新
      if(y>=h){ //最下点に衝突の場合
        y=h-256; //衝突位置に戻す
        v=-v*R1/R2; //跳ね返り
        if(v>REFMINV){ //ある一定値より跳ね返り速度が小さい場合に停止
          set_block((uint16_t)(h>>8)-1,col); //現在の最下点の上にLEDブロックを固定表示
          h=h-(int32_t)(BLOCK*256); //最下点を1ブロック分上げる
          col=(col+18)%24+1;//次の色に変更
        }
      }
    } while(y<h); //LEDブロックの先頭が最下点より上にある間繰り返す
  } while(h>=256); //最下点が1未満になるまで繰り返す
  LED.show();
  delay(500);

  //接続されたLED全体の落下
  y=0; //接続されて落下するLEDの最後尾の位置
  v=0; //全体の落下速度
  do{
    y=y+v; //最後尾位置更新
    v=v+GRAVITY/2; //落下速度更新（摩擦を考慮）
    for(int16_t i=LED_NUM-1;i>=(int16_t)(y>>8);i--){
      int32_t y1=((int32_t)i<<8)+(y&0xff)-v; //LED番号iの位置に次に落ちて来るLEDの現在位置
      if(y1>=y){
        LED.setPixelColor(i,LED.getPixelColor((uint16_t)(y1>>8))); //y1の位置のLEDの色をLED番号iにコピー
      }
      else{
        LED.setPixelColor(i,LED.Color(0,0,0)); //最後尾より上はLED消灯
      }
    }
    LED.show();
    delay(10);
  }while(y<(int32_t)LED_NUM<<8); //最後尾がLED総数を超えるまで繰り返し
  delay(500);
}

