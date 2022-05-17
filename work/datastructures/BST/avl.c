#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "queue.h"

#include"avl.h"


avl* newavl(char *song)
{//creates new tree with one node
  avl* avltree=(avl*)malloc(sizeof(avl));
  avltree->song=song;
  //assign left and right subtree as NULL
  avltree->leftsubtree=NULL;
  avltree->rightsubtree=NULL;
  //assign height as 1
  avltree->height=1;
  return avltree;
}
int heightofnode(avl* node)
{//return height as 0 if tree is NULL
  if (node==NULL)
  {
    return 0;
  }
  return node->height;
}
//returns 1 if song is found in inorder else returns 0
int search_avl(queue* inorder,char* song)
{
 for(int i=0;i<sizeofinorder_avl(inorder);i++)
 {
   if(strcmp(inorder->song[i],song)==0)
   {
     return 1;
   }
 }
 return 0;
}
//left left imbalance case(right rotate)
//leftsubtree of root becomes new root,root becomes rightsubtree of new root
//rightsubtree of leftsubtree(before balance) becomes leftsubtree of old root

avl* leftleft(avl* node)
{
  avl* leftnode=node->leftsubtree;
  avl* rightleftnode=leftnode->rightsubtree;
  leftnode->rightsubtree=node;
  node->leftsubtree=rightleftnode;
//update node height
  node->height=(heightofnode(node->leftsubtree)>heightofnode(node->rightsubtree))?heightofnode(node->leftsubtree):heightofnode(node->rightsubtree);
  node->height=node->height+1;
  leftnode->height=(heightofnode(leftnode->leftsubtree)>heightofnode(leftnode->rightsubtree))?heightofnode(leftnode->leftsubtree):heightofnode(leftnode->rightsubtree);
  leftnode->height=leftnode->height+1;
  return leftnode;
}
//right right imbalance case(left rotate)
//rightsubtree of root becomes new root,root becomes leftsubtree of new root
//leftsubtree of rightsubtree(before balance) becomes rightsubtree of old root
avl* rightright(avl* node)
{
  avl* rightnode=node->rightsubtree;
  avl* leftrightnode=rightnode->leftsubtree;
  rightnode->leftsubtree=node;
  node->rightsubtree=leftrightnode;
//update node height
  node->height=(heightofnode(node->leftsubtree)>heightofnode(node->rightsubtree))?heightofnode(node->leftsubtree):heightofnode(node->rightsubtree);
  node->height=node->height+1;
  rightnode->height=(heightofnode(rightnode->leftsubtree)>heightofnode(rightnode->rightsubtree))?heightofnode(rightnode->leftsubtree):heightofnode(rightnode->rightsubtree);
  rightnode->height=rightnode->height+1;
  return rightnode;
}
//left right imbalance case
//left rotate leftsubtree of root
//right rotate root

avl* leftright(avl* node)
{
  node->leftsubtree=rightright(node->leftsubtree);
  node=leftleft(node);
  return node;
}
//right left imbalance case
//right rotate leftsubtree of root
//left rotate root
avl* rightleft(avl* node)
{
  node->rightsubtree=leftleft(node->rightsubtree);
  node=rightright(node);
  return node;
}



//avl tree insertion
avl* insert(avl* tree,char* song)
{//if tree is NULL ,create new avltree with one node
  if(tree==NULL)
  {
    return newavl(song);
  }
 //if song appears after tree->song according to lexographic order,insert song in rightsubtree
  if(strcmp(song,tree->song)>0)
  { 
    tree->rightsubtree=insert(tree->rightsubtree,song);
  }
  //if song appears before tree->song according to lexographic order,insert song in leftsubtree
  else if(strcmp(song,tree->song)<0)
  {
    tree->leftsubtree=insert(tree->leftsubtree,song);
  }
  //if song already exists in tree,return tree without any change
  else
  {
    return tree;
  }
//update tree height
 tree->height=(heightofnode(tree->leftsubtree)>heightofnode(tree->rightsubtree))?heightofnode(tree->leftsubtree):heightofnode(tree->rightsubtree);
  tree->height=tree->height+1;
  //balance tree at each level after insertion
 int balnce=0;
 if(tree!=NULL)
 {
   balnce=balance(tree);
   return balanceinsertion(balnce,tree,song);
 }


  return tree;
}


