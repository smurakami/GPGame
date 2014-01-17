
#include "ofMain.h"
#include "Stage.h"
#include "Keys.h"
#include "MainChara.h"
#pragma once

class Enemy{
private:
  Stage * _stage;
  float _defaultX;
  float _defaultY;
  float _posX;
  float _posY;
  float _speedX;
  float _speedY;

  bool _dead;
  bool _outside;
  bool _active;

public:
  Enemy();
  Enemy(Stage * stage);
  ~Enemy();
  void update();
  void draw(float gamePosX, float gamePosY);
  float getPosX();
  float getPosY();
  bool isDead();
  void setDefaultPosition(Stage * stage, float x, float y);
};
