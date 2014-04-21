
#include "MainChara.h"
#include "my_rand.h"
#define MAX_SPEED 1
#define ACCEL 7
#define GRAVITY 1
#define DEFAULT_X 32*8
#define DEFAULT_Y 32*6

//*--------------  GP Tree --------------*//
//*------------- End GP Tree ------------*//


MainChara::MainChara(Stage * stage, Keys * keys)
{
    
    // 見た目の設定
    // 虹色ランダムの合成
    int color_elem[3];
    color_elem[0] = 255;
    color_elem[1] = rand() % 256;
    color_elem[2] = 0;
    int color_r_index = rand() % 3;
    int r_bin = rand() % 2;
    int color_g_index = (color_r_index + 1 +  r_bin) % 3;
    int color_b_index = (color_r_index + 1 + !r_bin) % 3;
    _color.set(color_elem[color_r_index], color_elem[color_g_index], color_elem[color_b_index]);
    for(int i = 0; i < 4; i++){
        char file_name[100];
        sprintf(file_name, "chara%d.png", i+1);
        _images[i].loadImage(file_name);
    }
    
    //*------------- End GP Tree ------------*//
    
    _stage = stage;
    _keys = keys;
    //---------------------------------------start-------------------------------------//
    _posX = DEFAULT_X;
    //  _posY = ( _stage->getHeight() - 5 )*32;
    _posY = (_stage->getHeight()/2+2)*32;////////////////////////????????????????????/////////////////////
    
    _dirX = 1;
                                         //----------------------------------------end---------------------------------------//
    _speedX = 0.0;
    _speedY = 0.0;
    
    _age = 0;
    
    /////////////////EnemyList//////////////////
    _dead = false;
    _cleared = false;
    _isAbleToJump = false;////////////////????//////////////
    _isJumping = true;
    _attackTimer = 0;
    _hasAttacked = false;
    _hasAttackJumped = false;
    /////////////////EnemyList/////end///////////////
    return ;
}

void MainChara::update()
{
	if( _keys->left() ) _speedX  += -ACCEL;
	if( _keys->right() ) _speedX +=  ACCEL;
    
    if(_speedX > 1) _dirX = 1;
    if(_speedX < -1) _dirX = -1;
    
	if( !_attackTimer ){
		if( _keys->space() && _isAbleToJump){
			_speedY -= 20;
			_isJumping = true;
			_isAbleToJump = false;
		}
		if(!_isJumping && !_keys->space()){
			_isAbleToJump = true;
		}
		if(_speedY < 0 && !_keys->space()){
			_speedY = 0;
		}
	}
	else{
		if( _hasAttacked && _keys->space() ){
			_speedY = -20;
			_hasAttackJumped = true;
		}
		else if( _hasAttacked && !_keys->space() ){
			_speedY = -10;
		}
		_hasAttacked = false;
		if( _hasAttackJumped && !_keys->space() ){
			_attackTimer = 0;
			_hasAttackJumped = false;
		}
		else{
			_attackTimer--;
		}
	}
  
	//
	_speedX *= 0.7;
	//
	_speedY += GRAVITY;
    
	//
	if( _stage->IsDead(_posX+_speedX, _posY+_speedY) ){//DEAD
		_dead = true;
	}
	if( _dead ){
		_speedX=0;
		_speedY=0;
	}
	//
	if( _stage->IsAbleToGo(_posX, _posY+_speedY) ){
		_posY=_posY+_speedY;
        _isAbleToJump = false;
        _isJumping = true;
	}
	else{
		if( _speedY > 0){
			while( _stage->IsAbleToGo(_posX, _posY+1)){
				_posY+=1;
			}
            _isJumping = false;
		}
		else{//_speedY <= 0
			while( _stage->IsAbleToGo(_posX, _posY-1)){
                _posY-=1;
            }
		}
		_speedY = 0;
		/////////////EnemyList/////////////
		_attackTimer = 0;
		_hasAttackJumped = false;
		///////////////EnemyList/////////////
	}
	if( _stage->IsAbleToGo(_posX+_speedX, _posY)){
		_posX=_posX+_speedX;
	}
	else{
		if( _speedX > 0)
			while( _stage->IsAbleToGo(_posX+1, _posY)){
				_posX+=1;
			}
		else{
			while( _stage->IsAbleToGo(_posX-1, _posY)){
				_posX-=1;
			}
		}
		_speedX = 0;
	}
	if( _stage->IsAbleToGo(_posX+_speedX, _posY+_speedY)){
        
	}
	else{
        //		_speedX = 0;
        //		_speedY = 0;
	}
    
    if(_dead && _keys->rebirth() /*|| _keys->s()*/ ){
        _posX = DEFAULT_X;
        _posY = (_stage->getHeight()/2+2)*32;
        _dead = false;
    }

    _age++;
}

void MainChara::setSinglePlayerMode(){
    _color.set(255, 255, 255);
    for(int i = 0; i < 4; i++){
        char file_name[100];
        sprintf(file_name, "chara%d.png", i+1);
        _images[i].loadImage(file_name);
    }
}

void MainChara::draw(float gamePosX, float gamePosY)
{
	ofSetColor(_color);
    int flame = 0;
    if(_isJumping){
        flame = 3;
    }else if(abs(_speedX) > 1){
      int num = _age / 4;
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
    
}

//-------- Accesser ---------

float MainChara::getPosX()
{
    return _posX;
}

float MainChara::getPosY()
{
    return _posY;
}
void MainChara::Die(){
	_dead = true;
}
bool MainChara::isDead()
{
    return _dead;
}
float MainChara::getSpeedX()
{
	return _speedX;
}
float MainChara::getSpeedY()
{
	return _speedY;
}
void MainChara::boostY(float plusY){
	_speedY = -plusY;
}
void MainChara::plusY(float plusY){
	_posY -= plusY;
}
void MainChara::attackTimerOn(int on){
	_attackTimer = on;
	_hasAttacked = true;
}

bool MainChara::isAbleToJump(){
    return _isAbleToJump;
}
