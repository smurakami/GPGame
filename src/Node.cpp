//
//  Node.cpp
//  GPGame
//
//  Created by S.Murakami and T.I. on 2013/05/05.
//
//

#include "Node.h"
#include <string.h>
#include "MyRandom.h"

Node::Node(){
  _nodeType = TERM;
  _termKind = (TermKind)(myRand() % TERM_KIND_NUM);
  _left = NULL;
  _right = NULL;
  _val = myRand() % SENSOR_NUM;
}

Node::Node(Node * parent){
  *this = *parent;
  if(_nodeType == OP){
    _left = new Node(_left);
    _right = new Node(_right);
  }
}

Node::~Node(){
  if(_nodeType == OP){
    delete _left;
    delete _right;
  }
}

void Node::addTerm(){
  if(_nodeType == OP){
    if(myRand()%2) _left->addTerm();
    else _right->addTerm();
    return;
  }
  _nodeType = OP;
  _opKind = (OpKind)(myRand() % OP_KIND_NUM);
  _left = new Node();
  _right = new Node();
}

Node * Node::leftChild(){
  return _left;
}
  
Node * Node::rightChild(){
  return _right;
}

void Node::setChild(Node *left, Node *right){
  _left = left;
  _right = right;
}

bool Node::run(Sensor * sensor){
  if(_nodeType == TERM){
    switch(_termKind){
      case FIELD_SENSOR:
        return sensor->field(_val);
      case ENEMY_SENSOR:
        return sensor->enemy(_val);
      case ITEM_SENSOR:
        return sensor->item(_val);
      default:
        printf("Node::run undefined sensor\n");
        exit(1);
    }
  }
  bool leftVal = _left->run(sensor);
  bool rightVal = _right->run(sensor);
  bool returnVal;
  switch (_opKind) {
    case AND:
      return (leftVal && rightVal);
    case OR:
      return (leftVal || rightVal);
    case NAND:
      return !(leftVal && rightVal);
    case NOR:
      return !(leftVal || rightVal);
    default:
      break;
  }
  printf("Node::run : undefined operater\n");
  exit(1);  
}

void Node::print(int depth){
  if(_nodeType == TERM){
    char termKindName[10];
    switch(_termKind){
      case FIELD_SENSOR:
        strcpy(termKindName, "FS");
        break;
      case ENEMY_SENSOR:
        strcpy(termKindName, "ES");
        break;
      case ITEM_SENSOR:
        strcpy(termKindName, "IS");
        break;
      default:
        printf("Node::run undefined sensor\n");
        exit(1);
    }
    printf(" %s%d", termKindName, _val);
    return;
  }
  char opKindName[10];
  switch (_opKind) {
    case AND:
      strcpy(opKindName, "AND");
      break;
    case OR:
      strcpy(opKindName, "OR");
      break;
    case NAND:
      strcpy(opKindName, "NAND");
      break;
    case NOR:
      strcpy(opKindName, "NOR");
      break;
    default:
      printf("Node::run : undefined operater\n");
      exit(1);
  }
  printf("\n");
  for(int i = 0; i < depth; i++){
    printf("  ");
  }
  printf("(%s", opKindName);
  _left->print(depth+1);
  _right->print(depth+1);
  printf(")");
  return;  
}

Node * Node::clone(){
  Node * n = new Node(this);
  return n;
}

Node ** Node::selectNodeByDepth(Node * root){
  if(_nodeType == TERM){
    return root->selectNodeByDepth(root);
  }
  if(myRand()%2){
    return (myRand()%2 ? &_left : &_right);
  }else{
    return (myRand()%2 ? _left->selectNodeByDepth(root) :
            _right->selectNodeByDepth(root));
  }
}

//void Node::setProperty(NodeType nodeType,
//                       TermKind termKind,
//                       OpKind opKind,
//                       Node * left,
//                       Node * right,
//                       int val)
//{
//  
//  
//  
//}
//
