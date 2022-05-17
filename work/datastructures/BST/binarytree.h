
struct Binarytree
{
   char* song;
   struct Binarytree* leftsubtree;
   struct Binarytree* rightsubtree;
};

typedef struct Binarytree binarytree;


binarytree* newbinarytree(char *song_name);
int search(queue* inorder,char* song);
int find_in_inorder(char *song_name,int from,int to,queue *inorder);
//binarytree* construct_tree(queue* inorder,queue* preorder,int from,int to);
binarytree* construct_tree(queue* preorder,int from,int to);
binarytree* inorder_successor_node_two_children(binarytree* tree);
binarytree* delete_node(char *song_name,binarytree* tree);
queue* getinorder(binarytree *tree,queue* inorder);
queue* getpreorder(binarytree* tree,queue *preorder);
int sizeofinorder(queue* inorder);






