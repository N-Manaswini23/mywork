
struct Queue
{
  char **song;
  int front;
  int rear;
  int max_size;
 
};

typedef struct Queue queue;
queue *newQueue(int maximum_size);
int isEmptyqueue(queue *q);
int isFullqueue(queue *q);
void enqueue(queue *q,char* song_name);
char* dequeue(queue *q);
void printqueue(queue *q);

int search_queue(char* song_name,queue* q);