//
//  Application.h
//  GPGameEnemy
//
//  Created by 村上 晋太郎 on 2013/05/14.
//
//

//#ifndef __GPGameEnemy__Application__
//#define __GPGameEnemy__Application__

#pragma once

class Application;

#include <iostream>
#include "GP.h"
#include "Game.h"
#include "GodView.h"
#include "EnemyList.h"
#include "Stage.h"

class Application{
  GP * _gp;
  Game * _game;
  GodView * _godView;
  ofImage _titleScreen;
  ofRectangle _windowRect;
  EnemyList * _enemyList;
  Stage * _stage;
  
  enum {
    TITLE_MODE,
    GP_MODE,
    SINGLE_MODE,
    STAGE_SELECT_MODE,
    APP_MODE_NUM
  } _appMode, _prevAppMode;
  
  
  
public:
  Application();
  ~Application();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);

//---------------------------

void drawGameOver();

};


//#endif /* defined(__GPGameEnemy__Application__) */
