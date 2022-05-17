#ifndef __LEVEL4_H
#define __LEVEL4_H
#include <iostream>
#include"ray.h"

class level4 : public raystriker
{
public :
int side;
level4();

void printboard();
int resultant();
void on(State *st);
private :
int resultarr();
};
#endif