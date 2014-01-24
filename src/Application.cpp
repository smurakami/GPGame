//
//  Application.cpp
//  GPGameEnemy
//
//  Created by S.Murakami and T.I. on 2013/05/14.
//
//

#include "Application.h"
#include <iostream>

ofTrueTypeFont myFont;

Application::Application(){
  _appMode = TITLE_MODE;
  _stage = new Stage(NULL);
  _enemyList = new EnemyList(_stage);
  _game = new Game(_enemyList);
  _game->enableHumanControl();
  _gp = new GP(_enemyList);
  _godView = new GodView();
  _enemyList->setGameClass(_game);
  
	myFont.loadFont("arial.ttf", ofGetWidth()/10);
  _titleScreen.loadImage("titleScreen.png");
  _windowRect = ofGetWindowRect();
}

Application::~Application(){
  delete _gp;
  delete _game;
  delete _godView;
  delete _enemyList;
  delete _stage;
}


void Application::update(){
  switch (_appMode) {
    case TITLE_MODE:
      
      break;
    case GP_MODE:
      _godView->update();
      _gp->update();
      _enemyList->update();
      break;
    case SINGLE_MODE:
      _game->update();
      _enemyList->update();
      break;
      
    case STAGE_SELECT_MODE:
      _godView->update();
      _enemyList->update();
      break;
      
    default:
      break;
  }
}

void Application::draw(){
	ofBackground(0);
  //   	ofBackground(0, 255, 255);
  switch (_appMode) {
    case TITLE_MODE:
      ofSetColor(255, 255, 255);
      _titleScreen.draw(_windowRect);
      break;
    case GP_MODE:
      _godView->draw();
      _gp->draw(_godView->getPosX(), _godView->getPosY());
      _enemyList->draw(_godView->getPosX(), _godView->getPosY());////////////////////changed!!!!!
      break;
    case SINGLE_MODE:
      _game->draw();
      _enemyList->draw(_game);////////////////////////changed!!!!
      if(_game->isOver()) drawGameOver();
      
      break;
      
    case STAGE_SELECT_MODE:
      _godView->draw();
      _enemyList->draw(_godView->getPosX(), _godView->getPosY());/////////////////////////changed!!!!!
      break;
      
    default:
      break;
  }
}

void Application::keyPressed(int key){
	ofBackground(0);
  switch (_appMode) {
    case TITLE_MODE:
      if(key == 'g') {
        _appMode = GP_MODE;
//        int seed = time(NULL);
//        cout << "seed: " << seed << endl;
//        srand(seed);
//        int seed = 139;
//        cout << "seed: " << seed << endl;
//        srand(seed);
      }   if(key == 'p') _appMode = SINGLE_MODE;
      break;
    case GP_MODE:
      //-----------------------------------CHANGED-----------------------------------------------//
      if(key == 'g'){
        _appMode = GP_MODE;
        _stage->loadMap();
        delete _enemyList;
        _enemyList = new EnemyList(_stage);
        _enemyList->setGameClass(_game);
        _gp->setEnemyList(_enemyList);
        _game->setEnemyList(_enemyList);
      }
      
      //-----------------------------------CHANGED-----------------------------------------------//
      _godView->setKeyOn(key);
      _gp->setKeyOn(key);
      break;
    case SINGLE_MODE:
      //-----------------------------------CHANGED-----------------------------------------------//
      if(key == 'r'){
        if(_game->isOver() ){
          delete _enemyList;
          _enemyList = new EnemyList(_stage);
          _enemyList->setGameClass(_game);
          _gp->setEnemyList(_enemyList);
          //			delete _game;
          //			_game = new Game(_enemyList);
          //			_game->enableHumanControl();
          _game->setEnemyList(_enemyList);
        }
      }
      
      //-----------------------------------CHANGED-----------------------------------------------//
      _game->setKeyOn(key);
      break;
    case STAGE_SELECT_MODE:
      _godView->setKeyOn(key);
      if(key == 'n'){
        _godView->selectNextStage();
        _stage->loadMap();
        delete _enemyList;
        _enemyList = new EnemyList(_stage);
        _enemyList->setGameClass(_game);
        _gp->setEnemyList(_enemyList);
        delete _game;
        _game = new Game(_enemyList);
        _game->enableHumanControl();
        _game->setEnemyList(_enemyList);
      }
      if(key == 'p'){
        _godView->selectPrevStage();
        _stage->loadMap();
        delete _enemyList;
        _enemyList = new EnemyList(_stage);
        _enemyList->setGameClass(_game);
        _gp->setEnemyList(_enemyList);
        delete _game;
        _game = new Game(_enemyList);
        _game->enableHumanControl();
        _game->setEnemyList(_enemyList);
      }
      if(key == 13){
        //ステージのロード
        _stage->loadMap();
        _enemyList = new EnemyList(_stage);///////////////////
        _enemyList->setGameClass(_game);///////////////////
        _gp->setEnemyList(_enemyList);///////////////////
        _game->setEnemyList(_enemyList);///////////////
        _gp->loadMap();
        _game->loadMap();
        _godView->loadMap();
        //		_enemyList->loadMap();///////////////
        //復帰
        _appMode = _prevAppMode;
      }
      break;
    default:
      break;
  }
  if(key == 's') {
    _prevAppMode = _appMode;
    _appMode = STAGE_SELECT_MODE;
  }
}

void Application::keyReleased(int key){
  switch (_appMode) {
    case TITLE_MODE:
      break;
    case GP_MODE:
      _godView->setKeyOff(key);
      _gp->setKeyOff(key);
      break;
    case SINGLE_MODE:
      _game->setKeyOff(key);
      break;
    case STAGE_SELECT_MODE:
      _godView->setKeyOff(key);
      break;
      
    default:
      break;
  }
}

//---------------------------

void Application::drawGameOver(){
  
  string game_over_message = "GAME OVER...";
  
  float w = myFont.stringWidth(game_over_message);
  float h = myFont.stringHeight(game_over_message);
  float x = ofGetWidth()/2-w/2;
  float y = ofGetHeight()/2+h/2;
  ofSetColor(0, 0, 255);
  myFont.drawString(game_over_message, x, y);
  
}


