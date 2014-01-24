//
//  File.c
//  GPGame
//
//  Created by 村上 晋太郎 on 2014/01/24.
//
//

#include <stdio.h>
#include "my_rand.h"

int myRand(void){
  int val = rand();
  printf("myRand: %d\n", val);
  return;
}