#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"rformat.h"
#include"jformat.h"
#include "header.h"
#include"lformat.h"


#include"get_format.h"
#define MAX_LINES 100

void analyze_format(char **mips,char file_name[50],char source_file[50])
{ int i=0;
char** function=(char**)malloc(100*sizeof(mips));
FILE *file=fopen(file_name,"w");
   if(file==NULL)
   {
       printf("unable to create file\n");
       exit(EXIT_FAILURE);
   }
  while(mips[i]!=NULL)
 {
  if(strlen(mips[i])<32)
    {
      
      int address=4*i;
      sprintf(mips[i],"%d",address);
      mips[i]=dec_to_hex(mips[i]);
      mips[i]=addstring(mips[i],":");
      fprintf(file,"%s\n",mips[i]);
    }

  else if(strcmp(create_array(mips[i],0,5),"000000")==0)
  {
      if(strcmp(create_array(mips[i],26,31),"100000")==0)
      {
        mips[i]=add(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"100010")==0)
      {
        mips[i]=sub(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"100100")==0)
      {
        mips[i]=and(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"100101")==0)
      {
        mips[i]=or(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"100111")==0)
      {
        mips[i]=nor(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"101010")==0)
      {
        mips[i]=slt(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"101011")==0)
      {
        mips[i]=sltu(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"000000")==0)
      {
        mips[i]=sll(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"000010")==0)
      {
        mips[i]=srl(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      if(strcmp(create_array(mips[i],26,31),"001000")==0)
      {
        mips[i]=jr(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
     
  }


     else if(strcmp(create_array(mips[i],0,5),"000010")==0)
      {
        mips[i]=jump(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"000011")==0)
      {
        mips[i]=jal(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }

     else if(strcmp(create_array(mips[i],0,5),"001000")==0)
      {
        mips[i]=addi(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }

      else if(strcmp(create_array(mips[i],0,5),"100011")==0)
      {
        mips[i]=lw(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"101011")==0)
      {
        mips[i]=sw(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"101001")==0)
      {
        mips[i]=sh(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"100001")==0)
      {
        mips[i]=lh(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"100101")==0)
      {
        mips[i]=lhu(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"100000")==0)
      {
        mips[i]=lb(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"100100")==0)
      {
        mips[i]=lbu(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"101000")==0)
      {
        mips[i]=sb(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"001100")==0)
      {
        mips[i]=andi(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"001101")==0)
      {
        mips[i]=ori(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"110000")==0)
      {
        mips[i]=ll(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"111000")==0)
      {
        mips[i]=sc(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"001111")==0)
      {
        mips[i]=lui(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"000101")==0)
      {
        mips[i]=bne(mips[i],source_file,i);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"000100")==0)
      {
        mips[i]=beq(mips[i],source_file,i);
        fprintf(file,"%s\n",mips[i]);
      }
      else if(strcmp(create_array(mips[i],0,5),"001010")==0)
      {
        mips[i]=slti(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
     else if(strcmp(create_array(mips[i],0,5),"001011")==0)
      {
        mips[i]=sltiu(mips[i]);
        fprintf(file,"%s\n",mips[i]);
      }
      else{
        printf("wrong code at line %d",i+1);
      }


    i++;
 }
 fclose(file);
}