//--------------------------------------------------------------------------------
// レイアウト用蛍点灯用スケッチです。
// [hotaru.cpp]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
// https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#include <Arduino.h>
#include"hotaru.h"

// コンストラクタ
hotaru::hotaru( unsigned char ch, unsigned char mode)
{
  port = ch;
  pinMode(port, OUTPUT);
  state = ST_IDLE;
  wait = random(1,10);

  switch(mode){
    case HEIKE:             // ヘイケボタル１秒間隔
                tb = 5;
                break;
    case GENJI2:            // ゲンジボタル２秒間隔(西日本)
                tb = 2.5;
                break;
    case GENJI4:           // ゲンジボタル４秒間隔(東日本)
                tb = 1.275;
                break;
    default:
                break;            
  }
  
}  

void hotaru::stateCheck()
{
  switch(state){
    case ST_IDLE:
                  if((millis() - Previous) >= (wait * 300)) {
                    state = ST_INIT;
                  }
                  break;
    case ST_INIT:
                  Previous = millis();
                  brink = random(5,20);
                  wait = random(1,10);
                  brite = 0;
                  state = ST_ON;
                  break;
    case ST_ON:
                  if((millis() - Previous) >= 10) { 
                    brite = brite + tb;
                    if( brite >= 250 ){
                    Previous = millis();
                      state = ST_OFF;
                    }
                    analogWrite(port, brite);
                    Previous = millis();
                  }
                  break;
    case ST_OFF:
                  if((millis() - Previous) >= 10) {
                    brite = brite - tb;
                    if( brite <= 0 ){
                      Previous = millis();
                      state = ST_LOOP;
                    }
                    analogWrite(port, brite);
                    Previous = millis();
                  }
                  break;
    case ST_LOOP: 
                  brink = brink - 1;
                  if(brink <= 0){
                    state = ST_WAIT;
                    break;
                  }
                  state = ST_ON;                
                  break;
    case ST_WAIT:
                  if((millis() - Previous) >= (wait * 1000)) {
                    state = ST_INIT;
                  }
                  break;
    default:
                  break;
  }
}
