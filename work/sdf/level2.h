#ifndef __LEVEL2_H
#define __LEVEL2_H
#include <iostream>
#include"ray.h"

class level2 :public raystriker
{
public :
int side;
level2();

void printboard();
int resultant();
void on(State *st);
private :
int resultarr();
};
#endif