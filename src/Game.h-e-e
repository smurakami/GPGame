//
//  Game.h
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/02.
//
//

//#ifndef __GPGame__Game__
//#define __GPGame__Game__
#pragma once

class Game;


#include <iostream>
#include "ofMain.h"
#include "MainChara.h"
#include "Stage.h"
#include "Keys.h"
#include "Node.h"
#include "Tree.h"
#include "Sensor.h"
#include "EnemyList.h"
#include "LocalEnemyList.h"


//*--------------  GP Tree --------------*//
//*------------- End GP Tree ------------*//

class Game {
private:
  Stage * _stage;
  MainChara * _mainChara;
  Keys * _keys;
  float _posX;
  float _posY;
  EnemyList * _enemyList;
  LocalEnemyList * _localEnemyList;
  
  //*--------------  GP Tree --------------*//
  bool _controlledByTree;
  Tree * _leftKeyTree;
  Tree * _rightKeyTree;
  Tree * _spaceKeyTree;
  void _runTrees();
  Sensor * _sensor;
  //*------------- End GP Tree ------------*//
public:
  Game(EnemyList * enemyList);//////////////////Enemy////////////////
  Game(Tree * left, Tree * right, Tree * space, EnemyList *enemyList);///////////////////Enemy//////////////////
  ~Game();
  
  void setKey(int key);
  
  void update();
  void draw();
  //*--------------  GP Tree --------------*//
  void enableHumanControl();
  void draw(float posX, float posY);
  float getPosX();
  float getPosY();
  float getProgress();
  Tree * leftKeyTree();
  Tree * rightKeyTree();
  Tree * spaceKeyTree();
  //*------------- End GP Tree ------------*//

  bool isOver();
  
  //controlled by human interface
  void setKeyOn(int key);
  void setKeyOff(int key);

  void loadMap();
//-----------------------------------CHANGED-----------------------------------------------//
  void setEnemyList(EnemyList *enemyList);
  bool enemyIsDead(int i);
//-----------------------------------CHANGED-----------------------------------------------//

};

//#endif /* defined(__GPGame__Game__) */
