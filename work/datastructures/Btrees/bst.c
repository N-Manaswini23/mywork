#include"stdio.h"
#include"stdlib.h"
#include"bst.h"
#define t 40

//returns index at which given key is present
int search(secondry sec,int key)
{
    int i=0;
    int j=0,k=0,n=0;
    int status=0;
    int array[t];//readdisk
    for(int n=0;n<t;n++)
    {
        array[n]=sec.secondary[0][n];
    }
    n=0;

    while(status==0)
    {
        if(array[n]==0)
        {
              printf("no such element %d\n",key);
            return -1;
        }//search in rightsubtree
        else if(array[n]<key)
        {
            k=i+2;
        }//search in leftsubtree
        else if(array[n]>key)
        {
            k=i+1;
        }
        else//if equal break and return index
        {
            break;
        }
        n=i+k;
        if(n>=40)
        {
           j=n/40;
           
           n=n%40;

        }
        for(int m=0;m<t;m++)//readdisk
           {
              array[m]=sec.secondary[j][m];
           }
            i=i+k;
    }
    return i;

}

//returns parent of given key
int parent(secondry sec,int key)
{
   int i=search(sec,key);//parent is present at index (i-1)/2
   int parent=(i-1)/2;
   int y=parent/t;
   int x=parent%t;
   int array[t];
   int n=0;
    for(int n=0;n<t;n++)//readdisk
    {
        array[n]=sec.secondary[y][n];
    }
    return array[x];

}

//this function is used in deletion when the key has only one child

secondry onechild(secondry sec,int key,int position,int final_position)
{
    int i=position;
    int j=final_position;
    int array_child[t];
   int n=0;//readdisk
    for(int n=0;n<t;n++)//store the row in which child is present in array_child
    {
        array_child[n]=sec.secondary[i/40][n];
    }
    int array_parent[t];
    for(int n=0;n<t;n++)//readdisk
    {//store the row in which parent is present in array_parent
        array_parent[n]=sec.secondary[j/40][n];
    }//replace parent by child
    array_parent[j%40]=array_child[i%40];
    array_child[i%40]=0;
    for(int n=0;n<t;n++)//writedisk
    {//update the bst
        sec.secondary[j/40][n]=array_parent[n];
    }
    for(int n=0;n<t;n++)//writedisk
    {//update bst
        sec.secondary[i/40][n]=array_child[n];
    }
    int array_child_leftchild[t];
    int k=2*i+1;
    
    for(int n=0;n<t;n++)//readdisk
    {
        array_child_leftchild[n]=sec.secondary[k/40][n];
    }
    int array_child_rightchild[t];
    int m=2*i+2;
    
    for(int n=0;n<t;n++)//readdisk
    {
        array_child_rightchild[n]=sec.secondary[m/40][n];
    }//update the positions of children of new parent
   if(array_child_leftchild[k%40]!=0)
    {
        sec=onechild(sec,array_child_leftchild[k%40],k,2*j+1);
    }
    if(array_child_rightchild[m%40]!=0)
    {
        sec=onechild(sec,array_child_rightchild[m%40],m,2*j+2);
    }
return sec;
}
//returns bst after balancing it incase of deleting a node with two children
secondry inorder_successor(secondry sec,int rightchild)
{
           int i=search(sec,rightchild);
           int m=(i-1)/2;
           int array_parent[t];
           for(int n=0;n<t;n++)//store the row in which parent is present in array_parent
    {//readdisk
        array_parent[n]=sec.secondary[m/40][n];
    }
           int j=2*i+1;
           int array_leftchild[t];
    for(int n=0;n<t;n++)//readdisk
    {//store the row in which left child is present in array_leftchild
        array_leftchild[n]=sec.secondary[j/40][n];
    }
    while(array_leftchild[j%40]!=0)
    {
        j=2*j+1;
        for(int n=0;n<t;n++)
    {
        array_leftchild[n]=sec.secondary[j/40][n];
    }
    }
    int k=(j-1)/2;//k is index of inorder successor
    for(int n=0;n<t;n++)//readdisk
    {//store the row in which inordersuccessor is present in array_leftchild
        array_leftchild[n]=sec.secondary[k/40][n];
    }//replace parent by inordersuccessor
    array_parent[m%40]=array_leftchild[k%40];
    if(k/40==m/40)//readdisk
    { 
        array_leftchild[m%40]=array_parent[m%40];
    }
    
    for(int n=0;n<t;n++)//writedisk
    {
        sec.secondary[m/40][n]=array_parent[n];
    }
    int x=2*k+2;
    int inorder_rightchild[t];//if inorder successor has rightchild,then shift rightsubtree of successor to previous index of successor
    for(int n=0;n<t;n++)
    {
        inorder_rightchild[n]=sec.secondary[x/40][n];
    }
    if(inorder_rightchild[x%40]!=0)
    {
        sec=onechild(sec,inorder_rightchild[x%40],x,k);
    }
    else
    {
        array_leftchild[k%40]=0;
        for(int n=0;n<t;n++)
    {//update bst
        sec.secondary[k/40][n]=array_leftchild[n];
    }
    }
     return sec; 
}

