#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_LINES 100
#include"get_format.h"
#include"header.h"
#include"arithmetic.h"
#include"data_transfer.h"
#include"logical.h"
#include"jump.h"
//gcc -o main main.c header.c data_transfer.c arithmetic.c logical.c get_format.c conditional.c jump.c

   
//enter the above command to run the code
int main() {

FILE *file;
printf("enter file name(convert from mips to binary)\n");
char* data =(char*)malloc(10000*sizeof(char));
char prog[MAX_LINES][100];
//open file in read mode
char file_name[50];

scanf("%[^\n]%*c",file_name);

file=fopen(file_name,"r");
if(file==NULL)
{
  printf("failed to open file");
  return 1;
}
int i=0;
   //read from file and store it in data
   while(fgets(prog[i],MAX_LINES*100,file)!=NULL)
   {
       prog[i][strlen(prog[i])-1]='\0';
       i++;
   }
   char **mips=(char**)malloc(sizeof(prog));
   for(int k=0;k<i;k++)
   {
     mips[k]=prog[k];
   }
  if(strcmp(file_name,"prog1.asm")==0)
  {
    char filename[50]="prog1bin.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog2.asm")==0)
  {
    char filename[50]="prog2bin.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog3.asm")==0)
  {
    char filename[50]="prog3bin.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog4.asm")==0)
  {
    char filename[50]="prog4bin.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog5.asm")==0)
  {
    char filename[50]="prog5bin.txt";
     analyze_format(mips,filename,file_name);
  }

printf("completed\n");
free(mips);
free(data);
return 0;
}