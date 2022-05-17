#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level1.h"
#include"level2.h"

level1::level1()
  {
  for(int i=0;i<17;i++)
  { 
  
    if (i==2||i==9||i==4||i==11||i==6||i==14||i==5||i==16||i==15)
    {
      arr[4]="   S  ";
      arr[6]="  M2  ";
      arr[2]="  M1  ";
      arr[9]="  M3  ";
      arr[14]="  M4  ";
      arr[15]="  M5  ";
      arr[11]="   E  ";
      arr[5]="......";
      arr[16]="hr";
    }
    else
    {
      arr[i]="      ";
    }
  }
    side=4;
    choice=0;
    s="  M1  ";
  }



void level1::printboard()
{
  {printw("\n\n\n");
  start_color();
  use_default_colors();
	init_pair(2,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(2));
  printw("    ______ ______ ______ ______    \n");
  refresh();
  for(int i=0;i<4;i++)
  {printw("   |");
  wprintw(stdscr,(arr+0+4*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+4*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+4*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+4*i)->data());
  refresh();
  printw("|   \n");
  refresh();
  printw("   |______|______|______|______|   \n");
  refresh();
  }
  
  attroff(COLOR_PAIR(2));
}
}

int level1::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
   for(i=0;i <17;i++)
  { 
    if (i==4||i==6||i==14||i==5||i==16||i==15||i==11||i==10)
    {
      result[4]="   S  ";
      result[6]="   \\  ";
      result[14]="   \\  ";
      result[15]="   /  ";
      result[11]="   E  ";
      result[5]="......";
      result[16]="vu";
      result[10]="   :  ";
      
    }
    else
    {
      result[i]="      ";
    }
  }
  for(i=0;i <17;i++)
  {
    if (i==4||i==5||i==6||i==10||i==11||i==14||i==15||i==16)
    {
    if(result[i]==arr[i])
    {
      y=0;
    }
    else if (result[i]!=arr[i])
    {
      y=1;
      break;
    }
    }
  }
  return y;
  }
}

int level1::resultant()
{return resultarr();}

void level1::on(State *st)
{
  
  printw("\n\n     Congrats, Level 1 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level2());
  st->ray->side=6;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}