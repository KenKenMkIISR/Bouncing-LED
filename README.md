# 跳ねるLEDアニメーション
市販のLEDテープのデモンストレーションがつまらないので、楽しめるアニメーションを作りました。  
WS2812B搭載Adafruit NeoPixel互換LEDテープをArduino UNOやRaspberry Pi Picoで制御します。  

ArduinoではArduino IDEにNeoPixel用のライブラリを追加し、スケッチ「LED_bouncing.ino」をコピーしてご利用ください。  
  
Raspberry Pi Picoでは https://github.com/benevpi/pico_python_ws2812b からダウンロードした「ws2812b.py」をThonnyなどでRaspberry Pi Pico本体に保存し、「LED_bouncing_Pico.py」を実行してください。  
  
LEDの総数、1ブロックの長さ、重力加速度、跳ね返り係数などのパラメータは変更可能です。  

動画はこちら https://youtu.be/mlCTygT_cpE
![](bouncingLED.jpg)

# 接続
LEDテープ側　　Arduino ／ Raspberry Pi Pico  
　　GND　　　　GND　／　　　GND  
　　DIN　　　　　 6　　／　　GPIO0  
  
# 利用について
本プログラムは公共の場を含め、誰でも自由にご利用いただけます。  
改変も可能です。ぜひご活用ください。
