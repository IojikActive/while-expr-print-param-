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
bool compar();// возможно в аргумент придется передавать значение первого аргумента
int param();
int plus(int num);
int var();

void DEBUG() {
    std::cout <<"[DEBUG][PARSER]: " << "LastToken:" << lastToken <<"lookahead: " << semDec(lookahead) << "\n";
}



int main()
{
    std::cout <<"[PARSER]: " << __FUNCTION__ << ": BEGIN" << " lookahead = " << semDec(lookahead) << "\n";
    //std::cout << "enter \"a\" value:";
    //std::cin >> a;

    //scan();

    //std::cout << "[PARSER]: lookahead= " << lookahead << "\n";
    temptemp();    
    
    //std::cout << "result : "<< result << std::endl;
    
    std::cin.get();
    return 0;
}


void temptemp(){
    temp();
}

void temp(){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";

    scan();

    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << " Before scan"  << "\n";

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

        scan();

        DEBUG();
        std::cout << __FUNCTION__ << " BEGIN" << " Before scan"  << "\n";

        if(lookahead == RPAREN){
            scan();
            if(lookahead == SEMI){
                exit(EXIT_SUCCESS);
            }else error("error in temp, NO SEMI in end of string");

        }else error("error in temp, NO RPAREN in PRINT");

    }
}

void expr(){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";
    
    param();
    scan();
    if( (lookahead == LESS) || (lookahead == MORE)){
        compar();
    }else error("Error in expr , NO LESS or NO MORE");
    //compar();
}



bool compar(){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";

    bool result = false;
    int tempint = intvalue;
    //scan();

    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << " Before scan"  << "\n";
    
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
        return intvalue; // Вызывать compar()?

    }else if(lookahead == VAR ){
        int tempint = var(); // Для перспективного анализа имени пременной и возвращения значения имени переменной
        //scan();
        if (lookahead == PLUS){
            return plus(tempint);

        }else return tempint;
    }else if (lookahead == PLUS){
        
        scan();
        if (lookahead == VAR){
            scan();
            if(lookahead == PLUS){
                int tempint = var();// Для перспективного анализа имени пременной и возвращения значения имени переменной
                return plus(tempint);
            }else if(lookahead == RPAREN){
                scan();
            }
            
            
        }else error("bad PLUSVAR in param");

    }else error("error bad param?");

}

int plus(int num){
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";

    scan();

    if(lookahead == NUM){
        return num++;
    }else error("error in plus");
}


// Для перспективного анализа имени пременной и возвращения значения имени переменной

int var() { // пока что будем парсить только переменную а...
    DEBUG();
    std::cout << __FUNCTION__ << " BEGIN" << "\n";
    
    return a;
}