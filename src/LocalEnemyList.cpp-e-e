#include "LocalEnemyList.h"
#include <cmath>
#define HANTEI 32
#define BOOST 20
#define PLUSY 3

LocalEnemyList::LocalEnemyList(EnemyList * enemyList, MainChara * mainChara){
	_enemyList = enemyList;
	_mainChara = mainChara;
	_enemyNum = _enemyList->getEnemyNum();
	_enemyArray = _enemyList->getEnemyArray();
	_alive = new bool[_enemyNum];
	for(int i =0; i < _enemyNum; i++){
		_alive[i] = true;
	}
}
LocalEnemyList::~LocalEnemyList(){
//	delete [] _alive;
}
void LocalEnemyList::update(){
	CD();
}

//Collision Detecter
void LocalEnemyList::CD(){
#define TIMER 60/////////////////////////////////???????????????????/////////////////
	for(int i=0; i < _enemyNum; i++){
		if( _alive[i] && _enemyList->getEnemyAlive(i)){
			float _posX = _enemyArray[i].getPosX();
			float _posY = _enemyArray[i].getPosY();
			float jiki_x = _mainChara->getPosX();
			float jiki_y = _mainChara->getPosY();
			float speed_x = _mainChara->getSpeedX();
			float speed_y = _mainChara->getSpeedY();
			float dx = fabs(jiki_x - _posX);
			float dy = fabs(jiki_y - _posY);
			if( dx < HANTEI && dy < HANTEI ){
				if( speed_y > 0 && _posY > jiki_y ){
					_alive[i] = false;
					_mainChara->attackTimerOn(TIMER);
					_mainChara->plusY(PLUSY);
				}
				else{
					_mainChara->Die();
				}
			}
		}
	}
}
//-----------------------------------CHANGED-----------------------------------------------//
void LocalEnemyList::setEnemyList(EnemyList * enemyList){
	_enemyList = enemyList;
	_enemyNum = _enemyList->getEnemyNum();
	_enemyArray = _enemyList->getEnemyArray();

	for(int i=0; i< _enemyNum; i++){
		_alive[i]=true;
	}
}
bool LocalEnemyList::_EnemyIsDead(int i){
	return !_alive[i];
}
//-----------------------------------CHANGED-----------------------------------------------//
