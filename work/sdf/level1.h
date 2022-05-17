#ifndef __LEVEL1_H
#define __LEVEL1_H
#include <iostream>
#include"ray.h"

class level1 :public raystriker
{
public :
int side;
level1();
void printboard();
int resultant();
void on(State *st);
private :
int resultarr();
};

#endif