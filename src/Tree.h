//
//  Tree.h
//  GPGame
//
//  Created by S.Murakami and T.I. on 2013/05/05.
//
//

//#ifndef __GPGame__Tree__
//#define __GPGame__Tree__
#pragma once

class Tree;


#include <iostream>
#include "Node.h"
#include "Sensor.h"

class Tree{
private:
  Node * _root;
  
public:
  Tree(int size);
  Tree(Tree * parent);
  ~Tree();
  
  Node * rootNode();
  bool run(Sensor * sensor);
  void print();
  Tree * clone();
  Tree * crossOver(Tree * parentB);
  /** mutation **/
  Tree * mutate();
};

//#endif /* defined(__GPGame__Tree__) */
