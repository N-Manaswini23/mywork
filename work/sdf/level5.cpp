#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level5.h" 
#include "level6.h"
level5::level5()
{
  for(int i=0;i<101;i++)
  {
    if(i==4||i==22||i==25||i==45||i==48||i==63||i==93||i==96||i==100)
    {
      arr[4]="  M1  ";
      arr[22]="   S  ";
      arr[23]="......";
      arr[24]="......";
      arr[25]="  M2  ";
      arr[45]="  M3  ";
      arr[48]="  M4  ";
      arr[68]="  M5  ";
      arr[63]="  M6  ";
      arr[93]="  M7  ";
      arr[96]="   E  ";
      arr[100]="hr";
    }
    else
    {
      arr[i]="      ";
    }
  }

  side=10;
  choice=0;
  s="  M1  ";
}

void level5::printboard()
{ printw("\n\n\n");
  start_color();
  use_default_colors();
  init_pair(5,COLOR_BLACK+16,COLOR_YELLOW+8);

  attron(COLOR_PAIR(5));
   printw(" ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n");
  refresh();
 
 for(int n=0;n<10;n++)
 { printw("|");
  wprintw(stdscr,(arr+0+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+7+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+8+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+9+10*n)->data());
  refresh();
  printw("|\n");
  refresh();
  printw("|______|______|______|______|______|______|______|______|______|______|\n");
  refresh();
 }
  
attroff(COLOR_PAIR(5));
}

int level5::resultarr()
{  
  
    std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
    int i=0;
    int y=1;
    for(i=0;i<101;i++)
    {
      if(i==22||i==23||i==24||i==25||i==35||i==45||i==46||i==47||i==48||i==58||i==68||i==67||i==66||i==65||i==64||i==63||i==73||i==83||i==93||i==94||i==95||i==96||i==100)
      {
      result[22]="   S  ";
      result[23]="......";
      result[24]="......";
      result[25]="   \\  ";
      result[35]="   :  ";
      result[45]="   \\  ";
      result[46]="......";
      result[47]="......";
      result[48]="   \\  ";
      result[58]="   :  ";
      result[68]="   /  ";
      result[67]="......";
      result[66]="......";
      result[65]="......";
      result[64]="......";
      result[63]="   /  ";
      result[73]="   :  ";
      result[83]="   :  ";
      result[93]="   \\  ";
      result[94]="......";
      result[95]="......";
      result[96]="   E  ";
      result[100]="hr";
      }
    
    else
    {
      result[i]="      ";
    }
    }
    for(i=0;i<101;i++)
    {
      if(i==22||i==23||i==24||i==25||i==35||i==45||i==46||i==47||i==48||i==58||i==68||i==67||i==66||i==65||i==64||i==63||i==73||i==83||i==93||i==94||i==95||i==96)
      { if(result[i]==arr[i])
      {y=0;}
      else if(result[i]!=arr[i])
      {y=1;
       break;}
      }
    }
return y;
}

int level5::resultant()
{
  return resultarr();
}

void level5::on(State *st)
{
  
  printw("\n \n      Congrats,level5 is complete. \n  Press any key to continue.\n");
  refresh();
  getch();
  refresh();       clear();
  refresh();
  st->setstate(new level6());
  st->ray->side=10;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}