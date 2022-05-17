#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "queue.h"
#include"binarytree.h"





binarytree* newbinarytree(char *song_name)
{//creates new tree with one node
   binarytree *newtree=(binarytree*)malloc(sizeof(binarytree));
   newtree->song=song_name;
   //assign left and right subtree as NULL
   newtree->leftsubtree=NULL;
   newtree->rightsubtree=NULL;

   return newtree;
}
//returns 1 if song is found in inorder else returns 0
int search(queue* inorder,char* song)
{
 for(int i=0;i<sizeofinorder(inorder);i++)
 {
   if(strcmp(inorder->song[i],song)==0)
   {
     return 1;
   }
 }
 return 0;
}


//returns index at which song_name appears before preorder->song[index] according to lexographic order
int find_in_inorder(char *song_name,int from,int to,queue *preorder)
{
  int j=from;
  
 for(j=from;j<=to;j++)
 {
   if(strcmp(song_name,preorder->song[j])<0)
 {
   break;
 }
   
 }
  return j;
}

//constructs binary tree from given preorder
binarytree* construct_tree(queue* preorder,int from,int to)
{
  
  static int index=0;
  binarytree* tree=newbinarytree(preorder->song[index]);
//if index from>to ,return NULL
  if(from>to)
  {
    return NULL;
  }
   index++;
   //if index from==to ,return tree
  if(from==to)
  {
   
    return tree;
  }
 //find index upto which leftsubtree nodes of tree is contained
  int i=find_in_inorder(tree->song,from,to,preorder);
  //construct leftsubtree
  tree->leftsubtree=construct_tree(preorder,index,i-1);
  //construct rightsubtree
  tree->rightsubtree=construct_tree(preorder,i,to);


  return tree;
}


//inorder successor of node with two children
binarytree* inorder_successor_node_two_children(binarytree* tree)
{
  while (tree!=NULL&&tree->leftsubtree!=NULL)
  {
    tree=tree->leftsubtree;
  }
  return tree;
}
//deletion from binarytree
binarytree* delete_node(char *song_name,binarytree* tree)
{ //if song appears after tree->song according to lexographic order,insert song in rightsubtree
  if(strcmp(song_name,tree->song)>0)
  {
    tree->rightsubtree=delete_node(song_name,tree->rightsubtree);
  }
   //if song appears before tree->song according to lexographic order,insert song in leftsubtree
  else if(strcmp(song_name,tree->song)<0)
  {
    tree->leftsubtree=delete_node(song_name,tree->leftsubtree);
  }

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
       
       binarytree* successor =inorder_successor_node_two_children(tree->rightsubtree);
       tree->song=successor->song;
       
       tree->rightsubtree=delete_node(successor->song,tree->rightsubtree);
      
     }
  }
  return tree;
}

//gets inorder traversal of binary tree stored into queue inorder
queue* getinorder(binarytree *tree,queue* inorder)
{
  if(tree==NULL)
  {
    return NULL;
  }
  getinorder(tree->leftsubtree,inorder);
  enqueue(inorder,tree->song);
  getinorder(tree->rightsubtree,inorder);
return inorder;
}

queue* getpreorder(binarytree *tree,queue* preorder)
{
  if(tree==NULL)
  {
    return NULL;
  }
  enqueue(preorder,tree->song);
  getpreorder(tree->leftsubtree,preorder);
  
  getpreorder(tree->rightsubtree,preorder);
return preorder;
}
//to find number of nodes in binary tree
int sizeofinorder(queue* inorder)
{
  int i=0;
  while(inorder->song[i]!=NULL)
  {
    i++;
  }
  return i;
}