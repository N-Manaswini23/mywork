
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
#include"data_transfer.h"


char* lw(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="100011";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}







char* sw(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="101011";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}



char* lh(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="100001";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}




char* lhu(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="100101";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}


char* sh(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="101001";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}



char* lb(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="100000";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}


char* lbu(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="100100";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}


char* lui(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,",");
   func="001111";
   rt=register_to_binary(rt);
   func=addstring(func,"00000");
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}
char* sb(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="101000";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}
char* ll(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="110000";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}
char* sc(char* mips)
{ char* data=mips;
char* func=NULL;
   func=strtok(data," ");
   char *rt=strtok(NULL,",");
   char *constant=strtok(NULL,"(");
   char *base=strtok(NULL,")");
   func="111000";
   rt=register_to_binary(rt);
   base=register_to_binary(base);
   func=addstring(func,base);
   func=addstring(func,rt);
   constant=dec_to_binary(constant,16);
   func=addstring(func,constant);
  return func;
}




