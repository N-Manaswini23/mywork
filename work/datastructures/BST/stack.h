struct Stack
{
  int max_size;
  int size;
  char** song;
};
typedef struct Stack stack;
int isEmptystack(stack* s);
int isFullstack(stack* s);
void push(stack* s,char new_song[]);
void pop(stack* s);
char* top(stack* s);
stack *newStack(int maximum_size);
