#include"stdio.h"
#include"stdlib.h"
#include"btree.h"
#define t 40
//returns number of keys present in node(of given key)
int number_of_keys(btree tree,int key)
{
    int j=key/5;
    int k=5*j;
    int n=0;
    int array[t];
    //read disk-10
    for(int m=0;m<t;m++)
    {
        array[m]=tree.secondary[k/t][m];
    }//break while loop when empty key is found
    while(k<=5*j+3)
    {
    //accessing array element-1
        if(array[k%t]==0)
        {
            break;
        }
        else
        {
          k++;
          n++;
        }
    }
    return n;

}
//returns 0 if given key is not leaf ,returns 1 if given key is leaf
int isleaf(btree tree,int key)
{
  int i=5*(key+1);
  int j=5*(key+2);
   int array1[t],array2[t];
   //readdisk-10
   for(int m=0;m<t;m++)
    {
        array1[m]=tree.secondary[i/t][m];
    }
    //readdisk-10
    for(int m=0;m<t;m++)
    {
        array2[m]=tree.secondary[j/t][m];
    }//accessing array element-1
    //given element isleaf if its left and right pointers are empty
    if(array1[i%t]==0&&array2[j%t]==0)
    {
        return 1;
    }
    return 0;
}
//return the index that given key should go to while inserting
int decide_path(btree tree,int key)
{
   int i=0,n=0,k=0;
   int array[t];
   //readdisk-10
   for(int m=0;m<t;m++)
    {
        array[m]=tree.secondary[0][m];
    }
    while(isleaf(tree,i)==0)
    {

      int j=number_of_keys(tree,i);
      for(int n=1;n<=j;n++)
      {
      //accessing array element-1
          if(key==array[i%t])
          {//if element is already present return -1
              printf("already inserted\n");
              return -1;
          }
          //find place in preceding child
         if(key<array[i%t])
         {
             i=5*(i+1);
             break;
         }//find place in succeding child
         else if(n==j)
         {
             i=5*(i+2);
         }  //go to next key of node
         else
         {
             i=i+1;
         } 
         

      }//readdisk-10
      for(int m=0;m<t;m++)
    {
        array[m]=tree.secondary[i/t][m];
    }
    }
    //readdisk-10
    for(int m=0;m<t;m++)
    {
        array[m]=tree.secondary[i/t][m];
    }
     int j=number_of_keys(tree,i);
     for(int n=1;n<=j;n++)
      {//accessing array element-1
        if(key>array[i%t])
         {
             i=i+1;
         }
         else if(key==array[i%t])
          {
              printf("already inserted\n");
              return -1;
          }
         else
         {
             break;
         }
      }

    return i;
}
//searches for an element in btree and returns the index at which it is present.
//if element is not present returns -1

int search_btree(btree tree,int key)
{
   int i=0,n=0,k=0;
   int array[t];
   //readdisk-10
   for(int m=0;m<t;m++)
    {
        array[m]=tree.secondary[0][m];
    }
    while(isleaf(tree,i)==0)
    {

      int j=number_of_keys(tree,i);
      for(int n=1;n<=j;n++)
      {//accessing array element-1
          if(key==array[i%t])
          {
              return i;
          }
          
         if(key<array[i%t])
         {//search in preceding child
             i=5*(i+1);
             break;
         }
         else if(n==j)
         {//search in succeding child
             i=5*(i+2);
         }  
         else
         {//search in next key of node
             i=i+1;
         } 

      }
      //readdisk-10
      for(int m=0;m<t;m++)
    {
        array[m]=tree.secondary[i/t][m];
    }
    }//readdisk-10
    for(int m=0;m<t;m++)
    {
        array[m]=tree.secondary[i/t][m];
    }
     int j=number_of_keys(tree,i);
     for(int n=1;n<=j;n++)
      {//accessing array element-1
        if(key>array[i%t])
         {
             i=i+1;
         }
         else if(key==array[i%t])
          {
              return i;
          }
         else
         {
             printf("no such element %d\n",key);
             return -1;
         }
      }
      return -1;
}

