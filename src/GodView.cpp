//
//  GodView.cpp
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/15.
//
//

#include "GodView.h"

GodView::GodView(){
  _stage = new Stage(NULL);
  _keys = new Keys();
  _posX = 10*32;
  _posY = ofGetHeight()/2;
}

GodView::~GodView(){
  delete _stage;
  delete _keys;
}

void GodView::update(){
  if(_keys->left()){
    _posX -= 30;
  }
  if(_keys->right()){
    _posX += 30;
  }
  if(_keys->up()){
    _posY -= 30;
  }
  if(_keys->down()){
    _posY += 30;
  }
}

void GodView::draw(){
  _stage->draw(_posX, _posY);
}


float GodView::getPosX(){
  return _posX;
}

float GodView::getPosY(){
  return _posY;
}

void GodView::setKeyOn(int key){
  _keys->setOn(key);
}

void GodView::setKeyOff(int key){
  _keys->setOff(key);
}

void GodView::selectStage(int stageNum){
  _stage->selectStage(stageNum);
}

void GodView::selectNextStage(){
  _stage->selectNextStage();
}

void GodView::selectPrevStage(){
  _stage->selectPrevStage();
}

void GodView::loadMap(){
  _stage->loadMap();
}
