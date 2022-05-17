#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//#define MAX_LINES 100
#include"header.h"

#include"arithmetic.h"
//function to convert add function from  mips to binary
char* add(char* mips)
{ char* data=mips;
char* func=NULL;
//obtain rd,rs,rt,op using strtok
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL," ");
   //opcode of r-format and function code are assigned
   char* op="000000";
   func="100000";
   //convert rd,rs,rt registers to binary
   rd=register_to_binary(rd);
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   //join all strings to obtain final binary code
   op=addstring(op,rs);
   op=addstring(op,rt);
   op=addstring(op,rd);
   op=addstring(op,"00000");
   op=addstring(op,func);
  return op;
}


//function to convert sub function from  mips to binary

char* sub(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL," ");
   char* op="000000";
   func="100010";
   rd=register_to_binary(rd);
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   op=addstring(op,rs);
   op=addstring(op,rt);
   op=addstring(op,rd);
   op=addstring(op,"00000");
   op=addstring(op,func);
  return op;
}

//function to convert addi function from  mips to binary

char* addi(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *constant=strtok(NULL," ");
   func="001000";
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   func=addstring(func,rs);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}

