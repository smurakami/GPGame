//
//  Tree.cpp
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/05.
//
//

#include "Tree.h"

Tree::Tree(int size){
  _root = new Node();
  for(int i = 0; i < size / 2; i++){
    _root->addTerm();
  }
}

Tree::Tree(Tree* parent){
  *this = *parent;
  if(_root){
    _root = new Node(parent->rootNode());
  }
}

Tree::~Tree(){
  delete _root;
}

Node * Tree::rootNode(){
  return _root;
}

bool Tree::run(Sensor *sensor){
  return _root->run(sensor);
}

void Tree::print(){
  printf("====== P R I N T   T R E E ======");
  _root->print(0);
  printf("\n========= E N D  T R E E ========\n");
}

Tree * Tree::clone(){
  Tree * t = new Tree(this);
  return t;
}

Tree * Tree::crossOver(Tree * parentB){
  Tree * t = new Tree(this);
  Node ** n0 = t->rootNode()->selectNodeByDepth(t->rootNode());
  Node ** n1 = parentB->rootNode()->selectNodeByDepth(parentB->rootNode());
  delete (*n0);
  *n0 = (*n1)->clone();
  return t;
}

/** mutation **/
Tree * Tree::mutate(){
  Tree * t = new Tree(this);
  Node ** n = t->rootNode()->selectNodeByDepth(t->rootNode());
  delete (*n);
  (*n) = new Node();
  for(int i = 0; i < 16; i++){
    (*n)->addTerm();
  }
  
  return t;
}


