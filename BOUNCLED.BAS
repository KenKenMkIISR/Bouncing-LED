REM Bouncing LEDs for MachiKania type P
REM  with WS2812B Class

USECLASS WS2812B
USEVAR LED_NUM,DIN_GPIO,REVERSE,BLOCK,BRIGHT,GRAVITY,R1,R2,REFMINV,BOTTOM
USEVAR WAIT1,WAIT2,COL,LED

LED_NUM  = 144:REM Number of NeoPixels
DIN_GPIO = 0  :REM Pin where NeoPixels are connected
REVERSE  = 0  :REM If True, LED block will fall off from the end of the LED strip

BLOCK  =  8:REM Length of LED block
BRIGHT = 60:REM LED brightness
GRAVITY= 20:REM Gravitational acceleration

REM Bounce coefficient = R1/R2
R1 = 3 :REM Bounce coefficient 1
R2 = 5 :REM Bounce coefficient 2
REFMINV = -80:REM Minimum bounce speed (Adjust when the bounce does not end)
WAIT1=5:REM Block falling speed 1(ms)
WAIT2=5:REM Block falling speed 2(ms)

LED=NEW(WS2812B,LED_NUM,DIN_GPIO)
COL=1:REM Color 0=off, 1=red ... 8=green ... 16=blue ... 24=red

DO
 BOTTOM=LED_NUM<<8
 WHILE BOTTOM>0
  Y=0:V=0
  WHILE Y<BOTTOM
   GOSUB SETBLOCK,Y>>8,COL
   LED.PUTLED()
   DELAYMS WAIT1
   GOSUB SETBLOCK,Y>>8,0
   V=V+GRAVITY:Y=Y+V
   IF Y>=BOTTOM THEN
    Y=BOTTOM-256:V=-V*R1/R2
    IF V>REFMINV THEN
     GOSUB SETBLOCK,(BOTTOM>>8)-1,COL
     BOTTOM=BOTTOM-(BLOCK<<8)
     COL=(COL+18)%24+1
    ENDIF
   ENDIF
  WEND
 WEND
 LED.PUTLED()
 DELAYMS 500

 Y=0:V=0
 WHILE Y<LED_NUM<<8
  Y=Y+V:V=V+GRAVITY/2
  FOR I=LED_NUM-1 TO Y>>8 STEP -1
   X=(I<<8)+(Y AND 255)-V
   IF X>=Y THEN
    IF REVERSE THEN
     LED.CPYLED(LED_NUM-(X>>8)-1,LED_NUM-I-1)
    ELSE
     LED.CPYLED(X>>8,I)
    ENDIF
   ELSE
    IF REVERSE THEN
     LED.SETLED(LED_NUM-I-1,0,0,0)
    ELSE
     LED.SETLED(I,0,0,0)
    ENDIF
   ENDIF
  NEXT
  LED.PUTLED()
  DELAYMS WAIT2
 WEND
 DELAYMS 500

LOOP
END

LABEL SETBLOCK
 VAR C,Y,I,R,G,B
 Y=ARGS(1):C=ARGS(2)
 IF C=0 THEN
  R=0:G=0:B=0
 ELSEIF C<=8 THEN
  R=(8-C)*BRIGHT>>3
  G=C*BRIGHT>>3
  B=0
 ELSEIF C<=16 THEN
  R=0
  G=(16-C)*BRIGHT>>3
  B=(C-8)*BRIGHT>>3
 ELSEIF C<=24 THEN
  R=(C-16)*BRIGHT>>3
  G=0
  B=(24-C)*BRIGHT>>3
 ELSE
  RETURN
 ENDIF
 FOR I=0 TO BLOCK-1
  IF Y<0 THEN BREAK
  IF REVERSE THEN
   LED.SETLED(LED_NUM-Y-1,R,G,B)
  ELSE
   LED.SETLED(Y,R,G,B)
  ENDIF
  Y=Y-1
 NEXT
RETURN
