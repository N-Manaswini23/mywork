  
#ifndef _LEVEL5_H
#define _LEVEL5_H
#include <iostream>
#include "ray.h"

class level5 :public raystriker
{
  public:
  int side;
  level5();

  void printboard();
  int resultant();
  void on(State *st);

  private:
  int resultarr();
};
#endif