//function to inset a key into bst
secondry insert(secondry sec,int key)
{
    int i=0;
    int j=0,k=0,n=0;
    int status=0;
    int array[t];
    for(int n=0;n<t;n++)
    {
        array[n]=sec.secondary[0][n];
    }
    n=0;
    while(status==0)
    {
        if(array[n]==0)
        {//if empty place is found insert new key
            array[n]=key;
            for(int m=0;m<t;m++)
              {//update bst
                 sec.secondary[j][m]=array[m];
              }
             printf("inserted %d\n",key);
            break;
        }
        else if(array[n]<key)
        {//insert right
            k=i+2;
        }
        else if(array[n]>key)
        {//insert left
            k=i+1;
        }
        else
        {
            printf("already inserted\n");
            break;
        }
        n=i+k;
        if(n>=40)
        {
           j=n/40;
           
           n=n%40;

        }
        for(int m=0;m<t;m++)
           {//update array
              array[m]=sec.secondary[j][m];
           }
            i=i+k;
    }
    return sec;
}



//function to delete a key from bst
secondry delete(secondry sec,int key)
{
   int i=0,j=0,k=0,n=0;
   k=search(sec,key);
   j=k/40;
   i=k%40;
   int array[t];
    for(int n=0;n<t;n++)
    {//store the row in which key is present in array
        array[n]=sec.secondary[j][n];
    }
int left_child_j=(2*k+1)/40;
int left_child_i=(2*k+1)%40;
int right_child_j=(2*k+2)/40;
int right_child_i=(2*k+2)%40;
int array_leftchild[t];
    for(int n=0;n<t;n++)
    {//store the row in which left child is present in array_leftchild
        array_leftchild[n]=sec.secondary[left_child_j][n];
    }
    int array_rightchild[t];
    for(int n=0;n<t;n++)
    {//store the row in which right child is present in array_rightchild
        array_rightchild[n]=sec.secondary[right_child_j][n];
    }
//if no child,then delete it
    if(array_leftchild[left_child_i]==0&&array_rightchild[right_child_i]==0)
    {
        array[i]=0;
        for(int n=0;n<t;n++)
    {//update bst
        sec.secondary[j][n]=array[n];
    }
    }//if only rightchild is present
    else if(array_leftchild[left_child_i]==0&&array_rightchild[right_child_i]!=0)
    {
        sec=onechild(sec,array_rightchild[right_child_i],2*k+2,k);
    }//if only leftchild is present
    else if(array_leftchild[left_child_i]!=0&&array_rightchild[right_child_i]==0)
    {
        sec=onechild(sec,array_leftchild[left_child_i],2*k+1,k);
    }//if two children exist
    else if(array_leftchild[left_child_i]!=0&&array_rightchild[right_child_i]!=0)
    {
       sec=inorder_successor(sec,array_rightchild[right_child_i]);
    }

    printf("deleted %d\n",key);
return sec;

}

