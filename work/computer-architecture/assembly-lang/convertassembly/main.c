#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_LINES 100
#include"get_format.h"
#include"rformat.h"
#include"jformat.h"
#include"lformat.h"
#include"header.h"
//gcc -o main main.c get_format.c header.c rformat.c jformat.c lformat.c

   
//enter the above command to run the code
int main() {

FILE *file;
printf("enter file name(convert from binary to mips)\n");
char* data =(char*)malloc(10000*sizeof(char));
char prog[MAX_LINES][100];
//open file in read mode
char file_name[20];

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

  if(strcmp(file_name,"prog1bin.txt")==0)
  {
    char filename[50]="prog1asm.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog2bin.txt")==0)
  {
    char filename[50]="prog2asm.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog3bin.txt")==0)
  {
    char filename[50]="prog3asm.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog4bin.txt")==0)
  {
    char filename[50]="prog4asm.txt";
     analyze_format(mips,filename,file_name);
  }
  else if(strcmp(file_name,"prog5bin.txt")==0)
  {
    char filename[50]="prog5asm.txt";
     analyze_format(mips,filename,file_name);
  }
  printf("completed\n");


free(mips);
free(data);
return 0;
}