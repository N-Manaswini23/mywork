#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"get_format.h"
#include"header.h"

#include"lformat.h"



char* addi(char* mips)
{
  char* func="addi";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}

char* lw(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="lw";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}

char* sw(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="sw";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}

char* lh(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="lh";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}


char* sh(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="sh";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}


char* lb(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="lb";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}

char* lbu(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="lbu";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}

char* lhu(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="lhu";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}

char* sb(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="sb";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}


char* sc(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="sc";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}


char* ll(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  char* constant=(char*)malloc(100*sizeof(char));
  func="ll";
  constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  func=addstring(func,"(");
  func=addstring(func,rs);
  func=addstring(func,")");
  return func;
}

char* lui(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="lui";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  constant=binary_to_dec_signed(constant);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}

char* andi(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="andi";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}

char* ori(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="ori";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}


char* slti(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="slti";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}

char* sltiu(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="sltiu";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}

char* beq(char* mips,char source_file[50],int line)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="beq";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  int m=atoi(constant);
  int address=(m+line)*4;
  sprintf(constant,"%d",address);
  constant=dec_to_hex(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}

char* bne(char* mips,char source_file[50],int line)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="bne";
  char* constant=create_array(mips,16,31);
  char* rt=create_array(mips,11,15);
  char* rs=create_array(mips,6,10);
  constant=binary_to_dec_signed(constant);
  int m=atoi(constant);
  int address=(m+line)*4;
  sprintf(constant,"%d",address);
  constant=dec_to_hex(constant);
  rs=bin_to_register(rs);
  rt=bin_to_register(rt);
  func=addstring(func," ");
  func=addstring(func,rt);
  func=addstring(func,",");
  func=addstring(func,rs);
  func=addstring(func,",");
  func=addstring(func,constant);
  return func;
}