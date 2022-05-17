#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//creates new queue with maximum capacity
queue *newQueue(int maximum_size)
{
   
  queue *q=(queue*)malloc(sizeof(queue));
  q->max_size=maximum_size;
  q->front=0;
  q->rear=-1;
  q->song =(char**)malloc(maximum_size*51*sizeof(char));
   
  return q;
}
//returns 1 if empty,else returns 0
int isEmptyqueue(queue *q)
{
  return (q->front > q->rear);
}
//returns 1 if full,else returns 0
int isFullqueue(queue *q)
{
  return (q->rear==q->max_size-1);
}
//function to enqueue an element into a queue
void enqueue(queue *q,char* song_name)
{
  if(isFullqueue(q))
  {
    printf("Full queue\n");
  }

  else
  {//increments rear by 1 and assigns song at the rear part of queue
    q->rear=q->rear+1;
    q->song[q->rear]=song_name;
  }
}
//function to dequeue an element from a queue
char* dequeue(queue *q)
{
  if(isEmptyqueue(q))
  {
    printf("Empty queue\n");
    return NULL;
  }

  else
  {//increments front by 1
    char* dequeued_song=q->song[q->front];
    q->front=q->front+1;
    return dequeued_song;
  }
}

//function to print queue
void printqueue(queue *q){
for(int i=q->front;i<=q->rear;i++)
{
  printf("%s\n",q->song[i]);
}
printf("\n");
}




  