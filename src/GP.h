//
//  GP.h
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/08.
//
//

#ifndef __GPGame__GP__
#define __GPGame__GP__

#include <iostream>
#include "Game.h"
#include "Tree.h"
#include "Keys.h"
#include "EnemyList.h"

class GP{
#define GEN_SIZE 256
  Game * _games[GEN_SIZE];
  Tree * _nextLeftKeyTree[GEN_SIZE];
  Tree * _nextRightKeyTree[GEN_SIZE];
  Tree * _nextSpaceKeyTree[GEN_SIZE];
  float _gameVal[GEN_SIZE];
  Keys * _keys;
  int _gpCounter;
  EnemyList * _enemyList;/////////////EnemyList//////////////

public:
  GP(EnemyList * enemyList);
  void setKeyOn(int key);
  void setKeyOff(int key);
  void stepGeneration();
  void update();
  void draw(float posX, float posY);
  int roulette();
  
  void loadMap();
  //-----------------------------------CHANGED-----------------------------------------------//
  void setEnemyList(EnemyList * enemyList);
  //-----------------------------------CHANGED-----------------------------------------------//
};

#endif /* defined(__GPGame__GP__) */
