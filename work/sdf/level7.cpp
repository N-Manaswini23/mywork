#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level7.h"
#include"level8.h"

level7::level7(){

    for (int i=0;i<82;i++){
    
  if(i==0||i==2||i==13||i==15||i==26||i==54||i==65||i==67||i==78||i==80||i==81)
  {
         arr[0]="  M1  ";
         arr[2]="  M2  ";
         arr[13]="  M5  ";
         arr[15]="  M6  ";
         arr[26]="   E  ";
         arr[54]="   S  ";
         arr[65]="  M3  ";
         arr[67]="  M4  ";
         arr[78]="  M7  ";
         arr[80]="  M8  ";
         arr[81]="vu";
  }
  else if (i%9==0 && i<54)
      {arr[i]="   :  ";}

  else {arr[i]="      ";}
  }
    side=9;
    choice=0;
    s="  M1  ";
 }
  void level7::printboard()
{ printw("\n\n\n");
  start_color();
  use_default_colors();
	init_pair(5,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(5));
   printw("    ______ ______ ______ ______ ______ ______ ______ ______ ______    \n");
  refresh();
  for(int i=0;i<9;i++)
  {printw("   |");
  wprintw(stdscr,(arr+0+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+7+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+8+9*i)->data());
  refresh();
  printw("|   \n");
  refresh();
  printw("   |______|______|______|______|______|______|______|______|______|   \n");
  refresh();
  }
  attroff(COLOR_PAIR(5));
}

int level7::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
      result[79]="......";
      result[80]="   /  ";
      result[81]="vu";

      if(result[79]==arr[79] && result[80]==arr[80] && result[81]==arr[81])
      {y = 0;}
    return y;
  }
}

int level7::resultant()
{
return resultarr();
}
void level7::on(State *st)
{
  
  printw("\n\n     Congrats, Level 7 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level8());
  st->ray->side=10;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}