#include<iostream>
#include<string>
#include"ray.h"
#include<ncurses.h>
#include"level1.h"
#include"level2.h"
#include"level3.h"
#include"level4.h"
#include"level5.h"
#include"level6.h"
#include"level7.h"
#include"level8.h"

//clang++-7 -std=c++17 -lncurses -o main main.cpp ray.cpp  level1.cpp level2.cpp level3.cpp level4.cpp level5.cpp level6.cpp level7.cpp level8.cpp

int main()
{
  initscr();
  if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color.\n");
		exit(1);
	}
  start_color();			
	init_pair(3,COLOR_BLACK +16,COLOR_WHITE+8);
  wbkgd(stdscr,COLOR_PAIR(3));
  char* c;
  printw("\n\n\n\n          Welcome to Ray Strikers 2D");
  
  unsigned count=1;
  unsigned k;
  unsigned l=0;

  
  
  std::string *arra=static_cast<std::string*>(malloc(2000*sizeof(std::string)));
  std::string s="  M1  ";
  int i=0;
  printinstructions();
  getch();
  clear();
  refresh();
   
  
  refresh();
  int choice=0;
  State stte;
  int y=0;
  for (int j=0;j<8;j++)
  { if(y==0)
  {
    y=1;
    i=1;
    arra=stte.ray->arr;
    int sid=stte.ray->side;
 
  while(y==1)
  {stte.onboard();
  if (i==1)
  { s="  M1  ";}
  else if (i==2)
  { s="  M2  ";}
  else if (i==3)
  { s="  M3  ";}
  else if (i==4)
  { s="  M4  ";}
  else if (i==5)
  { s="  M5  ";}
  else if (i==6)
  { s="  M6  ";}
  else if (i==7)
  { s="  M7  ";}
  else if (i==8)
  { s="  M8  ";}
  else if (i==9)
  { s="  M9  ";}
  else if (i==10)
  { s="  M10 ";}
  else if (i==11)
  { s="  M11 ";}
  else if (i==12)
  { s="  M12 ";}
  else if (i==13)
  { s="  M13 ";}
  else if (i==14)
  { s="  M14 ";}
  else if (i==15)
  { s="  M15 ";}

  printw("\n       Choose mirror M%d orientation\n",i);
  refresh();
  scanw("%d",&choice);
  refresh();
  clear();
  refresh();
  arra=stte.onorient(0,sid,arra,choice,s);
  stte.ray->arr=arra;
  stte.onboard();
  refresh();
  y=stte.onresult();

  if(y==0)
  {
    if(j<8)
    {
    stte.on();
    refresh();
    break;
    }
  }
  
  else if(y==1&&choice<=4 &&choice>0)
  {
    if(i==5&&j==0)
    {
      printw("\n\n        Level 1 not complete. Try again.\n           Press any key to continue\n");
      
      refresh();
      getch();
      refresh();
    break;
    }
    else if (i==7&&j==1)
    {
      printw("\n\n      Level 2 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
      refresh();
     
      break;
    }
  else if (i==9&&j==2)
    {
      printw("\n\n      Level 3 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
      refresh();
      
      break;
    }
  else if (i==15&&j==3)
    {
      printw("\n\n      Level 4 not complete. Try again.\n         Press any key to continue\n");
      
      getch();
      clear();
      refresh();
      
      break;
    }
    else if (i==7&&j==4)
    {
      printw("\n\n      Level 5 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
     
      break;
    }
    else if (i==9&&j==5)
    {
      printw("\n\n      Level 6 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
     
      break;
    }
    else if (i==8&&j==6)
    {
      printw("\n\n      Level 7 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
     
      break;
    }
     else if (i==8&&j==7)
     {
	     printw("\n\n   Level8 not complete.Try again.\n   Press any key to continue\n");
	     refresh();
	     getch();
	     
	     break;
     }
     
  }
  if(choice==1||choice==2||choice==3||choice==4)
  {i++;}
 
  refresh();
  clear();
  refresh();
  }
   } 
  }
  getch();
  endwin();
  return 0;
}