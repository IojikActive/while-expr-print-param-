all:
	g++ lexer.h parser.h parser.cpp lexer.cpp -o parser
	./parser

test:
	./parser
