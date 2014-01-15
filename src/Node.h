//
//  Node.h
//  GPGame
//
//  Created by 村上 晋太郎 on 2013/05/05.
//
//

//#ifndef __GPGame__Node__
//#define __GPGame__Node__
#pragma once

class Node;


#include <iostream>
#include "Sensor.h"

typedef enum{
  TERM,
  OP  
} NodeType;

typedef enum{
  AND,
  OR,
  NAND,
  NOR,
  OP_KIND_NUM
} OpKind;

typedef enum{
  FIELD_SENSOR,
  ENEMY_SENSOR,
  TERM_KIND_NUM,
  ITEM_SENSOR
} TermKind;

class Node{
private:
  NodeType _nodeType;
  TermKind _termKind;
  OpKind _opKind;
  Node * _left;
  Node * _right;
  int _val;
public:
  Node();
  Node(Node * parent);
  ~Node();
  void addTerm();
  Node * leftChild();
  Node * rightChild();
  void setChild(Node * left, Node * right);

  bool run(Sensor * sensor);
  void print(int depth);
  
  Node * clone();
  Node ** selectNodeByDepth(Node * root);
//  void setProperty(
//                   NodeType nodeType,
//                   TermKind termKind,
//                   OpKind opKind,
//                   Node * left,a
//                   Node * right,
//                   int val
//  );
  
};

//#endif /* defined(__GPGame__Node__) */
