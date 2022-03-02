#include "parser.h"
#include <stdio.h>
#include "lexer.h"


void DEBUG() {
    std::cout <<"[DEBUG][PARSER]: " << "LastToken:" << lastToken <<"lookahead: " << semDec(lookahead) << "\n";
}

void temptemp(){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";

    temp();
}

void temp(){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";

    scan();

    DEBUG();
    //std::cout << __FUNCTION__ << " BEGIN" << " Before scan"  << "\n";

    if(lookahead == WHILE){
        scan();
        if(lookahead == LPAREN){
            expr();
        }else error("error in temp NO LPAREN");

        scan();
        if(lookahead == RPAREN){
            temp();
        }else error ("error in temp NO RPAREN");
    }else if(lookahead == PRINT){
        scan();
        if(lookahead == LPAREN){
            param();
        }else error("error in temp, NO LPARERN in PRINT");

        if(lookahead !=RPAREN){
            scan(); //?
        }
        //scan();

        //DEBUG();
        //std::cout << __FUNCTION__ << " BEGIN" << " Before scan"  << "\n";

        if(lookahead == RPAREN){
            scan();
            if(lookahead == SEMI){
                //exit(EXIT_SUCCESS);
                temptemp();
            }else error("error in temp, NO SEMI in end of string");

        }else error("error in temp, NO RPAREN in PRINT");

    }
}

void expr(){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";
    
    
    param();
    if (lookahead == NUM){
        return;
    }
    scan();
    if( (lookahead == LESS) || (lookahead == MORE)){
        compare();
    }else return;    
}



bool compare(){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";

    bool result = false;
    int tempint = intvalue;

    DEBUG();
    //std::cout << __FUNCTION__ << " BEGIN" << " Before scan"  << "\n";
    
    if(lookahead == LESS){
        DEBUG();
        std::cout << __FUNCTION__ << " BEGIN" << "\n";
        std::cout << "LESS" << "\n";
        param();

    }else if( lookahead == MORE){
        DEBUG();
        std::cout << __FUNCTION__ << " BEGIN" << "\n";
        std::cout << "MORE" << "\n";
        param();

    }else return result;

}



int param () {

    scan();
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";
    if (lookahead == NUM){
        std::cout << __FUNCTION__ <<" EXIT NUM \n";
        return intvalue; 

    }else if(lookahead == VAR ){
        int tempint = var(); 
        scan();
        if (lookahead == PLUS){
            std::cout << __FUNCTION__ <<" EXIT RPLUS \n";
            return plus(tempint);

        }else return tempint;
    }else if (lookahead == PLUS){
        scan();
        if(lookahead == VAR){
            int tempint = var();
            std::cout << __FUNCTION__ <<" EXIT LPLUS \n";
            return ++tempint;

        }else error("Bad PLUSVAR int PARAM");
    }else error("error bad param?");

}

int plus(int num){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";

    return num++;
    //scan();
    // if(lookahead == NUM){
    //     return num++;
    // }else error("error in plus");
}


// Для перспективного анализа имени пременной и возвращения значения имени переменной

int var() { // пока что будем парсить только переменную а...
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";
    
    return a;
}

int main()
{
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    
    temptemp();
        
    std::cin.get();
    return 0;
}


/*
Для теста github merge

*/