//function to get inorder traversal of avl tree
queue* inorderget(avl *tree,queue* inorder)
{
  if(tree==NULL)
  {
    return NULL;
  }
  inorderget(tree->leftsubtree,inorder);
  enqueue(inorder,tree->song);
  inorderget(tree->rightsubtree,inorder);
return inorder;
}
//function to get preorder traversal of avl tree
queue* preorderget(avl *tree,queue* preorder)
{
  if(tree==NULL)
  {
    return NULL;
  }
  enqueue(preorder,tree->song);
  preorderget(tree->leftsubtree,preorder);
  
  preorderget(tree->rightsubtree,preorder);
return preorder;
}

//balance avl tree after insertion
avl* balanceinsertion(int balance,avl* tree,char* song)
{//left left case
  if(balance>1&&strcmp(song,tree->leftsubtree->song)<0)
  {
    return leftleft(tree);
  }
  //right right case
  if(balance<-1&&strcmp(song,tree->rightsubtree->song)>0)
  { 
    return rightright(tree);
  }
  //left right case
  if(balance>1&&strcmp(song,tree->leftsubtree->song)>0)
  {
    return leftright(tree);
  }
  //right left case
  if(balance<-1&&strcmp(song,tree->rightsubtree->song)<0)
  {
    return rightleft(tree);
  }
  return tree;
}


//inorder successor of node with two children
avl* avlinorder_successor_node_two_children(avl* tree)
{
  while (tree!=NULL&&tree->leftsubtree!=NULL)
  {
    tree=tree->leftsubtree;
  }
  return tree;
}


//avl tree deletion
avl* delete_from_playlist(char *song_name,avl* tree)
{ //if tree is null ,return NULL(tree)
  if (tree==NULL)
  {
    return tree;
  }
   //if song appears after tree->song according to lexographic order,insert song in rightsubtree
  if(strcmp(song_name,tree->song)>0)
  {
    tree->rightsubtree=delete_from_playlist(song_name,tree->rightsubtree);
  }
   //if song appears before tree->song according to lexographic order,delete song in leftsubtree
  else if(strcmp(song_name,tree->song)<0)
  {
    tree->leftsubtree=delete_from_playlist(song_name,tree->leftsubtree);
  }
//if song is found ,delete song
  else if(strcmp(song_name,tree->song)==0)
  { //no child case
  //delete song by making the corresponding node NULL
     if(tree->leftsubtree==NULL&&tree->rightsubtree==NULL)
     {
       tree=NULL;
     }
     //one child case
     //has left subtree as child
     //replace node corresponding to song by its leftsubtree
     else if(tree->leftsubtree!=NULL&&tree->rightsubtree==NULL)
     {
       tree=tree->leftsubtree;
     }
     //has right subtree as child
     //replace node corresponding to song by its rightsubtree
     else if(tree->leftsubtree==NULL&&tree->rightsubtree!=NULL)
     {
       tree=tree->rightsubtree;
     }
     //two childern case
     //replace node corresponding to song by its inorder successor
     else if(tree->leftsubtree!=NULL&&tree->rightsubtree!=NULL)
     {
       avl* successor =avlinorder_successor_node_two_children(tree->rightsubtree);
       tree->song=successor->song;
       
       tree->rightsubtree=delete_from_playlist(successor->song,tree->rightsubtree);
      
     }
  }
//update height
if (tree==NULL)
  {
    return tree;
  }
   tree->height=(heightofnode(tree->leftsubtree)>heightofnode(tree->rightsubtree))?heightofnode(tree->leftsubtree):heightofnode(tree->rightsubtree);
  tree->height=tree->height+1;
  
 int balnce=balance(tree);

//balance tree after deletion at each level
 return balancedeletion(balnce,tree,song_name);

 
}


//returns difference in height between left and right subtree
int balance(avl* tree)
{
  if(tree==NULL)
  {
    return 0;
  }
  else
  {
    return heightofnode(tree->leftsubtree)-heightofnode(tree->rightsubtree);
  }
}
//balance after deletion
avl* balancedeletion(int balnce,avl* tree,char* song)
{ //leftleft case
  if(balnce>1&& balance(tree->leftsubtree)>=0)
  {
    return leftleft(tree);
  }
  //rightrightcase
  if(balnce<-1&& balance(tree->rightsubtree)<=0)
  { 
    return rightright(tree);
  }
  //leftright case
  if(balnce>1&& balance(tree->leftsubtree)<0)
  {
    return leftright(tree);
  }
  //rightleft case
  if(balnce<-1&& balance(tree->rightsubtree)>0)
  {
    return rightleft(tree);
  }
  return tree;
}
//to find number of nodes in avl tree
int sizeofinorder_avl(queue* inorder)
{
  int i=0;
  while(inorder->song[i]!=NULL)
  {
    i++;
  }
  return i;
}