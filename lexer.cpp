#include "lexer.h"

int     lookahead;
int     intvalue;




void debugInfo(char c, std::string lastToken , std::string info){
    std::cout << "[LEXER]: C:"<<c << " LastToken:" << lastToken << "\t" << info << "\n";
}

int scan() {
    std::string lastToken = "";
    while(1) {
        char c = getchar();
        lastToken += c;
        //printf("Lexer:  %c \n",c);
        std::cout << "[LEXER]: C:"<<c << " LastToken:" << lastToken << std::endl;
        if (c == ' ' || c == '\t' || c == '\r'){;} // Возможно стоит очищать lastToken?
        else if (isdigit(c))
        {
            int tokenval = c - '0';
            c = getchar();
            lastToken += c;
            while (isdigit(c)) {
                tokenval = tokenval * 10 + (c - '0');
                c = getchar();
                lastToken += c;
            }
            ungetc(c,stdin);
            lookahead = NUM;
            intvalue = tokenval;
            return lookahead;
        }
        else if (c == 'w'){
            c = getchar();
            lastToken += c;
            if (c != 'h') error("invalid character");
            c = getchar();
            lastToken += c;
            if (c != 'i') error("invalid character");
            c = getchar();
            lastToken += c;
            if (c != 'l') error("invalid character");
            c = getchar();
            lastToken += c;
            if (c != 'e') error("invalid character");
            
            lookahead = WHILE;
            return lookahead;
        }
        else if (c == 'p'){
            c = getchar();
            if (c != 'r') error("invalid character");
            c = getchar();
            if (c != 'i') error("invalid character");
            c = getchar();
            if (c != 'n') error("invalid character");
            c = getchar();
            if (c != 't') error("invalid character");
            lookahead = PRINT;
            return lookahead;
        }
        else if (c == '('){
            lookahead = LPAREN;
            return lookahead;
        }
        else if (c == ')'){
            lookahead = RPAREN;
            return lookahead;
        }
        else if (c == ','){
            lookahead = COMMA;
            return lookahead;
        }
        else if (c == ';'){
            lookahead = SEMI;
            return lookahead;
        }
        else if (c == '+'){
            c = getchar();
            if (c != '+') error("invalid character");
            lookahead = PLUS;
            return lookahead;
        }
        else if (c == '<'){
            lookahead = LESS;
            return lookahead;
        }
        else if (c == '>'){
            lookahead = MORE;
            return lookahead;
        }else if(isalpha(c)){
            lastToken = "";
            lastToken +=c;
            do{
                printf("Lexer_isalpha(c):  %s \n %c", lastToken,c);
                c = getchar();
                lastToken += c;
            }while(isalpha(c));
        }else if (c == '\n'){
            lookahead = EMPTY;
            return lookahead;
        }
        
        else {
            error("Non-existing token: " + lastToken);
        }
    }
}

int error(std::string errorMessage) {
    std::cout << errorMessage << "\n";
    exit(EXIT_FAILURE);
}


std::string semDec(int Lexem){

    std::string lexemName;

    switch(Lexem){
        case 0:
            lexemName = "WHILE"; 
            break;
            return lexemName;
        case 1:
            lexemName = "PRINT"; 
            break;
            return lexemName;
        case 2:
            lexemName = "VAR"; 
            break;
            return lexemName;
            
        case 3:
            lexemName = "NUM"; 
            break;
            return lexemName;
        case 4:
            lexemName = "PLUS"; 
            break;
            return lexemName;
        case 5:
            lexemName = "LESS"; 
            break;
            return lexemName;
        case 6:
            lexemName = "MORE"; 
            break;
            return lexemName;
        case 7:
            lexemName = "RPAREN"; 
            break;
            return lexemName;
        case 8:
            lexemName = "LPAREN"; 
            break;
            return lexemName;
        case 9:
            lexemName = "COMMA"; 
            break;
            return lexemName;
        case 10:
            lexemName = "SEMI"; 
            break;
            return lexemName;
        case 11:
            lexemName = "EMPTY";
            break;
            return lexemName;
        default:
            lexemName = "Error decode";
            return lexemName;
    }
    
}