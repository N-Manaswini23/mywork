#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"get_format.h"
#include"header.h"

#include"rformat.h"

char* add(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="add";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  rd=bin_to_register(rd);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,rt);
  return func;
}

char* sub(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="sub";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  rd=bin_to_register(rd);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,rt);
  return func;
}

char* and(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="and";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  rd=bin_to_register(rd);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,rt);
  return func;
}

char* or(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="or";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  rd=bin_to_register(rd);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,rt);
  return func;
}

char* nor(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="nor";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  rd=bin_to_register(rd);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,rt);
  return func;
}


char* slt(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="slt";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  rd=bin_to_register(rd);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,rt);
  return func;
}

char* sltu(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="sltu";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  rd=bin_to_register(rd);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,rt);
  return func;
}

char* sll(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="sll";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* sa=create_array(mips,21,25);
  rd=bin_to_register(rd);
  sa=binary_to_dec(sa);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,sa);
  return func;
}

char* srl(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="srl";
  char* rd=create_array(mips,16,20);
  char* rt=create_array(mips,11,15);
  char* sa=create_array(mips,21,25);
  rd=bin_to_register(rd);
  sa=binary_to_dec(sa);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rd);
  func=addstring(func,",");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,sa);
  return func;
}

char* jr(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="jr";
  char* rs=create_array(mips,6,10);
  rs=bin_to_register(rs);
  func=addstring(func," ");
  func=addstring(func,rs);
  return func;
}

