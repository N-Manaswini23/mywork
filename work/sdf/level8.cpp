#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level8.h"

level8::level8()
{
  for(int i=0;i<101;i++)
  {
    if(i==11||i==12||i==13||i==33||i==35||i==45||i==42||i==72||i==74||i==94||i==99||i==100)
    {
      arr[11]="   S  ";
      arr[12]="......";
      arr[13]="  M1  ";
      arr[33]="  M2  ";
      arr[35]="  M3  ";
      arr[45]="  M4  ";
      arr[42]="  M5  ";
      arr[72]="  M6  ";
      arr[74]="  M7  ";
      arr[94]="  M8  ";
      arr[99]="   E  ";
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

void level8::printboard()
{ printw("\n\n\n");
  start_color();
  use_default_colors();
  init_pair(5,COLOR_BLACK+16,COLOR_YELLOW+8);

  
  attron(COLOR_PAIR(5));
   printw(" ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n");
  refresh();

  for(int n=0;n<10;n++)
  {printw("|");
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

int level8::resultarr()
{
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
  for(i=0;i<101;i++)
  {
    if(i==11||i==12||i==13||i==23||i==33||i==34||i==35||i==45||i==44||i==43||i==42||i==52||i==62||i==72||i==73||i==74||i==84||i==94||i==95||i==96||i==97||i==98||i==99||i==100)
    {
      result[11]="   S  ";
      result[12]="......";
      result[13]="   \\  ";
      result[23]="   :  ";
      result[33]="   \\  ";
      result[34]="......";
      result[35]="   \\  ";
      result[45]="   /  ";
      result[44]="......";
      result[43]="......";
      result[42]="   /  ";
      result[52]="   :  ";
      result[62]="   :  ";
      result[72]="   \\  ";
      result[73]="......";
      result[74]="   \\  ";
      result[84]="   :  ";
      result[94]="   \\  ";
      result[95]="......";
      result[96]="......";
      result[97]="......";
      result[98]="......";
      result[99]="   E  ";
      result[100]="hr";
    }
    else
    {result[i]="      ";
    }
  }
  for(i=0;i<101;i++)
  {
    if(i==11||i==12||i==13||i==23||i==33||i==34||i==35||i==45||i==44||i==43||i==42||i==52||i==62||i==72||i==73||i==74||i==84||i==94||i==95||i==96||i==97||i==98||i==99||i==100)
    { if(result[i]==arr[i])
    {y=0;}
    else if(result[i]!=arr[i])
    {y=1;
    break;}
    }
  }
  return y;
}

int level8::resultant()
{
  return resultarr();
}

void level8::on(State *st)
{
  
  printw("\n\n     Congrats, Level 8 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  printw("\n\n     Congrats, you have completed the game.\n      Press any key to exit\n");
  delete this;
}