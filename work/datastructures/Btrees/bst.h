
struct Secondry
{
  int secondary[100][40];
};
typedef struct Secondry secondry;
int search(secondry sec,int key);
secondry inorder_successor(secondry sec,int rightchild);
int parent(secondry sec,int key);
secondry insert(secondry sec,int key);
secondry delete(secondry sec,int key);
secondry onechild(secondry sec,int key,int position,int final_position);
secondry oneleftchild(secondry sec,int key,int position);
secondry onerightchild(secondry sec,int column,int row);
