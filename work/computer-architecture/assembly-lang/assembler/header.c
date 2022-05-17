#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
#define MAX_LINES 100
char* dec_to_binary(char *integer,int no_of_bits)
{
    int intgr=atoi(integer);
    char* binary=(char*)malloc(100*sizeof(char));
    int k=0;
    for(int i=no_of_bits-1;i>=0;i--)
    {
        int j=intgr>>i;
        if((j & 1)==1)
        {
            binary[k]='1';
        }
        else
        {
            binary[k]='0';
        }
        k++;
    }
    binary[k]='\0';
    return binary;
}






char* addstring(char *frst,char* scnd)
{ int i=strlen(frst);
int j=strlen(scnd);
char* new_str=(char*)malloc(33*sizeof(char));
int k=0;
    while (k<i)
    {
        new_str[k]=frst[k];
        k++;
    }
    k=0;
    while (k<j)
    {
        new_str[i+k]=scnd[k];
        k++;
    }
    new_str[i+j]='\0';
    return new_str;
}





char* register_to_binary(char* registr)
{
  if(strcmp(registr,"$zero")==0)
  {
      registr="00000";
  }
  else if(strcmp(registr,"$v0")==0)
  {
      registr="00010";
  }
  else if(strcmp(registr,"$v1")==0)
  {
      registr="00011";
  }
  else if(strcmp(registr,"$a0")==0)
  {
      registr="00100";
  }
  else if(strcmp(registr,"$a1")==0)
  {
      registr="00101";
  }
  else if(strcmp(registr,"$a2")==0)
  {
      registr="00110";
  }
  else if(strcmp(registr,"$a3")==0)
  {
      registr="00111";
  }
  else if(strcmp(registr,"$t0")==0)
  {
      registr="01000";
  }
  else if(strcmp(registr,"$t1")==0)
  {
      registr="01001";
  }
  else if(strcmp(registr,"$t2")==0)
  {
      registr="01010";
  }
  else if(strcmp(registr,"$t3")==0)
  {
      registr="01011";
  }
  else if(strcmp(registr,"$t4")==0)
  {
      registr="01100";
  }
  else if(strcmp(registr,"$t5")==0)
  {
      registr="01101";
  }
  else if(strcmp(registr,"$t6")==0)
  {
      registr="01110";
  }
  else if(strcmp(registr,"$t7")==0)
  {
      registr="01111";
  }
  else if(strcmp(registr,"$s0")==0)
  {
      registr="10000";
  }
  else if(strcmp(registr,"$s1")==0)
  {
      registr="10001";
  }
  else if(strcmp(registr,"$s2")==0)
  {
      registr="10010";
  }
  else if(strcmp(registr,"$s3")==0)
  {
      registr="10011";
  }
  else if(strcmp(registr,"$s4")==0)
  {
      registr="10100";
  }
  else if(strcmp(registr,"$s5")==0)
  {
      registr="10101";
  }
  else if(strcmp(registr,"$s6")==0)
  {
      registr="10110";
  }
  else if(strcmp(registr,"$s7")==0)
  {
      registr="10111";
  }
  else if(strcmp(registr,"$t8")==0)
  {
      registr="11000";
  }
  else if(strcmp(registr,"$t9")==0)
  {
      registr="11001";
  }
  else if(strcmp(registr,"$gp")==0)
  {
      registr="11100";
  }
  else if(strcmp(registr,"$sp")==0)
  {
      registr="11101";
  }
  else if(strcmp(registr,"$fp")==0)
  {
      registr="11110";
  }
  else if(strcmp(registr,"$ra")==0)
  {
      registr="11111";
  }

  return registr;
}

char hexadecimal(char* binary)
{
    char c;
    if(strcmp(binary,"0000")==0)
    {
       c='0';
    }
    else if(strcmp(binary,"0001")==0)
    {
       c='1';
    }
    else if(strcmp(binary,"0010")==0)
    {
       c='2';
    }
    else if(strcmp(binary,"0011")==0)
    {
       c='3';
    }
    else if(strcmp(binary,"0100")==0)
    {
       c='4';
    }
    else if(strcmp(binary,"0101")==0)
    {
       c='5';
    }
    else if(strcmp(binary,"0110")==0)
    {
       c='6';
    }
    else if(strcmp(binary,"0111")==0)
    {
       c='7';
    }
    else if(strcmp(binary,"1000")==0)
    {
       c='8';
    }
    else if(strcmp(binary,"1001")==0)
    {
       c='9';
    }
    else if(strcmp(binary,"1010")==0)
    {
       c='A';
    }
    else if(strcmp(binary,"1011")==0)
    {
       c='B';
    }
    else if(strcmp(binary,"1100")==0)
    {
       c='C';
    }
    else if(strcmp(binary,"1101")==0)
    {
       c='D';
    }
    else if(strcmp(binary,"1110")==0)
    {
       c='E';
    }
    else if(strcmp(binary,"1111")==0)
    {
       c='F';
    }
    return c;
}


char* bin_to_hex(char* binary)
{
    char* bin=(char*)malloc(5*sizeof(char));
    char* hex=(char*)malloc(9*sizeof(char));
    int n=0;
   for(int i=0;i<32;i=i+4)
   {int k=0;
       for(int j=i;j<i+4;j++)
       { 
          bin[k]=binary[j];
          k++;
       }
       bin[k]='\0';
       hex[n]=hexadecimal(bin);
       n++;
   }
   hex[n]='\0';
   
   return hex;

}

char* getaddress(char source_file[50],char* function)
{
    FILE *file;
    char* data=(char*)malloc(100*sizeof(char));
file=fopen(source_file,"r");
if(file==NULL)
{
  printf("failed to open file");
  return NULL;
}
int i=0;
   //read from file and store it in data
   while(fgets(data,MAX_LINES*100,file)!=NULL)
   {
       data[strlen(data)-1]='\0';
       if(strcmp(data,function)==0)
       {
          break;
       }
       i++;
   }
   //actual address is 4*i,but dividing it by four and the converting it to string because j,jal contain address/4 in binary code.
   int m=i;
   char* address=(char*)malloc(100*sizeof(char));
   sprintf(address,"%d",m);
   return address;
}

int isnumber(char* str)
{
   int i=0;
   for(i=0;i<strlen(str);i++)
   {
       if(!isdigit(str[i]))
       {
           return 0;
       }
   }
   return 1;
}