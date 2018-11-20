#include<iostream>
#include<string>
#include<fstream>

#include "InputStream.h"
#include "Token.h"
#include "lexical.h"
#include "ll.h"

int main(int argc, char * argv[]) {

	if (argc < 2) {
		std::cerr << "Requires argument for input." << std::endl;
		return 1;
	}
	if (argc > 2) {
		std::cerr << "Too many arguments. Please try again." << std::endl;
		return 1;
	}

	FILE* inFile = fopen(argv[1], "r");

  if (NULL != inFile) {
	  InputStream input(inFile);

	  std::list<Token> tokenList;
	  tokenizer(input, tokenList);
	  parser(tokenList);

	  fclose(inFile);
  }
  else
  {
    std::cerr << "Input file: " << argv[1] << " not found." << std::endl;
  }

	return 0;
}
