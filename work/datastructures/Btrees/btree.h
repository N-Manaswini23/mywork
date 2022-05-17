
struct Btree
{
  int secondary[100][40];
};
typedef struct Btree btree;
int search_btree(btree tree,int key);
btree insert_btree(btree tree,int key);
btree delete_btree(btree tree,int key);
int number_of_keys(btree tree,int key);
int isleaf(btree tree,int key);
int decide_path(btree tree,int key);
btree split_node(btree tree,int key);
btree shift_node(btree tree,int from,int to);
btree merge_node(btree tree,int key);
btree split_root(btree tree);
btree shift_root(btree tree,btree new_btree,int from,int to);
btree delete1a(btree tree,int key);
btree delete2a(btree tree,int key);
btree delete2b(btree tree,int key);
btree delete2c(btree tree,int key);
btree delete3a(btree tree,int key);
btree delete3b(btree tree,int key);
int successor(btree tree,int key);
int predecessor(btree tree,int key);