#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>

std::string semDec(int Lexem);

enum
{
	WHILE, 		//ok
	PRINT,		//ok
	VAR,		// For var names OK?
	NUM,	 	//numbers ok
	PLUS, 		// ++ ok
	LESS, 		// < ok
	MORE, 		// > ok
	RPAREN, 	// ( ok
	LPAREN, 	// ) ok
	COMMA,		// , ok
	SEMI,		// ; ok
	EMPTY
};


int scan();
int error(std::string errorMessage);

#endif
