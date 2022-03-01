#include <stdio.h>
#include "lexer.h"


extern int  lookahead;
extern int  intvalue;
extern std::string lastToken;

extern int leftIntValue;
extern int rightIntValue;

int a =1;



void temptemp();
void temp();
void expr();
bool compare();// возможно в аргумент придется передавать значение первого аргумента
int param();
int plus(int num);
int var();

void DEBUG();
