struct Avl
{
  char* song;
  struct Avl *leftsubtree;
  struct Avl *rightsubtree;
  int height;
};
typedef struct Avl avl;
avl* newavl(char *song);
int heightofnode(avl* node);
int search_avl(queue* inorder,char* song);
avl* leftleft(avl *node);
avl* rightright(avl* node);
avl* leftright(avl* node);
avl* rightleft(avl* node);
avl* insert(avl *tree,char* song);
int balance(avl* tree);
queue* inorderget(avl *tree,queue* inorder);
queue* preorderget(avl *tree,queue* preorder);
avl* balanceinsertion(int balance,avl* tree,char* song);
avl* avlinorder_successor_node_two_children(avl* tree);
avl* delete_from_playlist(char *song_name,avl* tree);
avl* balancedeletion(int balance,avl* tree,char* song);
int sizeofinorder_avl(queue* inorder);