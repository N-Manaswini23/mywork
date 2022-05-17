#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"get_format.h"
#include"header.h"

#include"jformat.h"

char* jump(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="j";
  char* constant=create_array(mips,06,31);
  constant=binary_to_dec(constant);
  int address=4*atoi(constant);
  sprintf(constant,"%d",address);
  constant=dec_to_hex(constant);
  func=addstring(func," ");
  func=addstring(func,constant);
  return func;
}

char* jal(char* mips)
{
  char* func=(char*)malloc(100*sizeof(char));
  func="jal";
  char* constant=create_array(mips,06,31);
  constant=binary_to_dec(constant);
  int address=4*atoi(constant);
  sprintf(constant,"%d",address);
  constant=dec_to_hex(constant);
  func=addstring(func," ");
  func=addstring(func,constant);
  return func;
}