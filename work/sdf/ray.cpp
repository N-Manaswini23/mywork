#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level1.h"
#include"level2.h"
#include"level3.h"
#include"level4.h"





void printinstructions()
{
  printw("\n\n            Instructions\n");
  waddstr(stdscr,"\n\n   S - Starting position of the light ray\n");
  waddstr(stdscr,"   E - Expected end position of the light ray\n\n");
  waddstr(stdscr,"             Mirror orientation codes:\n");
  waddstr(stdscr,"                      1 - \\\n");
  waddstr(stdscr,"                      2 - /\n");
  waddstr(stdscr,"                      3 - _\n");
  waddstr(stdscr,"                      4 - |\n\n");
  waddstr(stdscr," Orientation of a mirror can only be changed once\n");
  waddstr(stdscr,"\n           Press any key to continue\n     ");
}
  void raystriker:: printboard()
  {
    printw("base function");
  }
  int raystriker::resultarr()
  {
    return 1;
  }
  int raystriker::resultant()
  {
    return resultarr();
  }
void raystriker::on(State *st)
{
  printw("base function");
}
  
std::string* raystriker::orientation(int _i,int side,std::string *arr,int choice,std::string s)
{
  int i=_i,j=0;
  int n=side*side;
  int w=side;
  for(i=_i;i < n;i++)
  {
    if (arr[i]==s)
    {
      
    if (choice==1)
    {
      arr[i]="   \\  ";
      if (arr[n]=="hr" && (arr[i-1]=="......"||(arr[i-1]=="   \\  "&&arr[i-1-w]=="   :  ")||(arr[i-1]=="   /  "&&arr[i-1+w]=="   :  ")||(arr[i-1]=="  __  "&&arr[i-2]=="......")||(arr[i-1]=="   |  "&&arr[i]=="......")) && (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="vd";
         
          j=i+w;
    while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n)
           {
            if (arr[j]=="   \\  ")
            {
              s=arr[j];
              choice=1;
              
              orientation(j,w,arr,choice,s);
              
              break;
            }
            else if (arr[j]=="   /  ")
            {
              s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {
              s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {
              s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j+w;
            
            }
            
          }
        
        
      }
      else if (arr[n]=="hl"&&(arr[i+1]=="......"||(arr[i+1]=="   \\  "&&arr[i+w+1]=="   :  ")||(arr[i+1]=="   /  "&&arr[i-w+1]=="   :  ")||(arr[i+1]=="  __  "&&arr[i+2]=="......")||(arr[i+1]=="   |  "&&arr[i]=="   :  "))&& (i+1)%w!=0 && (i+1)<n)
      { 
         arr[n]="vu";
       j=i-w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            j=j-w;
            }
            
         }
         
      }
      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||(arr[i+w]=="   \\  "&&arr[i+w+1]=="......")||(arr[i+w]=="   /  "&& arr[i+w-1]=="......")||(arr[i+w]=="  __  "&&arr[i]=="   :  ")||(arr[i+w]=="   |  "&&arr[i+2*w]=="   :  "))&& (i)%w!=0&&(i+w)<n)
      {  
         arr[n]="hl";
       j=i-1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&&  arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0&& j%w!=w-1)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
              
            arr[j]="......";
            
            j=j-1;
            if (j==-1)
            {
              break;
            }
            }
         }
      }
      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||(arr[i-w]=="   \\  "&&arr[i-w-1]=="......")||(arr[i-w]=="   /  "&&arr[i-w+1]=="......")||(arr[i-w]=="  __  "&&arr[i]=="   :  ")||(arr[i-w]=="   |  "&&arr[i-2*w]=="   :  "))&& (i)%w!=w-1&&(i-w)>=0)
      { 
        arr[n]="hr";
       j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n && j%w!=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else 
            {
            arr[j]="......";
            
            j=j+1;
            }
         }         
      }
    }
     else if (choice==2)
    {
      
      arr[i]="   /  ";
      if (arr[n]=="hr" && (arr[i-1]=="......"||(arr[i-1]=="   \\  "&&arr[i-1-w]=="   :  ")||(arr[i-1]=="   /  "&&arr[i-1+w]=="   :  ")||(arr[i-1]=="  __  "&&arr[i-2]=="......")||(arr[i-1]=="   |  "&&arr[i]=="......")) && (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="vu";
         
          j=i-w;
          while(arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  "&&j>=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {
              s=arr[j];
              choice=2;
              
              orientation(j,w,arr,choice,s);
              
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
             
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              
              
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j-w;
            }
          }        
      }
      else if (arr[n]=="hl"&&(arr[i+1]=="......"||(arr[i+1]=="   \\  "&&arr[i+w+1]=="   :  ")||(arr[i+1]=="   /  "&&arr[i-w+1]=="   :  ")||(arr[i+1]=="  __  "&&arr[i+2]=="......")||(arr[i+1]=="   |  "&&arr[i]=="   :  "))&& (i+1)%w!=0 && (i+1)<n)
      { 
        arr[n]="vd";
       j=i+w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&&  arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j+w;
            }
         }
      }
      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||(arr[i+w]=="   \\  "&&arr[i+w+1]=="......")||(arr[i+w]=="   /  "&& arr[i+w-1]=="......")||(arr[i+w]=="  __  "&&arr[i]=="   :  ")||(arr[i+w]=="   |  "&&arr[i+2*w]=="   :  "))&&i%w!=w-1&&(i+w)<n)
      { 
        arr[n]="hr";
       j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n&& j%w!=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j+1;
            }
         }
      }
      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||(arr[i-w]=="   \\  "&&arr[i-w-1]=="......")||(arr[i-w]=="   /  "&&arr[i-w+1]=="......")||(arr[i-w]=="  __  "&&arr[i]=="   :  ")||(arr[i-w]=="   |  "&&arr[i-2*w]=="   :  "))&&(i)%w!=0&&(i-w)>=0)
      { 
        arr[n]="hl";
       j=i-1;
       
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0 && j%w!=w-1)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
              
            arr[j]="......";
            
            j=j-1;
            }
         }
      }
    }
    else if (choice==4)
    {
      arr[i]="   |  ";
      if (arr[n]=="hr" && (arr[i-1]=="......"||(arr[i-1]=="   \\  "&&arr[i-1-w]=="   :  ")||(arr[i-1]=="   /  "&&arr[i-1+w]=="   :  ")||(arr[i-1]=="  __  "&&arr[i-2]=="......")||(arr[i-1]=="   |  "&&arr[i]=="......"))&& (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="hl";
         
          j=i-1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&&  arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j>=0&& j%w!=w-1)
          {
            
            arr[j]="......";
            
            j=j-1;
            
          }
      }
      else if (arr[n]=="hl"&&(arr[i+1]=="......"||(arr[i+1]=="   \\  "&&arr[i+w+1]=="   :  ")||(arr[i+1]=="   /  "&&arr[i-w+1]=="   :  ")||(arr[i+1]=="  __  "&&arr[i+2]=="......")||(arr[i+1]=="   |  "&&arr[i]=="   :  "))&& (i+1)%w!=0 && (i+1)<n)
      { 
        arr[n]="hr";
       j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j<n&&j%w!=0)
          {
            
            arr[j]="......";
            
            j=j+1;
         }
      }
      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||(arr[i+w]=="   \\  "&&arr[i+w+1]=="......")||(arr[i+w]=="   /  "&& arr[i+w-1]=="......")||(arr[i+w]=="  __  "&&arr[i]=="   :  ")||(arr[i+w]=="   |  "&&arr[i+2*w]=="   :  "))&&(i+w)<n)
      { 
        arr[n]="vu";
       j=i-w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j-w;
            }
         }
      }
      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||(arr[i-w]=="   \\  "&&arr[i-w-1]=="......")||(arr[i-w]=="   /  "&&arr[i-w+1]=="......")||(arr[i-w]=="  __  "&&arr[i]=="   :  ")||(arr[i-w]=="   |  "&&arr[i-2*w]=="   :  "))&&(i-w)>=0)
      { 
        arr[n]="vd";
       j=i+w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j+w;
            }
         }
      }
    }
    else if (choice==3)
    {
      
      arr[i]="  __  ";
      if (arr[n]=="hr" && (arr[i-1]=="......"||(arr[i-1]=="   \\  "&&arr[i-1-w]=="   :  ")||(arr[i-1]=="   /  "&&arr[i-1+w]=="   :  ")||(arr[i-1]=="  __  "&&arr[i-2]=="......")||(arr[i-1]=="   |  "&&arr[i]=="......")) && (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="hr";
         
          j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&&  arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n&& j%w!=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j+1;
            }
          }
      }
      else if (arr[n]=="hl"&&(arr[i+1]=="......"||(arr[i+1]=="   \\  "&&arr[i+w+1]=="   :  ")||(arr[i+1]=="   /  "&&arr[i-w+1]=="   :  ")||(arr[i+1]=="  __  "&&arr[i+2]=="......")||(arr[i+1]=="   |  "&&arr[i]=="   :  "))&& (i+1)%w!=0 && (i+1)<n)
      { 
        arr[n]="hl";
       j=i-1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0&&j%w!=w-1)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j-1;
            }
         }
      }
      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||(arr[i+w]=="   \\  "&&arr[i+w+1]=="......")||(arr[i+w]=="   /  "&& arr[i+w-1]=="......")||(arr[i+w]=="  __  "&&arr[i]=="   :  ")||(arr[i+w]=="   |  "&&arr[i+2*w]=="   :  "))&&(i+w)<n)
      { 
        arr[n]="vd";
        
       j=i+w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j<n)
          {
           
            

            arr[j]="   :  ";
            
            j=j+w;
         }
      }
      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||(arr[i-w]=="   \\  "&&arr[i-w-1]=="......")||(arr[i-w]=="   /  "&&arr[i-w+1]=="......")||(arr[i-w]=="  __  "&&arr[i]=="   :  ")||(arr[i-w]=="   |  "&&arr[i-2*w]=="   :  "))&&(i-w)>=0)
      { 
         arr[n]="vu";
       j=i-w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&arr[j]!="  M6  "&& arr[j]!="  M7  "&& arr[j]!="  M8  " &&arr[j]!="  M9  "&& arr[j]!="  M10 "&&arr[j]!="  M11 "&& arr[j]!="  M12 "&& arr[j]!="  M13 " &&arr[j]!="  M14 "&& arr[j]!="  M15 "&& arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j>=0)
          {
            

            arr[j]="   :  ";
            
            j=j-w;
         }
      }
    }
  break;
  } 
  }
 return arr;
}

std::string* raystriker::orient(int _i,int _side,std::string *arr,int choice,std::string s)
{
  return orientation(_i,_side,arr,choice,s);
}


 
State::State()
{ 
  setstate(new level1());
  ray->side=4;
  ray->choice=0;
  ray->s="  M1  ";
  
}

std::string* State::onorient(int _i,int side, std::string *arr, int choice, std::string s)
{
  return ray->orient(_i,side,arr,choice,s);
}

int State::onresult()
{
 return ray->resultant();
}

void State::onboard()
{
  ray->printboard();
}

void State::on()
{
  ray->on(this);
}

void State::setstate(raystriker *r)
{
  ray=r;
}

