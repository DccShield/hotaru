//--------------------------------------------------------------------------------
// レイアウト用蛍点灯用スケッチです。
// [hotaru.ino]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------


#include "hotaru.h"

hotaru hotaruA = hotaru(3, GENJI2); 
hotaru hotaruB = hotaru(5, GENJI2);
hotaru hotaruC = hotaru(6, GENJI2);
hotaru hotaruD = hotaru(9, GENJI2);
hotaru hotaruE = hotaru(10, GENJI2);
hotaru hotaruF = hotaru(11, GENJI2);

void setup() {
}

void loop() {
  hotaruA.stateCheck();
  hotaruB.stateCheck();
  hotaruC.stateCheck();
  hotaruD.stateCheck();
  hotaruE.stateCheck();
  hotaruF.stateCheck();
}
