#ifndef __LEVEL6_H
#define __LEVEL6_H
#include <iostream>
#include"ray.h"

class level6 :public raystriker
{
public :
int side;
level6();

void printboard();
int resultant();
void on(State *st);
private :
int resultarr();
};
#endif