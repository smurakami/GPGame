//
//  Keys.cpp
//  GPGame
//
//  Created by S.Murakami and T.I. on 2013/05/01.
//
//

#include "Keys.h"

Keys::Keys()
{
  _right = false;
  _left = false;
  _space = false;
  _rebirth = false;
  _g = false;
  _s = false;
  _up = false;
  _down = false;
}

void Keys::setOn(int key)
{
  if( key == 356/*left*/ ) _left = true;
  if( key == 358/*right*/ ) _right = true;
  if( key == 32/*space*/ ) _space = true;
  if( key == 357) _space = true;
  //REBIRTH
//  if( key == 'r' && dead == 1){
  if( key == 'r') _rebirth = true;
  //*--------------  GP Tree --------------*//
  if( key == 'g') _g = true;
  if( key == 's') _s = true;
  //*------------- End GP Tree ------------*//
  if( key == 357) _up = true;
  if( key == 359) _down = true;

//  printf("key is '%c'\n, == %d",(char)key, key);

}

void Keys::setOff(int key)
{
  if( key == 356/*left*/ ) _left = false;
  if( key == 358/*right*/ ) _right = false;
  if( key == 32/*space*/ ) _space = false;
  if( key == 357) _space = false;
  if( key == 'r') _rebirth = false;
  //*--------------  GP Tree --------------*//
  if( key == 'g') _g = false;
  if( key == 's') _s = false;
  //*------------- End GP Tree ------------*//
  if( key == 357) _up = false;
  if( key == 359) _down = false;
}

//*--------------  GP Tree --------------*//

void Keys::setRight(bool x){
  _right = x;
}

void Keys::setLeft(bool x){
  _left = x;
}

void Keys::setSpace(bool x){
  _space = x;
}

bool Keys::g(){
  return _g;
}

bool Keys::s(){
	return _s;
}

bool Keys::up(){
  return _up;
}

bool Keys::down(){
  return _down;
}

//*------------- End GP Tree ------------*//

bool Keys::right()
{
  return _right;
}
bool Keys::left()
{
  return _left;
}
bool Keys::space()
{
  return _space;
}
bool Keys::rebirth()
{
  return _rebirth;
}
