all:
	g++ parser.cpp lexer.cpp -o parser
	./parser

test:
	g++ test_scan.cpp -o test
	./test
