#include"stdio.h"
#include"stdlib.h"
#include"bst.h"
#include"btree.h"
#define t 40
//gcc -o main bst.c btree.c main.c
//bst insertion on average takes 350 units of time per each insertion
//bst search on average takes 250 units of time per each search
//bst deletion on average takes 800 units of time per deketion


//btree insertion on average takes 1000 units of time per each insertion
//bst search on average takes 1500 units of time per each search
//bst deletion on average takes 800 units of time per deketion
int main()
{
    secondry sec1;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<t;j++)
        {
            sec1.secondary[i][j]=0;
        }
    }
printf("\nBST\n");
printf("\nbst insertion\n");
  sec1=insert(sec1,17);
  sec1=insert(sec1,13);
  sec1=insert(sec1,2);
  sec1=insert(sec1,27);
  sec1=insert(sec1,48);
  sec1=insert(sec1,54);
  sec1=insert(sec1,39);
  sec1=insert(sec1,57);
  sec1=insert(sec1,60);
  sec1=insert(sec1,3);
  sec1=insert(sec1,23);
  sec1=insert(sec1,46);
  sec1=insert(sec1,16);
  sec1=insert(sec1,18);
  sec1=insert(sec1,49);
  sec1=insert(sec1,45);
  sec1=insert(sec1,33);
  sec1=insert(sec1,36);
  sec1=insert(sec1,55);
  sec1=insert(sec1,19);
  sec1=insert(sec1,47);
  sec1=insert(sec1,35);
  sec1=insert(sec1,7);
  sec1=insert(sec1,22);
  sec1=insert(sec1,4);
  sec1=insert(sec1,50);
  sec1=insert(sec1,9);
  sec1=insert(sec1,56);
  sec1=insert(sec1,37);
  sec1=insert(sec1,12);
  sec1=insert(sec1,11);
  sec1=insert(sec1,21);
  sec1=insert(sec1,31);
  sec1=insert(sec1,38);
  sec1=insert(sec1,29);
  sec1=insert(sec1,44);
  sec1=insert(sec1,8);
  sec1=insert(sec1,26);
  sec1=insert(sec1,25);
  sec1=insert(sec1,40);
  sec1=insert(sec1,6);
  sec1=insert(sec1,58);
  sec1=insert(sec1,51);
  sec1=insert(sec1,1);
  sec1=insert(sec1,15);
  sec1=insert(sec1,30);
  sec1=insert(sec1,52);
  sec1=insert(sec1,10);
  sec1=insert(sec1,28);
  sec1=insert(sec1,59);
  sec1=insert(sec1,53);
  sec1=insert(sec1,34);
  sec1=insert(sec1,43);
  sec1=insert(sec1,42);
  sec1=insert(sec1,24);
  sec1=insert(sec1,14);
  sec1=insert(sec1,32);
  sec1=insert(sec1,41);
  sec1=insert(sec1,5);
  sec1=insert(sec1,20);
printf("\nbst search\n");
int x=0;
x=search(sec1,49);
if(x!=-1){printf("49 found at index %d\n",x);}
x=search(sec1,27);
if(x!=-1){printf("27 found at index %d\n",x);}
x=search(sec1,22);
if(x!=-1){printf("22 found at index %d\n",x);}
x=search(sec1,38);
if(x!=-1){printf("38 found at index %d\n",x);}
x=search(sec1,11);
if(x!=-1){printf("11 found at index %d\n",x);}
x=search(sec1,55);
if(x!=-1){printf("55 found at index %d\n",x);}
x=search(sec1,7);
if(x!=-1){printf("7 found at index %d\n",x);}
x=search(sec1,35);
if(x!=-1){printf("35 found at index %d\n",x);}
x=search(sec1,59);
if(x!=-1){printf("59 found at index %d\n",x);}
printf("\nbst deletion\n");
sec1=delete(sec1,13);
sec1=delete(sec1,19);
sec1=delete(sec1,24);
sec1=delete(sec1,37);
sec1=delete(sec1,43);
sec1=delete(sec1,53);
sec1=delete(sec1,18);
sec1=delete(sec1,38);
sec1=delete(sec1,58);
printf("keys in bst after deletion\n");
for(int i=0;i<100;i++)
    {
        for(int j=0;j<t;j++)
        {if(sec1.secondary[i][j]!=0)
            printf("%d  ",sec1.secondary[i][j]);
        }
    }

