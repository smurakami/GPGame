#pragma once

class EnemyList;

#include "ofMain.h"
#include "Stage.h"
#include "Keys.h"
#include "Enemy.h"
#include "Game.h"

class EnemyList{
private:
  Stage * _stage;
  Enemy * _enemyArray;
  Game * _game;
  int _enemyNum;
  int _height;
  int _width;

public:
  EnemyList(Stage * stage);
  ~EnemyList();
  void update();
  void draw(float gamePosX, float gamePosY);////////////////changed!!!!
  void setGameClass(Game * game);
  int getEnemyNum();
//-----------------------------------CHANGED-----------------------------------------------//
  bool getEnemyAlive(int i);
  void loadMap();
  void draw(Game * game);
  float getEnemyX(int i);
  float getEnemyY(int i);
//-----------------------------------CHANGED-----------------------------------------------//
  Enemy * getEnemyArray();
};
