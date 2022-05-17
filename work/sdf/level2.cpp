#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level2.h"
#include"level3.h"
level2::level2()
  {
    for(int i=0;i <37;i++)
  { 
    if (i==0||i==1||i==2||i==3||i==6||i==14||i==21||i==22||i==25||i==34||i==35||i==36)
    {
      arr[0]="   S  ";
      arr[1]="......";
      arr[2]="......";
      arr[3]="  M1  ";
      arr[6]="  M2  ";
      
      arr[14]="  M4  ";
      
      arr[21]="  M3  ";
      arr[22]="  M5  ";
      arr[25]="  M6  ";
      arr[34]="  M7  ";
      
      arr[35]="   E  ";
      arr[36]="hr";
    }
    else
    {
      arr[i]="      ";
    }
  }


    side=6;
    choice=0;
    s="  M1  ";
  }



  void level2::printboard()
{
  {printw("\n\n\n");
	start_color();
  use_default_colors();
	init_pair(4,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(4));
  printw("    ______ ______ ______ ______ ______ ______    \n");
  refresh();
  for(int i=0;i<6;i++)
  {printw("   |");
  wprintw(stdscr,(arr+0+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+6*i)->data());
  refresh();
  printw("|   \n");
  refresh();
  printw("   |______|______|______|______|______|______|   \n");
  refresh();
  }
  attroff(COLOR_PAIR(4));
}
}

int level2::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
   for(i=0;i <37;i++)
  { 
    if (i==0||i==1||i==2||i==3||i==9||i==15||i==21||i==22||i==28||i==34||i==35||i==36)
    {
      result[0]="   S  ";
      result[1]="......";
      result[2]="......";
      result[3]="   \\  ";
      result[9]="   :  ";
      result[15]="   :  ";
      result[21]="   \\  ";
      result[22]="   \\  ";
      result[28]="   :  ";
      result[34]="   \\  ";
      result[35]="   E  ";
      result[36]="hr";
    }
    else
    {
      result[i]="      ";
    }
  }
  for(i=0;i <37;i++)
  {
    if (i==0||i==1||i==2||i==3||i==9||i==15||i==21||i==22||i==28||i==34||i==35||i==36)
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

int level2::resultant()
{return resultarr();}

void level2::on(State *st)
{
  
  printw("\n\n     Congrats, Level 2 complete.\n      Press any key to continue\n\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level3());
  st->ray->side=8;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}