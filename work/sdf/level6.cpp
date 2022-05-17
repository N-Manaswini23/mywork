#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level6.h"
#include"level7.h"
level6::level6(){

 for(int i=0;i<101;i++){
   if(i==13||i==15||i==30||i==31||i==32||i==33||i==25||i==27||i==57||i==58||i==88||i==89||i==79||i==100){
      arr[13]="  M2  ";
      arr[15]="  M3  ";
      arr[30]="   S  ";
      arr[31]="......";
      arr[32]="......";
      arr[33]="  M1  ";
      arr[25]="  M4  ";
      arr[27]="  M5  "; 
      arr[57]="  M6  ";
      arr[58]="  M7  ";
      arr[88]="  M8  ";
      arr[89]="  M9  ";
      arr[79]="   E  ";
      arr[100]="hr";
     
   }
   else {
        arr[i]="      ";
        
       }
 }
    side=10;
    choice=0;
    s="  M1  ";
}
 
void level6::printboard()
{
  {printw("\n\n\n");
	start_color();
  use_default_colors();
	init_pair(4,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(4));
  printw(" ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n");
  refresh();
  for(int i=0;i<10;i++)
  {printw("|");
  wprintw(stdscr,(arr+0+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+7+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+8+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+9+10*i)->data());
  refresh();
  printw("|\n");
  refresh();
  printw("|______|______|______|______|______|______|______|______|______|______|\n");
  refresh();
  }
  attroff(COLOR_PAIR(4));
}
}
int level6::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
   for(i=0;i <101;i++)
  { 
    if(i==30||i==31||i==32||i==33||i==23||i==13||i==14||i==15||i==25||i==26||i==27||i==37||i==47||i==57||i==58||i==68||i==78||i==88||i==89||i==79||i==100){
      result[30]="   S  ";
      result[31]="......";
      result[32]="......";
      result[33]="   /  ";
      result[23]="   :  ";
      result[13]="   /  ";
      result[14]="......";
      result[15]="   \\  ";
      result[25]="   \\  ";
      result[26]="......";
      result[27]="   \\  ";
      result[37]="   :  ";
      result[47]="   :  ";
      result[57]="   \\  ";
      result[58]="   \\  ";
      result[68]="   :  ";
      result[78]="   :  ";
      result[88]="   \\  ";
      result[89]="   /  ";
      result[79]="   E  ";
      result[100]="vu";
    }
    else {
      result[i]="      ";
    }
    }
    for(i=0;i<101;i++)
    {
     if(i==30||i==31||i==32||i==33||i==23||i==13||i==14||i==15||i==25||i==26||i==27||i==37||i==47||i==57||i==58||i==68||i==78||i==88||i==89||i==79||i==100)
      {
       if(result[i]==arr[i]){
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
int level6::resultant()
{return resultarr();}

void level6::on(State *st)
{
  
  printw("\n\n     Congrats, Level 6 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level7());
  st->ray->side=9;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}