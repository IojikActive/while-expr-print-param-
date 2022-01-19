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
    scan();

    //std::cout << "[PARSER]: lookahead= " << lookahead << "\n";
    temptemp();    
    
    //std::cout << "result : "<< result << std::endl;
    
    std::cin.get();
    return 0;
}

void temptemp(){
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    temp();
}

void temp(){
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";


    if(lookahead == WHILE){
        scan();
        if(lookahead == LPAREN){
            expr();
            temp();
        }else error("expected error in temp, bad while");

    }

}

bool expr(){
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    bool leftArg = param();
    bool resultCOMP = compar(leftArg);

    return resultCOMP;
}

bool compar (int leftValue){
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    scan();
    if(lookahead == LESS){
        int RightValue = param();
        if(leftValue < RightValue){
            return true;
        }else return false;
    }else if(lookahead == MORE){
        int RightValue = param();
        if(leftValue > RightValue){
            return true;
        }else return false;

    }else if(lookahead == RPAREN){
        return leftValue; // Должен возвращать bool добавить if и счетчик
    }else error("Expected error in compar: bad arguments");

}


int param (){ 
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    scan();
    std::cout << "[PARSER]:" << "scan() in param " "lookahead= " << semDec(lookahead)  << "\n";

    if(lookahead == PLUS){
        //scan();
        if(lookahead == VAR) {
            scan();
            int a = 10; // костыль на время, чтоб хоть как-то работала 
            return ++a;// Скорее всего это неверно!
        }else error("Expected error in param: bad prefix increment arg");

    }else if(lookahead == VAR){
        scan();
        if(lookahead == PLUS){
            int a = 10;
            return a++;
        }else error("Expected error in param: bad postfix increment arg");

    }else if(lookahead == NUM){
        return intvalue;
    }else error("Expected error in param: bad int");

}

int plus(int num){
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    scan();
    if(lookahead == PLUS){
        return num++;
    }else if(lookahead == EMPTY){
        error("Expected invalid argument in plus");
    }else if(lookahead == NUM){
        return num+intvalue;
    }else error("Expected error in plus:invalid argument with num");
}