//inserts new element into the index returned by function decide_path.
//if number of keys exceed 3,splits the node
btree insert_btree(btree tree,int key)
{
    int i=0,j=0,k=0;
    int array[t];
    int status=0;
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array[n]=tree.secondary[0][n];
    }
    if(array[0]==0)
    {
        array[0]=key;
        //writedisk-10
         for(int n=0;n<t;n++)
    {
        tree.secondary[0][n]=array[n];
    }
    return tree;
    }//path contains index at which giveen element is to be inserted
    int path=decide_path(tree,key);
    if(path==-1){return tree;}
    i=path/5;
    j=5*i;
    k=number_of_keys(tree,j);
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array[n]=tree.secondary[path/t][n];
    }
    array[(5*i+k)%t]=key;//insert the given element and push keys after inserted index one step backward
    for(int n=(5*i+k)%t;n>path%t;n--)
    {
      int x=array[n];
      int y=array[n-1];
      array[n]=y;
      array[n-1]=x;
    }
    //writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[path/t][n]=array[n];
    }//if number of keys in node exceed 3 ,split node
    if(number_of_keys(tree,path)>=4)
    {
        tree=split_node(tree,path);
    }
    
    printf("inserted %d\n",key);
    return tree;
}
//shifts given node from given from position to given to positions
//recursively shifts children of given node
btree shift_node(btree tree,int from,int to)
{
    int i=0,j=0,k=0;
    int array1[t],array2[t];
    int status=0;
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[from/t][n];
    }
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array2[n]=tree.secondary[to/t][n];
    }//move given element to final position
    array2[to%t]=array1[from%t];
    array1[from%t]=0;
    if(from/t==to/t)
    {//accessing array element-1
        array1[to%t]=array2[to%t];
        array2[from%t]=array1[from%t];
    }
    for(int n=0;n<t;n++)
    {
        tree.secondary[from/t][n]=array1[n];
    }
    //writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[to/t][n]=array2[n];
    }//move children to new position
    if(isleaf(tree,from)==0)
    {
        if(to%5==0)
        {
    for(int n=0;n<4;n++)
    {
        tree=shift_node(tree,5*(from+1)+n,5*(to+1)+n);
    }
        }
    for(int n=0;n<4;n++)
    {
        tree=shift_node(tree,5*(from+2)+n,5*(to+2)+n);
    }
    }
    return tree;

}
//split given node
btree split_node(btree tree,int key)
{
   int j=key/5;
   int k=5*j+1;
   int i=j-1;
   if(i==-1)
   {
       return split_root(tree);
   }

    int array1[t],array2[t];
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[key/t][n];
    }
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array2[n]=tree.secondary[i/t][n];
    }
    int x=number_of_keys(tree,i);
    int y=i/5;
    int z=5*y;//shift mid element to parent and push element after inserted index by one
    for(int n=z+x-1;n>=i;n--)
    {
      tree=shift_node(tree,n,n+1);
    }//shift children
    for(int n=3;n>=2;n--)
    {
      tree=shift_node(tree,5*(i+1)+n,5*(i+2)+n-2);
    }
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[key/t][n];
    }//readdisk-10
    for(int n=0;n<t;n++)
    {
        array2[n]=tree.secondary[i/t][n];
    }
    array2[i%t]=array1[k%t];
    array1[k%t]=0;
    if(i/t==key/t)
    {
        array1[i%t]=array2[i%t];
        array2[k%t]=0;
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[key/t][n]=array1[n];
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[i/t][n]=array2[n];
    }
    if(number_of_keys(tree,i)>=4)
    {
        tree=split_node(tree,i);
    }

  return tree;
}

//used when splitting root,shifts given node.
btree shift_root(btree tree,btree new_btree,int from,int to)
{
    int i=0,j=0,k=0;
    int array1[t],array2[t];
    int status=0;
    //readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[from/t][n];
    }//readisk-10
    for(int n=0;n<t;n++)
    {
        array2[n]=new_btree.secondary[to/t][n];
    }//accessing array element-1
    array2[to%t]=array1[from%t];
    for(int n=0;n<t;n++)//writedisk-10
    {
        new_btree.secondary[to/t][n]=array2[n];
    }//shift children
    if(isleaf(tree,from)==0)
    {
    for(int n=0;n<4;n++)
    {
        new_btree=shift_root(tree,new_btree,5*(from+1)+n,5*(to+1)+n);
    }
    for(int n=0;n<4;n++)
    {
        new_btree=shift_root(tree,new_btree,5*(from+2)+n,5*(to+2)+n);
    }
    }
    return new_btree;
}

