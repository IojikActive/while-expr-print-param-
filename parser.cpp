#include <stdio.h>
#include "lexer.h"

extern int  lookahead;
extern int  intvalue;

extern int leftIntValue;
extern int rightIntValue;



void temptemp();
void temp();
bool expr();
bool compar(int leftValue);// возможно в аргумент придется передавать значение первого аргумента
int param();
int plus(int num);



int main()
{
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    int a;
    std::cout << "enter \"a\" value:";
    std::cin >> a;

    //scan();

    //std::cout << "[PARSER]: lookahead= " << lookahead << "\n";
    temptemp();    
    
    //std::cout << "result : "<< result << std::endl;
    
    std::cin.get();
    return 0;
}





int plus(int num){

    scan();

    if(lookahead == NUM){
        return num++;
    }else error("error in plus");
}

void var( std::string namevar) { // пока что будем парсить только переменную а...
    
    if (lookahead == VAR){

        
    }

}