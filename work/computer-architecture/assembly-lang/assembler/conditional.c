#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
#include"conditional.h"


//function to convert beq function from  mips to binary

char* beq(char* mips,char source_file[50],int address)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   //obtain constant,rs,rt using strtok
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL," ");
   data=mips;
   func="000100";
   //convert rs,rt registers to binary
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   func=addstring(func,rs);
   func=addstring(func,rt);
   if(isnumber(constant)==1)
   {//if it is number convert it into binary number of 16 bits
     constant=dec_to_binary(constant,16);
   }
   else
   {constant=addstring(constant,":");
     constant=getaddress(source_file,constant);
     int dec=atoi(constant);
     int offset=dec-address;
     sprintf(constant,"%d",offset);
     constant=dec_to_binary(constant,16);
    //target address=pc+4+4*address(constant)

   }
   //join all strings to obtain final binary code
   func=addstring(func,constant);
  return func;
}




//function to convert bne function from  mips to binary

char* bne(char* mips,char source_file[50],int address)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL," ");
   data=mips;
   func="000101";
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   func=addstring(func,rs);
   func=addstring(func,rt);
   if(isnumber(constant)==1)
   {
     constant=dec_to_binary(constant,16);
   }
   else
   {constant=addstring(constant,":");
     constant=getaddress(source_file,constant);
     int dec=atoi(constant);
     int offset=dec-address;
     sprintf(constant,"%d",offset);
     constant=dec_to_binary(constant,16);
     //target address=pc+4+4*address(constant)

   }
   func=addstring(func,constant);
  return func;
}


//function to convert slt function from  mips to binary
char* slt(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL," ");
   char* op="000000";
   func="101010";
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
//function to convert sltu function from  mips to binary

char* sltu(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL," ");
   char* op="000000";
   func="101011";
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


//function to convert slti function from  mips to binary

char* slti(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *constant=strtok(NULL," ");
   func="001010";
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   func=addstring(func,rs);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}


//function to convert sltiu function from  mips to binary

char* sltiu(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *constant=strtok(NULL," ");
   func="001011";
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   func=addstring(func,rs);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}