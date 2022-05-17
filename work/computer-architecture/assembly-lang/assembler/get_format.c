#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_LINES 100
#include"header.h"
#include"arithmetic.h"
#include"data_transfer.h"
#include"conditional.h"
#include"logical.h"
#include"jump.h"

void analyze_format(char** mips,char file_name[50],char source_file[50])
{
    char **output=(char**)malloc(34*MAX_LINES*sizeof(char));

 FILE *file=fopen(file_name,"w");
   if(file==NULL)
   {
       printf("unable to create file\n");
       exit(EXIT_FAILURE);
   }
   


    char function[MAX_LINES][100];
    int i=0,j=0;
  while(mips[i]!=NULL)
  { j=0;
      while(mips[i][j]!=' ')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
      if(strcmp(function[i],"addi")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
      output[i]=addi(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
     else if(strcmp(function[i],"add")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=add(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"sub")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sub(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"lw")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=lw(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }


else if(strcmp(function[i],"sw")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sw(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }


     else if(strcmp(function[i],"lh")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=lh(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }


else if(strcmp(function[i],"lhu")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=lhu(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }

      else if(strcmp(function[i],"lb")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=lb(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }

      else if(strcmp(function[i],"sh")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sh(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }

      else if(strcmp(function[i],"lbu")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=lbu(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"sb")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sb(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"ll")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=ll(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"sc")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sc(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"lui")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=lui(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }

      else if(strcmp(function[i],"and")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=and_(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"or")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=or_(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"nor")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=nor(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"andi")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=andi(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"ori")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=ori(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"sll")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sll(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"srl")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=srl(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"bne")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=bne(mips[i],source_file,i);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"beq")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=beq(mips[i],source_file,i);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"slt")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=slt(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"slti")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=slti(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"sltiu")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sltiu(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"sltu")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=sltu(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"j")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=jmp(mips[i],source_file);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"jr")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=jr(mips[i]);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }
      else if(strcmp(function[i],"jal")==0)
      {
          j=0;
      while(mips[i][j]!='\0')
      {
         
         function[i][j]=mips[i][j];
         
         j++;
      }
      function[i][j]='\0';
          output[i]=jal(mips[i],source_file);
          fprintf(file,"%s",output[i]);
          char* hex=bin_to_hex(output[i]);
          fprintf(file,"(%s,%s)\n",hex,function[i]);
      }

      



    else
    {   char* func=strtok(mips[i]," ");
         func=getaddress(source_file,func);
         int m=4*atoi(func);
         sprintf(func,"%d",m);
         func=dec_to_binary(func,16);
        fprintf(file,"%s(%s)\n",func,mips[i]);
    }
      i++;
  }
  
  fclose(file);
}