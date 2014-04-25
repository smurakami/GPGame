
#include "Enemy.h"
#include <cmath>
#define GRAVITY 1
#define EnemySpeed 3
#define HANTEI 32
#define BOOST 20
#define PLUSY 3

Enemy::Enemy(){
  for(int i = 0; i < 4; i++){
    char file_name[100];
    sprintf(file_name, "chara%d.png", i+1);
    _images[i].loadImage(file_name);
  }
	_speedX = -EnemySpeed;
	_speedY = 0;
	_dead = false;
  _dirX = 1;
  _age = 0;
}

Enemy::Enemy(Stage * stage)
{
  _stage = stage;
/*  _defaultX = defaultX;
  _defaultY = defaultY;
  _posX = _defaultX;
  _posY = _defaultY;
*/
  for(int i = 0; i < 4; i++){
    char file_name[100];
    sprintf(file_name, "chara%d.png", i+1);
    _images[i].loadImage(file_name);
  }
  _speedX = -EnemySpeed;
  _speedY = 0;
  _dead = false;
  _outside = true;
  _dirX = 1;
  _age = 0;
  return ;
}

Enemy::~Enemy(){
}

void Enemy::setDefaultPosition(Stage * stage, float x, float y){
	_stage = stage;
	_defaultX = x;
	_defaultY = y;
	_posX = x;
	_posY = y;
}

void Enemy::update()
{
/*	//is it OutSide?
	if( _outside )
	_outside = _stage->IsOutSide(gamePosX, gamePosY, _posX, _posY);
	if( _outside ){
		return;
	}
*/	
/*	//Collision Detecter
	CD();
*/
	
	//Update
	_speedY += GRAVITY;
	//Is it dead?
	if( _stage->IsDead(_posX+_speedX, _posY+_speedY) ){
		_dead = true;
	}
	if( _dead ){
		_speedX=0;
		_speedY=0;
	}
	//Is it able to go down(up)?
	if( _stage->IsAbleToGo(_posX, _posY+_speedY) ){
		_posY=_posY+_speedY;
	}
	else{
		if( _speedY > 0){
			while( _stage->IsAbleToGo(_posX, _posY+1)){
				_posY+=1;
			}
		}
		else{
			while( _stage->IsAbleToGo(_posX, _posY-1)){
        _posY-=1;
      }
		}
		_speedY = 0;
	}
	//Is it able to go forward(back)?
	if( _stage->IsAbleToGo(_posX+_speedX, _posY)){
		_posX=_posX+_speedX;
	}
	else{
		_speedX *= -1;
	}
  if (_speedX > 0) _dirX =  1;
  if (_speedX < 0) _dirX = -1;
  _age++;
}

void Enemy::draw(float gamePosX, float gamePosY)
{
	//if this is not the head of the list, draw it!
	if( !_dead ){
    ofSetColor(255,255,255);
    int flame = 0;
    if(abs(_speedX) > 1){
      int num = _age / 3;
      if (num % 2 == 0){
        flame = 1 + num / 2 % 2;
      } else {
        flame = 0;
      }
    }
    if(_dirX == 1)
      _images[flame].draw(_posX - gamePosX -16+ofGetWidth()/2, _posY - gamePosY -16+ofGetHeight()/2, 32, 32);
    else
      _images[flame].draw(_posX - gamePosX -16+ofGetWidth()/2 + 32, _posY - gamePosY -16+ofGetHeight()/2, -32, 32);

//    ofRect(_posX - gamePosX-16+ofGetWidth()/2, _posY - gamePosY -16+ofGetHeight()/2, 32, 32);
	}
}

//-------- Accesser ---------

float Enemy::getPosX()
{
  return _posX;
}

float Enemy::getPosY()
{
  return _posY;
}

bool Enemy::isDead()
{
  return _dead;
}
