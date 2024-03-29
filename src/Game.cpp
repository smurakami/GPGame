//
//  Game.cpp
//  GPGame
//
//  Created by S.Murakami and T.I. on 2013/05/02.
//
//

#include "Game.h"

Game::Game(EnemyList *enemyList)
{
    _stage = new Stage(STAGEDATAPATH);
    _keys = new Keys();
    _mainChara = new MainChara(_stage, _keys);
    _enemyList = enemyList;//////////////////////////EnemyList/////////////////
    _localEnemyList = new LocalEnemyList(_enemyList, _mainChara);//////////////////////////EnemyList/////////////////
                                                                 //*--------------  GP Tree --------------*//
#define DEFAULT_TREE_SIZE 1000
    _controlledByTree = true;
    _leftKeyTree  = new Tree(DEFAULT_TREE_SIZE);
    _rightKeyTree = new Tree(DEFAULT_TREE_SIZE);
    _spaceKeyTree = new Tree(DEFAULT_TREE_SIZE);
    //   _leftKeyTree->print();
    _sensor = new Sensor();
    //*------------- End GP Tree ------------*//
}

//*--------------  GP Tree --------------*//
Game::Game(Tree * left, Tree * right, Tree * space, EnemyList *enemyList)
{
    _stage = new Stage(STAGEDATAPATH);
    _keys = new Keys();
    _mainChara = new MainChara(_stage, _keys);
    _enemyList = enemyList;//////////////////////////EnemyList//////////////////
    _localEnemyList = new LocalEnemyList(_enemyList, _mainChara);////////////////////////////////this
#define DEFAULT_TREE_SIZE 1000
    _controlledByTree = true;
    _leftKeyTree  = left;
    _rightKeyTree = right;
    _spaceKeyTree = space;
    //   _leftKeyTree->print();
    _sensor = new Sensor();
}
//*------------- End GP Tree ------------*//

Game::~Game()
{
    delete _stage;
    delete _keys;
    delete _mainChara;
    delete _localEnemyList;
    //*--------------  GP Tree --------------*//
    delete _leftKeyTree;
    delete _rightKeyTree;
    delete _spaceKeyTree;
    //*------------- End GP Tree ------------*//
    
}

void Game::update()
{
    //*--------------  GP Tree --------------*//
    if(_controlledByTree){
        _sensor->update(_stage, _enemyList, _localEnemyList, _enemyList->getEnemyNum(), _mainChara->getPosX(), _mainChara->getPosY(), _mainChara->isAbleToJump());
        _runTrees();
    }
    //*------------- End GP Tree ------------*//s
    _mainChara->update();
    _posX = _mainChara->getPosX();
    _posY = ofGetHeight()/2;
    _localEnemyList->update();///////////////////////////EnemyList////////////////////////
}

//*--------------  GP Tree --------------*//
void Game::_runTrees(){
    _keys->setLeft(_leftKeyTree->run(_sensor));
    _keys->setRight(_rightKeyTree->run(_sensor));
    _keys->setSpace(_spaceKeyTree->run(_sensor));
}
//*------------- End GP Tree ------------*//

void Game::draw()
{
    _mainChara->draw(_posX, _posY);
    _stage->draw(_posX, _posY);
}

//*--------------  GP Tree --------------*//
void Game::draw(float posX, float posY)
{
    _mainChara->draw(posX, posY);
}

float Game::getPosX(){
    return _posX;
}

float Game::getPosY(){
    return _posY;
}

void Game::enableHumanControl(){
    _controlledByTree = false;
    _mainChara->setSinglePlayerMode();
}

float Game::getProgress(){
    return _mainChara->getPosX();
}

Tree * Game::leftKeyTree(){
    return _leftKeyTree;
}

Tree * Game::rightKeyTree(){
    return _rightKeyTree;
}

Tree * Game::spaceKeyTree(){
    return _spaceKeyTree;
}

//*------------- End GP Tree ------------*//

bool Game::isOver()
{
    return _mainChara->isDead();
}

//human interface

void Game::setKeyOn(int key){
    _keys->setOn(key);
}

void Game::setKeyOff(int key){
    _keys->setOff(key);
}

void Game::loadMap(){
    _stage->loadMap();
}

void Game::setEnemyList(EnemyList * enemyList){
	_enemyList = enemyList;
	_localEnemyList->setEnemyList(_enemyList);
}

bool Game::enemyIsDead(int i){
	return _localEnemyList->_EnemyIsDead(i);
}
