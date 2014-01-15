#pragma once

class LocalEnemyList;

#include "ofMain.h"
#include "Stage.h"
#include "Keys.h"
#include "Enemy.h"
#include "MainChara.h"
#include "EnemyList.h"


class LocalEnemyList{
private:
  MainChara * _mainChara;
  EnemyList * _enemyList;
  int _enemyNum;
  Enemy * _enemyArray;
  bool * _alive;

public:
  LocalEnemyList(EnemyList * enemyList, MainChara * mainChara);
  ~LocalEnemyList();
  void update();
  void CD();
  //-----------------------------------CHANGED-----------------------------------------------//
  void setEnemyList(EnemyList * enemyList);
  bool _EnemyIsDead(int i);
  //-----------------------------------CHANGED-----------------------------------------------//
};
