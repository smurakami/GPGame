//
//  Sensor.h
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/05.
//
//


//#ifndef __GPGame__Sensor__
//#define __GPGame__Sensor__

#pragma once

class Sensor;

#include <iostream>
#include "Stage.h"
#include "EnemyList.h"
#include "LocalEnemyList.h"
#define SENSOR_NUM 24
#define MAP_CHIP_SIZE 32


class Sensor{
  bool _field[SENSOR_NUM];
  bool _enemy[SENSOR_NUM];
  bool _item[SENSOR_NUM];
  bool _isAbleToJump;
  
public:
  Sensor();
  bool field(int index);
  bool enemy(int index);
  bool item(int index);

  void update(Stage * stage, EnemyList *enemyList, LocalEnemyList *_localEnemyList, int enemyNum, float posX, float posY, bool isAbleToJump);

};


//#endif /* defined(__GPGame__Sensor__) */
