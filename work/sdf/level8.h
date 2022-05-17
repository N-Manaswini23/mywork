#ifndef __LEVEL8_H
#define __LEVEL8_H
#include <iostream>
#include"ray.h"

class level8 :public raystriker
{
  public:
  int side;
  level8();

  void printboard();
  int resultant();
  void on(State *st);
  private:
  int resultarr();
};
#endif