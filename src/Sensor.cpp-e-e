//
//  Sensor.cpp
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/05.
//
//

#include "Sensor.h"
#include <cmath>

Sensor::Sensor(){
  for(int i = 0; i < SENSOR_NUM; i++){
    _field[i] = false;
    _enemy[i] = false;
    _item[i]  = false;
  }
}

bool Sensor::field(int index){
  if(index >= SENSOR_NUM){
    printf("Sensor: out of range sensor num\n");
    exit(1);
  }
  return _field[index];
}

bool Sensor::enemy(int index){
  if(index >= SENSOR_NUM){
    printf("Sensor: out of range sensor num\n");
    exit(1);
  }
  return _enemy[index];
}

bool Sensor::item(int index){
  if(index >= SENSOR_NUM){
    printf("Sensor: out of range sensor num\n");
    exit(1);
  }
  return _item[index];
}

void Sensor::update(Stage *stage, EnemyList * enemyList, LocalEnemyList * localEnemyList,int enemyNum, float posX, float posY, bool ableToJump){
  float originX = posX - MAP_CHIP_SIZE * 2;
  float originY = posY - MAP_CHIP_SIZE * 2;
  int index = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if((i == 2) && (j == 2)) continue;
      int mapVal = stage->getMapChip(originX + i*MAP_CHIP_SIZE, originY + j*MAP_CHIP_SIZE);
      if(mapVal == 1) _field[index] = true;
      else _field[index] = false;
//      if(mapVal == 3) _enemy[index] = true;
//      else _enemy[index] = false;
	  _enemy[index] = false;
      if(mapVal == 4) _item[index] = true;
      else _item[index] = false;      
      index++;
    }
  }
  index = 0;
    for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if((i == 2) && (j == 2)) continue;
	  /////////////EnemySensor////////////////////
	  for(int k = 0; k < enemyNum; k++){
	      float x =originX + i*MAP_CHIP_SIZE;
		  float y = originY + j*MAP_CHIP_SIZE;
		  float enemyX = enemyList->getEnemyX(k);
		  float enemyY = enemyList->getEnemyY(k);
		  if( fabs(x-enemyX) < MAP_CHIP_SIZE/2 && fabs(y-enemyY) < MAP_CHIP_SIZE/2 && enemyList->getEnemyAlive(k) && !localEnemyList->_EnemyIsDead(k) )
			  _enemy[index] = true;
//		  else _enemy[index] = false;
	  }
      index++;
    }
  }
}







