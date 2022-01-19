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
    scan();
    //std::cout << "[PARSER]: lookahead= " << lookahead << "\n";
    temptemp();    
    
    //std::cout << "result : "<< result << std::endl;
    
    std::cin.get();
    return 0;
}

void temptemp(){
    std::cout<<__FUNCTION__<<"\n";
    temp();
}

void temp(){
    std::cout<<__FUNCTION__<<"\n";
    if(lookahead == WHILE){
        scan();
        if(lookahead == LPAREN){
            //scan();
            while(expr()){
                temp();
            }

        }else if(lookahead == PRINT){
            int a=param();
            std::cout <<"\n a:" << a << std::endl;

        }else error("expected error in temp, bad while");

    }

}

bool expr(){
    std::cout<<__FUNCTION__<<"\n";
    bool leftArg = param();
    bool resultCOMP = compar(leftArg);

    return resultCOMP;
}

bool compar (int leftValue){
    std::cout<<__FUNCTION__<<"\n";
    //if()//
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
        return leftValue; // Должен возвращать bool добавить if и счетчик?
    }else error("Expected error in compar: bad arguments");

}


int param (){ // не закончен
    std::cout<<__FUNCTION__<<"\n";
    /*
    while(a++<10)print(a);
    Пока что непонятно как мне инициализировать переменную а
    Либо добавлять в свою грамматику часть грамматики Бори
    Либо придумывать какой-то костыль, который позволит обойти
    инициализацию переменной.
    Переменную а можно будет запрашивать сразу, если я увидел её
    */
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
    std::cout<<__FUNCTION__<<"\n";
    scan();
    if(lookahead == PLUS){
        return num++;
    }else if(lookahead == EMPTY){
        error("Expected invalid argument in plus");
    }else if(lookahead == NUM){
        return num+intvalue;
    }else error("Expected error in plus:invalid argument with num");
}


