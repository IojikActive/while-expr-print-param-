#include <stdio.h>
#include "lexer.h"
#include <vector>

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

static bool tempexpr = 0;

struct Data_while {
    int count_while = 0;
    int i_while = 0;

};

int count_while = 0;
//std::vector<Data_while> __i_while;



int main()
{
    //scan();
    //std::cout << "[PARSER]: lookahead= " << lookahead << "\n";
    temptemp();    
    
    //std::cout << "result : "<< result << std::endl;
    
    std::cin.get();
    return 0;
}

void temptemp(){
    scan();
    std::cout << "[PARSER]:" << "scan() in temptemp " "lookahead= " << semDec(lookahead)  << "\n";
    std::cout<<__FUNCTION__<<"\n";
    temp();
}

void temp(){
    std::cout<<__FUNCTION__<<"\n";
    //scan();
    if(lookahead == WHILE){
        scan();
        std::cout << "[PARSER]:" << "scan() in temp " "lookahead= " << semDec(lookahead)  << "\n";
        if(lookahead == LPAREN){
            
            tempexpr = expr();
            scan();
            std::cout << "[PARSER]:" << "scan() in temp:LPAREN " "lookahead= " << semDec(lookahead)  << "\n";

            while(tempexpr){
                temp();
            }

        }
    }else if(lookahead == PRINT){
            scan();
            std::cout << "[PARSER]:" << "scan() in param::PRINT " "lookahead= " << semDec(lookahead)  << "\n";
            int a=param();
            std::cout <<"\n a:" << a << std::endl;
    }else if(lookahead == SEMI){
        tempexpr= false;

    } else error("expected error in temp, bad while");
}


bool expr(){
    std::cout<<__FUNCTION__<<"\n";

    bool leftArg = param();
    scan();
    std::cout << "[PARSER]:" << "scan() in expr " "lookahead= " << semDec(lookahead)  << "\n";
    if(lookahead == LESS || lookahead == MORE){
        bool resultCOMP = compar(leftArg);
        return resultCOMP;    
    }else if(lookahead == RPAREN){
        if(leftArg){
            return true;
        }
    }
}

bool compar (int leftValue){
    std::cout<<__FUNCTION__<<"\n";
    //if()//
    //scan();
    //std::cout << "[PARSER]:" << "scan() in compar " "lookahead= " << semDec(lookahead)  << "\n";
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
        //scan();
        return leftValue; // Должен возвращать bool, добавить if и счетчик?
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
            std::cout << "[PARSER]:" << "scan() in param::+VAR " "lookahead= " << semDec(lookahead)  << "\n";
            int a = 10; // костыль на время, чтоб хоть как-то работала 
            return ++a;// Скорее всего это неверно!
        }else error("Expected error in param: bad prefix increment arg");

    }else if(lookahead == VAR){
        scan();
        std::cout << "[PARSER]:" << "scan() in param::VAR+ " "lookahead= " << semDec(lookahead)  << "\n";
        if(lookahead == PLUS){
            int a = 10;
            return a++;
        }else error("Expected error in param: bad postfix increment arg");

    }else if(lookahead == NUM){
        scan();
        scan();
        std::cout << "[PARSER]:" << "scan() in param::NUM " "lookahead= " << semDec(lookahead)  << "\n";
        std::cout << "[PARSER]:" << "scan() in param::NUM2 " "lookahead= " << semDec(lookahead)  << "\n";
        return intvalue;
    }else error("Expected error in param: bad int");

}

int plus(int num){
    std::cout<<__FUNCTION__<<"\n";
    scan();
    std::cout << "[PARSER]:" << "scan() in PLUS " "lookahead= " << semDec(lookahead)  << "\n";
    if(lookahead == PLUS){
        return num++;
    }else if(lookahead == EMPTY){
        error("Expected invalid argument in plus");
    }else if(lookahead == NUM){
        return num+intvalue;
    }else error("Expected error in plus:invalid argument with num");
}


