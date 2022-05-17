#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
#include"math.h"
#define MAX_LINES 100
char* bin_to_register(char* registr)
{
   
if(strcmp(registr,"00000")==0)
  {
      registr="$zero";
  }
  else if(strcmp(registr,"00010")==0)
  {
      registr="$v0";
  }
  else if(strcmp(registr,"00011")==0)
  {
      registr="$v1";
  }
  else if(strcmp(registr,"00100")==0)
  {
      registr="$a0";
  }
  else if(strcmp(registr,"00101")==0)
  {
      registr="$a1";
  }
  else if(strcmp(registr,"00110")==0)
  {
      registr="$a2";
  }
  else if(strcmp(registr,"00111")==0)
  {
      registr="$a3";
  }
  else if(strcmp(registr,"01000")==0)
  {
      registr="$t0";
  }
  else if(strcmp(registr,"01001")==0)
  {
      registr="$t1";
  }
  else if(strcmp(registr,"01010")==0)
  {
      registr="$t2";
  }
  else if(strcmp(registr,"01011")==0)
  {
      registr="$t3";
  }
  else if(strcmp(registr,"01100")==0)
  {
      registr="$t4";
  }
  else if(strcmp(registr,"01101")==0)
  {
      registr="$t5";
  }
  else if(strcmp(registr,"01110")==0)
  {
      registr="$t6";
  }
  else if(strcmp(registr,"01111")==0)
  {
      registr="$t7";
  }
  else if(strcmp(registr,"10000")==0)
  {
      registr="$s0";
  }
  else if(strcmp(registr,"10001")==0)
  {
      registr="$s1";
  }
  else if(strcmp(registr,"10010")==0)
  {
      registr="$s2";
  }
  else if(strcmp(registr,"10011")==0)
  {
      registr="$s3";
  }
  else if(strcmp(registr,"10100")==0)
  {
      registr="$s4";
  }
  else if(strcmp(registr,"10101")==0)
  {
      registr="$s5";
  }
  else if(strcmp(registr,"10110")==0)
  {
      registr="$s6";
  }
  else if(strcmp(registr,"10111")==0)
  {
      registr="$s7";
  }
  else if(strcmp(registr,"11000")==0)
  {
      registr="$t8";
  }
  else if(strcmp(registr,"11001")==0)
  {
      registr="$t9";
  }
  else if(strcmp(registr,"11100")==0)
  {
      registr="$gp";
  }
  else if(strcmp(registr,"11101")==0)
  {
      registr="$sp";
  }
  else if(strcmp(registr,"11110")==0)
  {
      registr="$fp";
  }
  else if(strcmp(registr,"11111")==0)
  {
      registr="$ra";
  }

  return registr;
}



char* create_array(char* source,int from,int to)
{
  char* destination=(char*)malloc(100*sizeof(source));
  int i=0,j=0;
  for(i=from;i<=to;i++)
  { 
     destination[j]=source[i];
     j++;
  }
  destination[j]='\0';
  return destination;
}


char* addstring(char *frst,char* scnd)
{ int i=strlen(frst);
int j=strlen(scnd);
char* new_str=(char*)malloc(100*sizeof(char));
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




char* binary_to_dec(char* binary)
{
    char* decimal=(char*)malloc(sizeof(binary));
    int i=0;
    long int dec=0;
    long int m=0;
    for(i=0;i<strlen(binary);i++)
    {
        if(binary[i]=='1')
        {
            m=(long int)pow(2,strlen(binary)-1-i);
           
        }
        else{
            m=0;
        }
        dec=dec+m;
        
        
    }
    sprintf(decimal,"%ld",dec);
    return decimal;

}



char* binary_to_dec_signed(char* binary)
{
    char* decimal=(char*)malloc(sizeof(binary));
    int i=0;
    long int dec=0;
    long int m=0;
    for(i=1;i<strlen(binary);i++)
    {
        if(binary[i]=='1')
        {
            m=(long int)pow(2,strlen(binary)-1-i);
           
        }
        else{
            m=0;
        }
        dec=dec+m;
        
        
    }
    if(binary[0]=='1')
    {
       m=(long int)pow(2,strlen(binary)-1);
       dec=dec-m;
    }
    sprintf(decimal,"%ld",dec);
    return decimal;

}



char* getaddress(char source_file[50],char* line)
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
       if(strcmp(data,line)==0)
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


char* dec_to_hex(char* decimal)
{
    char* hex=(char*)malloc(32*sizeof(char));
    char* hexadecimal=(char*)malloc(32*sizeof(char));
    int j=0;
    int dec=atoi(decimal);
    if(dec==0)
    {
        hex[j]='0';
        j++;
    }
    else{
    while(dec!=0)
    {
       int remainder=dec%16;
       if(remainder<10)
       {
           hex[j]=48+remainder;
       }
       else{
           hex[j]=55+remainder;
       }
       dec=dec/16;
       j++;
    }
    }

    hex[j]='X';
    hex[j+1]='0';
    int k=0;
    for(int i=j+1;i>=0;i--)
    {
       hexadecimal[k]=hex[i];
       k++;
    }
    hexadecimal[k]='\0';
    return hexadecimal;
}