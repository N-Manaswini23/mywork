#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "queue.h"
#include "binarytree.h"
#include"avl.h"
#include"stack.h"
#include"playlist.h"
#define MAX_SONGS 1000
//gcc -o main main.c avl.c binarytree.c playlist.c queue.c stack.c   
//enter the above command to run the code
int main() {


  queue* inorder =newQueue(MAX_SONGS);
  queue* preorder =newQueue(MAX_SONGS);
char* data =(char*)malloc(MAX_SONGS*51*sizeof(char));
FILE *file;
//open file in read mode
file=fopen("traversal.txt","r");
if(file==NULL)
{
  printf("failed to open file");
  return 1;
}
   //read from file and store it in data
   while(fgets(data,10000,file)!=NULL)
   {
     continue;
   }
   //strtok(data,":") returns string before first ":" in data
 preorder->song[0]=strtok(data,":"); 
int i=0;
//strtok(NULL,":") returns next elements in preorder traversal
while(preorder->song[i]!=NULL)
{
  i++;
  preorder->song[i]=strtok(NULL,":");
}

int len=i;
//construct binary tree
binarytree* root = construct_tree(preorder, 0, len - 1);
//update inorder and preorder traversals
inorder=newQueue(MAX_SONGS);
inorder=getinorder(root,inorder);
preorder=newQueue(MAX_SONGS);
preorder=getpreorder(root, preorder);
char song[51];
//delete song if it is in inorder traversal of tree
printf("enter songs u wish to delete,end with -1\n");
while(strcmp(song,"-1")!=0)
  {
     scanf("%[^\n]%*c",song);
     if(search(inorder,song)==1)
     {
     root=delete_node(song,root);
     if(root!=NULL)
     {//update inorder and preorder traversals
     inorder=newQueue(MAX_SONGS);
     inorder=getinorder(root,inorder);
     preorder=newQueue(MAX_SONGS);
     preorder=getpreorder(root, preorder);
     }
     }
     else if(strcmp(song,"-1")!=0)
     {
       printf("Enter song present in list\n");
     }
     
  }
if(root==NULL)
{
  printf("you deleted all songs\n");
  return 0;
}
//update inorder and preorder traversals
inorder=newQueue(MAX_SONGS);
inorder=getinorder(root,inorder);
preorder=newQueue(MAX_SONGS);
preorder=getpreorder(root, preorder);

avl* avltree=NULL;
int m=inorder->rear+1;
//insert elements from inorder into avltree one by one
for(int k=0;k<m;k++)
{
  char *dequed_song=dequeue(inorder);
  avltree=insert(avltree,dequed_song);
  
}
inorder=newQueue(MAX_SONGS);
inorder=inorderget(avltree,inorder);
//delete song if it is in inorder traversal of tree
printf("enter songs u wish to delete in playlist,end with -1\n");
strcpy(song,"\0");
   while(strcmp(song,"-1")!=0)
   {
     scanf("%[^\n]%*c",song);
     if(search_avl(inorder,song)==1)
     {
     avltree=delete_from_playlist(song,avltree);
      if(avltree!=NULL)
     {
     inorder=newQueue(MAX_SONGS);
     inorder=getinorder(root,inorder);
     preorder=newQueue(MAX_SONGS);
     preorder=getpreorder(root, preorder);
     }
     }
      else if(strcmp(song,"-1")!=0)
     {
       printf("Enter song present in list\n");
     }
     
   }
if(avltree==NULL)
{
  printf("you deleted all songs\n");
  return 0;
}
inorder=newQueue(MAX_SONGS);
inorder=inorderget(avltree,inorder );
//printqueue(inorder);
preorder=newQueue(MAX_SONGS);
preorder=preorderget(avltree, preorder);
//printqueue(preorder);
stack* recent_songs=newStack(MAX_SONGS);
select_n_p_e(inorder,recent_songs);



  return 0;
}