//used when splitting root.mid elem is made root,remaining are made  children
btree split_root(btree tree)
{
     btree new_btree;
    for(int i=0;i<100;i++)//new btree.writebtree-10*100=1000
    {
        for(int j=0;j<t;j++)
        {
            new_btree.secondary[i][j]=0;
        }
    }
     int i=0,j=0,k=0;
    int array1[t],array2[t];
    int status=0;//readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=new_btree.secondary[0][n];
    }
    for(int n=0;n<t;n++)//readdisk-10
    {
        array2[n]=tree.secondary[0][n];
    }//make mid element root of btree
    array1[0]=array2[1];//accessing array element-1
    for(int n=0;n<t;n++)//writedisk-10
    {
        new_btree.secondary[0][n]=array1[n];
    }//shift remaining nodes as preceding and suceeding children
    new_btree=shift_root(tree,new_btree,0,5);
    new_btree=shift_root(tree,new_btree,2,10);
    new_btree=shift_root(tree,new_btree,3,11);
  return new_btree;
}
//find successor of given element
int successor(btree tree,int key)
{
    int k=search_btree(tree,key);//search in succeding child
  int i=5*(k+2);
    int array1[t];
    int status=0;//readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[i/t][n];
    }
    while(isleaf(tree,i)==0)//continue to search the leftmost of right subtree until leaf is found
    {
      i=5*(i+1);//writedisk-10
      for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[i/t][n];
    }
    }//accessing array element-1
    return array1[i%t];
}//find successor of given element
int predecessor(btree tree,int key)
{
    int k=search_btree(tree,key);//search in preceding child
  int i=5*(k+1);
  int x=number_of_keys(tree,i);
  i=i+x-1;
    int array1[t];
    int status=0;//readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[i/t][n];
    }
    while(isleaf(tree,i)==0)//continue to search the rightmost of left subtree until leaf is found
    {
      i=5*(i+2);
      int j=number_of_keys(tree,i);
      i=i+j-1;//readdisk-10
      for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[i/t][n];
    }
    }//accessing array element-1
    return array1[i%t];
}
//merges given node with its children
btree merge_node(btree tree,int key)
{
  int k=number_of_keys(tree,key);
  if(k>1)
  { int i=(5*(key+2)+1);
      tree=shift_node(tree,5*(key+2),5*(key+2)+2);
      tree=shift_node(tree,5*(5*(key+2)+1),5*(5*(key+2)+2+1));
      int array1[t],array2[t];
    for(int n=0;n<t;n++)//readdisk-10
    {
        array1[n]=tree.secondary[key/t][n];
    }
    for(int n=0;n<t;n++)//readdisk-10
    {
        array2[n]=tree.secondary[i/t][n];
    }
    //accessing array element-1
    array2[i%t]=array1[key%t];
    array1[key%t]=0;
    if(i/t==key/t)
    {//accessing array element-1
        array2[key%t]=0;
        array1[i%t]=array2[i%t];
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[key/t][n]=array1[n];
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[i/t][n]=array2[n];
    }
    tree=shift_node(tree,5*(key+1),5*(key+2));
    for(int n=1;n<k;n++)
    {
        tree=shift_node(tree,key+n,key+n-1);
    }
  }

  else if(k==1)
  {
      tree=shift_node(tree,key,key+1);
      tree=shift_node(tree,5*(key+1),key);
      tree=shift_node(tree,5*(key+3),key+2);
  }
  return tree;
}
//case1a leaf deletion
btree delete1a(btree tree,int key)
{
    int i=search_btree(tree,key);
    int j=i/5;
    int k=number_of_keys(tree,i);
    int array1[t];
    int status=0;//readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[i/t][n];
    }
    array1[i%t]=0;//readdisk-10
    for(int n=i;n<5*j+k;n++)
    {
        array1[n%t]=array1[(n+1)%t];//push elements after deleted elements one step forward
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[i/t][n]=array1[n];
    }
    return tree;
}//case 2a-if element to be deleted is in internal node and preceding child has atleast 2 elements
btree delete2a(btree tree,int key)
{//find predecessor ,delete predecessor,replace key element by predecessor
  int i=search_btree(tree,key);
  int j=predecessor(tree,key);
  tree=delete_btree(tree,j);
  int array1[t];//readdisk-10
    for(int n=0;n<t;n++)
    {
        array1[n]=tree.secondary[i/t][n];
    }
    array1[i%t]=j;
    for(int n=0;n<t;n++)//writedisk-10
    {
        tree.secondary[i/t][n]=array1[n];
    }

return tree;
}
//case 2b-if element to be deleted is in internal node and succeding child has atleast 2 elements
btree delete2b(btree tree,int key)
{//find successor ,delete successor,replace key element by successor
  int i=search_btree(tree,key);
  int j=successor(tree,key);
  tree=delete_btree(tree,j);
  int array1[t];
    for(int n=0;n<t;n++)//readdisk-10
    {
        array1[n]=tree.secondary[i/t][n];
    }
    array1[i%t]=j;
    for(int n=0;n<t;n++)//writedisk-10
    {
        tree.secondary[i/t][n]=array1[n];
    }
return tree;
}//case 2c-if element to be deleted is in internal node and both children have only one element
btree delete2c(btree tree,int key)
{//merge node with two children
  int i=search_btree(tree,key);
  tree=merge_node(tree,i);
  tree=delete_btree(tree,key);
  return tree;
}
//3a-if one sibling has atleast 2 elements
btree delete3a(btree tree,int key)
{//give one element from parent to deleted place and shift one element from immediate sibling to parent
    int i=key;
    int k=number_of_keys(tree,5*(i+2));
   int array1[t],array2[t],array3[t];
    for(int n=0;n<t;n++)//readdisk-10
    {
        array1[n]=tree.secondary[i/t][n];
    }
    for(int n=0;n<t;n++)//readdisk-10
    {
        array2[n]=tree.secondary[5*(i+1)/t][n];
    }
    for(int n=0;n<t;n++)//readdisk-10
    {
        array3[n]=tree.secondary[5*(i+2)/t][n];
    }//accessing array element-1
    array2[5*(i+1)%t]=array1[i%t];
    array1[i%t]=array3[5*(i+2)%t];
    array3[5*(i+2)%t]=0;
    if(i/t==5*(i+1)/t)
    {//accessing array element-1
        array1[5*(i+1)%t]=array2[5*(i+1)%t];
        array2[i%t]=array1[i%t];
    }
    if(5*(i+2)/t==5*(i+1)/t)
    {//accessing array element-1
        array2[5*(i+2)%t]=0;
        array3[5*(i+1)%t]=array2[5*(i+1)%t];
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[i/t][n]=array1[n];
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[5*(i+1)/t][n]=array2[n];
    }//writedisk-10
    for(int n=0;n<t;n++)
    {
        tree.secondary[5*(i+2)/t][n]=array3[n];
    }
    for(int n=1;n<k;n++)
    {
       tree=shift_node(tree,5*(i+2)+n,5*(i+2)+n-1);
    }
    return tree;
}
//3a-if no sibling has atleast 2 elements
btree delete3b(btree tree,int key)
{//merge one sibling ,given node with root
  int i=key;
  int k=number_of_keys(tree,i);
  if(k>1)
  {
     tree=merge_node(tree,i);
  }
  else if(k==1)
  {
      
    int j=i/5;
    if(number_of_keys(tree,5*(j+1))==1)
    {
        tree=merge_node(tree,j-1);
    }
    else if(number_of_keys(tree,5*(j-1))==1)
    {
        tree=merge_node(tree,j-2);
    }
      
  }
 
  return tree;
}

