//
//  GodView.h
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/15.
//
//

//#ifndef __GPGame__GodView__
//#define __GPGame__GodView__

#pragma once

class GodView;


#include <iostream>
#include "ofMain.h"
#include "Stage.h"
#include "Keys.h"


class GodView{
  Stage * _stage;
  Keys * _keys;
  float _posX;
  float _posY;

public:
  GodView();
  ~GodView();
  void update();
  void draw();
  float getPosX();
  float getPosY();
  void setKeyOn(int key);
  void setKeyOff(int key);

  void selectPrevStage();
  void selectNextStage();
  void selectStage(int stageNum);

  void loadMap();

};

//#endif /* defined(__GPGame__GodView__) */
