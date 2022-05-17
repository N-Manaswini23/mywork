#ifndef __LEVEL7_H
#define __LEVEL7_H
#include <iostream>
#include"ray.h"

class level7 : public raystriker
{
public :
int side;
level7();

void printboard();
int resultant();
void on(State *st);
private :
int resultarr();
};
#endif