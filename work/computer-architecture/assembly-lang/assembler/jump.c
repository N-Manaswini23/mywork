#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
#include"jump.h"

char* jmp(char* mips,char source_file[50])
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *constant=strtok(NULL," ");
   func="000010";
   if(isnumber(constant)==1)
   {
     constant=dec_to_binary(constant,26);
   }
   else
   {constant=addstring(constant,":");
     constant=getaddress(source_file,constant);
     constant=dec_to_binary(constant,26);
     //address in j contains address(constant)/4 ,but getaddress(constant)=address(constant)/4
   }
   
   func=addstring(func,constant);
  return func;
}


char* jal(char* mips,char source_file[50])
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *constant=strtok(NULL," ");
   func="000011";
   if(isnumber(constant)==1)
   {
     constant=dec_to_binary(constant,26);
   }
   else
   { constant=addstring(constant,":");
     constant=getaddress(source_file,constant);
     constant=dec_to_binary(constant,26);
     //address in jal contains address(constant)/4 ,but getaddress(constant)=address(constant)/4
   }
   
   func=addstring(func,constant);
  return func;
}

char* jr(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rs=strtok(NULL," ");
  char* op="000000";
   func="001000";
   rs=register_to_binary(rs);
   op=addstring(op,rs);
   op=addstring(op,"000000000000000");
   op=addstring(op,func);
  return op;
}