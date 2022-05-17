#ifndef __LEVEL3_H
#define __LEVEL3_H
#include <iostream>
#include"ray.h"

class level3 :public raystriker
{
public :
int side;
level3();

void printboard();
int resultant();
void on(State *st);
private :
int resultarr();
};
#endif