#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
#include "logical.h"



char* and_(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL," ");
   char* op="000000";
   func="100100";
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



char* or_(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL," ");
   char* op="000000";
   func="100101";
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


char* nor(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *rt=strtok(NULL," ");
   char* op="000000";
   func="100111";
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

char* andi(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *constant=strtok(NULL," ");
   func="001100";
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   func=addstring(func,rs);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}



char* ori(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *rs=strtok(NULL,",");
   char *constant=strtok(NULL," ");
   func="001101";
   rt=register_to_binary(rt);
   rs=register_to_binary(rs);
   func=addstring(func,rs);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}

char* sll(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rt=strtok(NULL,",");
   char *sa=strtok(NULL," ");
   char* op="000000";
   func="000000";
   rd=register_to_binary(rd);
   rt=register_to_binary(rt);
   op=addstring(op,"00000");
   op=addstring(op,rt);
   op=addstring(op,rd);
   sa=dec_to_binary(sa,5);
   op=addstring(op,sa);
   op=addstring(op,func);
  return op;
}


char* srl(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rd=strtok(NULL,",");
   char *rt=strtok(NULL,",");
   char *sa=strtok(NULL," ");
   char* op="000000";
   func="000010";
   rd=register_to_binary(rd);
   rt=register_to_binary(rt);
   op=addstring(op,"00000");
   op=addstring(op,rt);
   op=addstring(op,rd);
   sa=dec_to_binary(sa,5);
   op=addstring(op,sa);
   op=addstring(op,func);
  return op;
}




