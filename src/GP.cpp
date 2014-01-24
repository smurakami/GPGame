//
//  GP.cpp
//  GPGame
//
//  Created by S.Murakami and T.I. on 2013/05/08.
//
//

#include "GP.h"
#include "my_rand.h"

#define TIME_LIMIT 30
#define PROBAB_CROSSOVER 70
#define PROBAB_MUTATION 3
#define PROBAB_COPY 27
#define PROBAB_MAX (PROBAB_CROSSOVER + PROBAB_MUTATION + PROBAB_COPY)
#define ELETE_NUM 10



GP::GP(EnemyList * enemyList){
  _enemyList = enemyList;////////////EnemyList////////////
  _keys = new Keys();
  _gpCounter = 0;
  for(int i = 0; i < GEN_SIZE; i++){
    _games[i] = new Game(_enemyList);/////////////EnemyList///////////////
  }
}

void GP::update(){
  if(_gpCounter < TIME_LIMIT * 30){
    for(int i = 0; i < GEN_SIZE; i++){
      if(i > _gpCounter * 4) break;
      _games[i]->update();
    }
  }
  _gpCounter++;
  
  if(_keys->g()){
    stepGeneration();
  }
}

void GP::draw(float posX, float posY){
  for(int i = 0; i < GEN_SIZE; i++){
    if(i > _gpCounter * 4) break;
    _games[i]->draw(posX, posY);
  }
}

void GP::setKeyOn(int key){
  _keys->setOn(key);
}

void GP::setKeyOff(int key){
  _keys->setOff(key);
}

void GP::stepGeneration(){
  for(int i = 0; i < GEN_SIZE; i++){
    _gameVal[i] = _games[i]->getProgress();
  }

  //--- elete
  int eleteIndex[ELETE_NUM];
  int eleteVal[ELETE_NUM];
  for(int i = 0; i < ELETE_NUM; i++){
    eleteVal[i] = 0;
    eleteIndex[i] = 0;
  }
  
  for(int i = 0; i < GEN_SIZE; i++){
    int val = _gameVal[i];
    int index = i;
    for(int j = 0; j < ELETE_NUM; j++){
      if(_gameVal[i] > eleteVal[j]){
        {
          int x = eleteIndex[j];
          eleteIndex[j] = index;
          index = x;
        }
        {
          int x = eleteVal[j];
          eleteVal[j] = val;
          val = x;
        }
      }
    }
  }
  //--- end elete
  
  for(int num = 0; num < GEN_SIZE; num++){
    //--- elete
    if(num < ELETE_NUM){
      _nextLeftKeyTree[num] = _games[eleteIndex[num]]->leftKeyTree()->clone();
      _nextRightKeyTree[num] = _games[eleteIndex[num]]->rightKeyTree()->clone();
      _nextSpaceKeyTree[num] = _games[eleteIndex[num]]->spaceKeyTree()->clone();
      continue;
    }
    //---end elete
    int dice = rand() % PROBAB_MAX;
    if(dice < PROBAB_CROSSOVER){
      int parentA = roulette();
      int parentB = roulette();
      _nextLeftKeyTree[num] = _games[parentA]->leftKeyTree()->crossOver(_games[parentB]->leftKeyTree());
      _nextRightKeyTree[num] = _games[parentA]->rightKeyTree()->crossOver(_games[parentB]->rightKeyTree());
      _nextSpaceKeyTree[num] = _games[parentA]->spaceKeyTree()->crossOver(_games[parentB]->spaceKeyTree());
    }else if(dice < PROBAB_CROSSOVER + PROBAB_COPY){
      int parent = roulette();
      _nextLeftKeyTree[num] = _games[parent]->leftKeyTree()->clone();
      _nextRightKeyTree[num] = _games[parent]->rightKeyTree()->clone();
      _nextSpaceKeyTree[num] = _games[parent]->spaceKeyTree()->clone();
      /** addition **/
    }else{
      int parent = roulette();
      _nextLeftKeyTree[num] = _games[parent]->leftKeyTree()->mutate();
      _nextRightKeyTree[num] = _games[parent]->rightKeyTree()->mutate();
      _nextSpaceKeyTree[num] = _games[parent]->spaceKeyTree()->mutate();
    }
  }
  for(int i = 0; i < GEN_SIZE; i++){
    delete _games[i];
    _games[i] = new Game(_nextLeftKeyTree [i],
                         _nextRightKeyTree[i],
                         _nextSpaceKeyTree[i],
						 _enemyList);
  }
  
  _gpCounter = 0;
}

int GP::roulette(){
  float max = 0;
  for(int i = 0; i < GEN_SIZE; i++){
    max += _gameVal[i]*_gameVal[i];
  }
  float sum = 0;
  float dice = (rand() / (float)RAND_MAX) * max;
  if((dice > max) || (dice < 0)){
    printf("roulette: out of range dice val\n");
    exit(1);
  }
  for(int i = 0; i < GEN_SIZE; i++){
    sum += _gameVal[i]*_gameVal[i];
    if(sum > dice) return i;
  }
  return GEN_SIZE - 1;
}

void GP::loadMap(){
  for(int i = 0; i < GEN_SIZE; i++){
    _games[i]->loadMap();
  }
}
//-----------------------------------CHANGED-----------------------------------------------//
void GP::setEnemyList(EnemyList * enemyList){
	_enemyList = enemyList;
	for(int i = 0; i < GEN_SIZE; i++){
		_games[i]->setEnemyList(_enemyList);
	}
}
//-----------------------------------CHANGED-----------------------------------------------//