btree delete_btree(btree tree,int key)
{
    int i=search_btree(tree,key);
    int k=number_of_keys(tree,i);
    int j=i/5;
    if(isleaf(tree,i)==1&&k>1)
    {
        tree=delete1a(tree,key);
    }
    else if(isleaf(tree,i)==0 && number_of_keys(tree,5*(i+1))>1)
    {
        tree=delete2a(tree,key);
    }
    else if(isleaf(tree,i)==0 && number_of_keys(tree,5*(i+2))>1)
    {
        tree=delete2b(tree,key);
    }
    else if(isleaf(tree,i)==0 && number_of_keys(tree,5*(i+1))<2&&number_of_keys(tree,5*(i+2))<2)
    {
        tree=delete2c(tree,key);
    }
    else if(isleaf(tree,i)==1&&k==1&&number_of_keys(tree,5*(j-1))>1)
    {
        tree=delete3a(tree,j-2);
    }
    else if(isleaf(tree,i)==1&&k==1&&number_of_keys(tree,5*(j+1))>1)
    {
        tree=delete3a(tree,j-1);
    }
    else if(isleaf(tree,i)==1&&k==1&&number_of_keys(tree,5*(j+1))<2&&number_of_keys(tree,5*(j-1))<2)
    {
        if((j-2)%5<3)
        {
          tree=delete3b(tree,j-2);
          tree=delete_btree(tree,key);
        }
        else if((j-1)%5<3)
        {
            tree=delete3b(tree,j-1);
            tree=delete_btree(tree,key);
        }
    }
    return tree;
}