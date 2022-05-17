#include <stdio.h>

#include<stdlib.h>
#include "stack.h"
//returns 1 if stack is empty,else returns 0
int isEmptystack(stack* s)
{
 return (s->size==-1);
}
//returns 1 if stack is full,else returns 0
int isFullstack(stack* s)
{
  return (s->size==s->max_size-1);
}
//function to push an element into stack
void push(stack* s,char new_song[])
{
  if (isFullstack(s))
  {
    printf("stack is full\n");
  }
  else
  {//increment size by 1 and assign new song at last
    s->size +=1;
    s->song[s->size]=new_song;
  }
}
//function to pop from stack
void pop(stack* s)
{
 if (isEmptystack(s))
 {
   printf("Stack is Empty\n");
   
 }
 else
 {
   s->size-=1;
   
 }
}
//returns top element of stack
char* top(stack* s)
{

  if (isEmptystack(s))
 {
   printf("Stack is Empty\n");
   return NULL;
 }
 else
 {
   return s->song[s->size];
 }

}
//creates new stack with maximum capacity
stack *newStack(int maximum_size)
{
   
  stack *s=(stack*)malloc(sizeof(stack));
  s->max_size=maximum_size;
  s->size=-1;
   
  s->song =(char**)malloc(maximum_size*51*sizeof(char));
   
  return s;
}