printf("\n\nBTREE\n");
   btree tree;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<t;j++)
        {
            tree.secondary[i][j]=0;
        }
    }
printf("\nbtree insertion\n");
tree=insert_btree(tree,17);
tree=insert_btree(tree,13);
tree=insert_btree(tree,2);
tree=insert_btree(tree,27);
tree=insert_btree(tree,48);
tree=insert_btree(tree,54);
tree=insert_btree(tree,39);
tree=insert_btree(tree,57);
tree=insert_btree(tree,60);
tree=insert_btree(tree,3);
tree=insert_btree(tree,23);
tree=insert_btree(tree,46);
tree=insert_btree(tree,16);
tree=insert_btree(tree,18);
tree=insert_btree(tree,49);
tree=insert_btree(tree,45);
tree=insert_btree(tree,33);
tree=insert_btree(tree,36);
tree=insert_btree(tree,55);
tree=insert_btree(tree,19);
tree=insert_btree(tree,47);
tree=insert_btree(tree,35);
tree=insert_btree(tree,7);
tree=insert_btree(tree,22);
tree=insert_btree(tree,4);
tree=insert_btree(tree,50);
tree=insert_btree(tree,9);
tree=insert_btree(tree,56);
tree=insert_btree(tree,37);
tree=insert_btree(tree,12);
tree=insert_btree(tree,11);
tree=insert_btree(tree,21);
tree=insert_btree(tree,31);
tree=insert_btree(tree,38);
tree=insert_btree(tree,29);
tree=insert_btree(tree,44);
tree=insert_btree(tree,8);
tree=insert_btree(tree,26);
tree=insert_btree(tree,25);
tree=insert_btree(tree,40);
tree=insert_btree(tree,6);
tree=insert_btree(tree,58);
tree=insert_btree(tree,51);
tree=insert_btree(tree,1);
tree=insert_btree(tree,15);
tree=insert_btree(tree,30);
tree=insert_btree(tree,52);
tree=insert_btree(tree,10);
tree=insert_btree(tree,28);
tree=insert_btree(tree,59);
tree=insert_btree(tree,53);
tree=insert_btree(tree,34);
tree=insert_btree(tree,43);
tree=insert_btree(tree,42);
tree=insert_btree(tree,24);
tree=insert_btree(tree,14);
tree=insert_btree(tree,32);
tree=insert_btree(tree,41);
tree=insert_btree(tree,5);
tree=insert_btree(tree,20);
printf("\nbtree search\n");
x=search_btree(tree,49);
if(x!=-1){printf("49 found at %d\n",x);}
x=search_btree(tree,27);
if(x!=-1){printf("27 found at %d\n",x);}
x=search_btree(tree,22);
if(x!=-1){printf("22 found at %d\n",x);}
x=search_btree(tree,38);
if(x!=-1){printf("38 found at %d\n",x);}
x=search_btree(tree,11);
if(x!=-1){printf("11 found at %d\n",x);}
x=search_btree(tree,55);
if(x!=-1){printf("55 found at %d\n",x);}
x=search_btree(tree,7);
if(x!=-1){printf("7 found at %d\n",x);}
x=search_btree(tree,35);
if(x!=-1){printf("35 found at %d\n",x);}
x=search_btree(tree,59);
if(x!=-1){printf("59 found at %d\n",x);}
printf("\nbtree deletion\n");
tree=delete_btree(tree,13);
printf("deleted 13\n");
tree=delete_btree(tree,19);
printf("deleted 19\n");
tree=delete_btree(tree,24);
printf("deleted 24\n");
tree=delete_btree(tree,37);
printf("deleted 37\n");
tree=delete_btree(tree,43);
printf("deleted 43\n");
tree=delete_btree(tree,53);
printf("deleted 53\n");
tree=delete_btree(tree,18);
printf("deleted 18\n");
tree=delete_btree(tree,38);
printf("deleted 38\n");
tree=delete_btree(tree,58);
printf("deleted 58\n");
printf("keys in btree after deletion\n");
for(int i=0;i<100;i++)
    {
        for(int j=0;j<t;j++)
        {if(tree.secondary[i][j]!=0)
            printf("%d  ",tree.secondary[i][j]);
        }
    }
    return 0;
}