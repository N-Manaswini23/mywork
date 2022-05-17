#ifndef __RAY_H
#define __RAY_H
#include <iostream>
#include <array>

void printinstructions();



class State
{
  public:
  class raystriker *ray;
  
  void setstate(raystriker *r);
  State();
  std::string* onorient(int _i,int side,std::string *arr,int choice,std::string s);
  int onresult();
  void onboard(); 
  void on();
  
};

class raystriker
{
  protected :
  std::string* orientation(int _i,int side,std::string *arr,int choice,std::string s);
 
  public :
  State *st;
  int side;
  std::string* arr=static_cast<std::string*>(malloc(20000));
  int choice;
  std::string s;
  virtual void printboard();
  virtual int resultarr();
  std::string* orient(int _i,int side,std::string *arr,int choice,std::string s);
  virtual void on(State *st);
  virtual int resultant();
};


#endif