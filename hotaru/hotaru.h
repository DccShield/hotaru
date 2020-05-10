//--------------------------------------------------------------------------------
// レイアウト用蛍点灯用スケッチです。
// [hotaru.h]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
// https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#ifndef hotal_h
#define hotal_h

enum{
  HEIKE = 0,
  GENJI2,
  GENJI4,
};

class hotaru
{
public:
  hotaru(unsigned char ch,unsigned char mode);
  void stateCheck();
  
private:
  char state = ST_INIT;
  unsigned char port;
  unsigned char mode;
  unsigned long Previous;
  int brink;
  float brite;
  int wait;
  float tb;

  enum{
    ST_INIT = 0,
    ST_IDLE,
    ST_ON,
    ST_OFF,
    ST_LOOP,
    ST_WAIT,
  };
  
};

#endif
