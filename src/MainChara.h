
#include "ofMain.h"
#include "Stage.h"
#include "Keys.h"
#pragma once

class MainChara{
private:
    Stage * _stage;
    Keys * _keys;
    
    ofColor _color;
    ofImage _images[4];
    
    float _posX;
    float _posY;
    float _speedX;
    float _speedY;
    char _dirX;
    
    int _age;
    
    bool _dead;
    bool _cleared;
    bool _isAbleToJump;
    bool _isJumping;
    int _attackTimer;
    bool _hasAttacked;
    bool _hasAttackJumped;
    
public:
    MainChara(Stage * stage, Keys * keys);
    void setSinglePlayerMode();
    void update();
    void draw(float gamePosX, float gamePosY);
    float getPosX();
    float getPosY();
    //////////////EnemyList////////////
    float getSpeedX();
    float getSpeedY();
    bool isDead();
    void Die();
    void boostY(float plusY);
    void plusY(float plusY);
    void attackTimerOn(int on);
    bool isAbleToJump();
    //////////////////EnemyList////////////
    
};
