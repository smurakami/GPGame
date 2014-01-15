#include "EnemyList.h"

EnemyList::EnemyList(Stage * stage){
	_stage = stage;
	_width = stage->getWidth();
	_height = stage->getHeight();
	//Count EnemyNumber
	_enemyNum = 0;
	for(int chip_y=0; chip_y< _height; chip_y++){
		for(int chip_x=0; chip_x< _width; chip_x++){
			if(stage->chip[chip_y*_width + chip_x] == 3)
				_enemyNum++;
		}
	}
	//Make EnemyArray
	_enemyArray = new Enemy[_enemyNum];
	int i = 0;
	for(int chip_y=0; chip_y< _height; chip_y++){
		for(int chip_x=0; chip_x< _width; chip_x++){
			if(stage->chip[chip_y*_width + chip_x] == 3){
				_enemyArray[i].setDefaultPosition(_stage, chip_x*32, chip_y*32);
				i++;
			}
		}
	}
}

EnemyList::~EnemyList(){
	delete [] _enemyArray;////////////////changed!!!!!
}

void EnemyList::update(){
	//update Enemy
	for(int i = 0; i < _enemyNum; i++)
		_enemyArray[i].update();
}

void EnemyList::draw(float gamePosX, float gamePosY){///////////////changed!!!!
	for(int i = 0; i < _enemyNum; i++)
		_enemyArray[i].draw(gamePosX, gamePosY);/////////////changed!!!!!
}
void EnemyList::setGameClass(Game * game){
	_game = game;
}

int EnemyList::getEnemyNum(){
	return _enemyNum;
}
Enemy * EnemyList::getEnemyArray(){
	return _enemyArray;
}
//-----------------------------------CHANGED-----------------------------------------------//
bool EnemyList::getEnemyAlive(int i){
	return !_enemyArray[i].isDead();
}
void EnemyList::loadMap(){
  _stage->loadMap();
}
void EnemyList::draw(Game * game){
	for(int i = 0; i< _enemyNum; i++){
		if(!game->enemyIsDead(i))
			_enemyArray[i].draw(game->getPosX(), game->getPosY());
	}
}
float EnemyList::getEnemyX(int i){
	return _enemyArray[i].getPosX();
}
float EnemyList::getEnemyY(int i){
	return _enemyArray[i].getPosY();
}
//-----------------------------------CHANGED-----------------------------------------------//
