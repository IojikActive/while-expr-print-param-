all:
	g++ parser.cpp lexer.cpp -o parser
	./parser

test:
	./parser
