#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include<string.h>
#include<ctype.h>
#include "playlist.h"
//plays next song
void playnextsong(queue* playlist,stack* recent_songs)
{//dequeue song from playlist
  char *dequeued_song=dequeue(playlist);
  
  if(dequeued_song!=NULL&&strcmp(dequeued_song,"-1\n")!=0)
  {//push dequeued song into recent songs stack
    push(recent_songs,dequeued_song);
    printf("playing song --> %s\n",dequeued_song);
  }
  else if(dequeued_song==NULL||strcmp(dequeued_song,"-1\n")==0)
  {
    printf("No more songs in playlist\n");
  }
  
}

//plays previous songs
void playprevious(stack* recent_songs,int k)
{
  int i=1;
  queue* temporary_queue=newQueue(100);
  for(int i=1;i<=k;i++)
  {
    char* recentsong=top(recent_songs);
    
    if(recentsong!=NULL&&strcmp(recentsong,"-1\n")!=0)
    {//pushes previous song into temporary queue and plays it
      pop(recent_songs);
      printf("playing song --> %s\n",recentsong);
      enqueue(temporary_queue,recentsong);
    }
      else if(recentsong==NULL)
      {
        printf("there are no previous songs\n");
        break;
      }
    
  }

while(isEmptyqueue(temporary_queue)==0)
{//push all songs from temporary queue into recent songs stack
 
  push(recent_songs,dequeue(temporary_queue));
}

}

//if we enter n-playnextsong function gets executed
//if we enter p:k-playprevious function gets executed
//if we enter e-playlist ends
void select_n_p_e(queue* playlist,stack* recent_songs)
{
   char string[10]="0";
   char ch[]= ":";
   char *integer;
  
   
   while(strcmp(string,"e\n")!=0)
   {

      printf("play next song -n/play previous song-p:k/end-e\n");
   fgets(string,sizeof(string),stdin);
   //reads string before ":",if ":" is present in input
   integer = strtok(string, ch);
   //reads string after ":",if ":" is present in input
   
   integer=strtok(NULL,ch);
   
  int y=1;
  
   if(strcmp(string,"p\n")==0 )
   {
     if( integer!=NULL)
     {//checking if string after ":" is int
        for(int i=0;integer[i]!='\n';i++)
        {
          if(isdigit(integer[i]))
          {
            y=1;
           
          }
          else
          {
            y=0;
            
            printf("please enter in format of p:k,where k is integer\n");
            break;
          }
        }
     }
     else
     {
       printf("please enter in format of p:k,where k is integer\n");
     }
     
   }
  int x=0;
   if (y==1&&integer!=NULL)
   {//converting integer(which is string) into int
     x=atoi(integer);
   }
   
   

   if(y==1)
   {
     if(strcmp(string,"n\n")==0)
     {
       playnextsong(playlist,recent_songs);
     }
     else if(strcmp(string,"p")==0)
     {
       playprevious(recent_songs,x);
     }
     else if(strcmp(string,"e\n")==0)
   {
     printf("bye\n");
   }
     else
     {
       printf("please enter n/p:k/e");
     }
   }
   }
   

   


}
