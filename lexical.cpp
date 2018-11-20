#include<iostream>
#include<string>
#include<fstream>

#include "lexical.h"

char stateShifter(char x) {
	if (isalpha(x)) {
		return 'a';
	}
	return x;
}

bool endQuote(char x, char y) {
	if (x == '\'' && y != '\'') {
		return true;
	}
	return false;
}

void whiteSpace(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = WHITESPACE;
	currString = "\" \"";
	startLine = input.getLine();
	return;
}

void comma(InputStream &input, tokenType & currToken, std::string &currString, int &startLine) {
	currToken = COMMA;
	currString = "\",\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void period(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = PERIOD;
	currString = "\".\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void qmark(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = Q_MARK;
	currString = "\"?\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void lparen(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = LEFT_PAREN;
	currString = "\"(\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void rparen(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = RIGHT_PAREN;
	currString = "\")\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void colon(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = COLON;
	currString = "\":\"";
	startLine = input.getLine();
	input.advance();
	if (input.getCurrent() == '-') {
		currToken = COLON_DASH;
		currString = "\":-\"";
		input.advance();
	}
	return;
}

void multiply(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = MULTIPLY;
	currString = "\"*\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void add(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = ADD;
	currString = "\"+\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void specialID(std::string currString, tokenType &currToken) {

	if (currString == "\"Schemes\"") {
		currToken = SCHEMES;
	}
	else if (currString == "\"Facts\"") {
		currToken = FACTS;
	}
	else if (currString == "\"Rules\"") {
		currToken = RULES;
	}
	else if (currString == "\"Queries\"") {
		currToken = QUERIES;
	}
	return;
}

void id(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {

	currToken = ID;
	currString = "\"";
	currString += input.getCurrent();
	startLine = input.getLine();
	input.advance();
	while (isalpha(input.getCurrent()) || isdigit(input.getCurrent())) {
		currString += input.getCurrent();
		input.advance();
	}
	currString += "\"";
	specialID(currString, currToken);
	return;
}

void str(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {

			currToken = STRING;
			currString = "\"\'";
			startLine = input.getLine();
			input.advance();
				do {
				
				if (input.getCurrent() != EOF) {
					if (input.getCurrent() == '\'' && !endQuote(input.getCurrent(), input.getNext())) {
						currString += input.getCurrent();
						currString += input.getNext();
						input.advance();
					}
					else if (input.getCurrent() == '\'' && endQuote(input.getCurrent(), input.getNext())) {
						break;
					}
					else {
						currString += input.getCurrent();
					}
				}
				else {
					currToken = UNDEFINED;
					break;
				}
				input.advance();
			} while (!endQuote(input.getCurrent(), input.getNext()));
			if (currToken == UNDEFINED) {
				currString += "\"";
			}
			else {
				currString += "\'\"";
				input.advance();
			}
	return;
}	

void comment(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {

	currToken = COMMENT;
	currString = "\"#";
	startLine = input.getLine();
	input.advance();
	if (input.getCurrent() == '|') {
		currString = "\"#|";
		input.advance();
		while ((input.getCurrent() != '|') || (input.getNext() != '#')) {
			currString += input.getCurrent();
			input.advance();
			if (input.getCurrent() == EOF) {
				currToken = UNDEFINED;
				currString += "\"";
				return;
			}
		}
		if (currToken == UNDEFINED) {
			return;
		}
		else {
			currString += "|#\"";
			input.advance();
			input.advance();
		}
	}
	else {
		while (input.getCurrent() != '\r' && input.getCurrent() != '\n') {
			currString += input.getCurrent();
			input.advance();
		}
		currString += "\"";
	}
	return;
}

void end(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = END;
	currString = "\"\"";
	startLine = input.getLine();
	input.advance();
	return;
}

void undef(InputStream &input, tokenType &currToken, std::string &currString, int &startLine) {
	currToken = UNDEFINED;
	currString = "\"\"";
	currString.insert(1, 1, input.getCurrent());
	startLine = input.getLine();
	input.advance();
	return;
}

void tokenizer(InputStream &input, std::list<Token> &tokenList) {
	int listSize = input.getSize();
	for (int i = 0; i < listSize; ++i) {
		std::string currString = "";
		tokenType currToken = WHITESPACE;
		int startingLine = 1;

		switch (stateShifter(input.getCurrent())) {

		case ' ':
		case '\n':
		case '\r':
			whiteSpace(input, currToken, currString, startingLine);
			break;
			
		case ',':
			comma(input, currToken, currString, startingLine);
			break;

		case '.':
			period(input, currToken, currString, startingLine);
			break;

		case '?':
			qmark(input, currToken, currString, startingLine);
			break;

		case '(':
			lparen(input, currToken, currString, startingLine);
			break;

		case ')':
			rparen(input, currToken, currString, startingLine);
			break;

		case ':':
			colon(input, currToken, currString, startingLine);
			break;

		case '*':
			multiply(input, currToken, currString, startingLine);
			break;

		case '+':
			add(input, currToken, currString, startingLine);
			break;

		case 'a':
			id(input, currToken, currString, startingLine);
			break;

		case '\'':
			str(input, currToken, currString, startingLine);
			break;

		case '#':
			comment(input, currToken, currString, startingLine);
			break;

		case EOF:
			end(input, currToken, currString, startingLine);
			break;

		default:
			undef(input,currToken, currString, startingLine);
			break;
		}
		
		if (currToken != WHITESPACE && currToken != COMMENT) {
			Token newToken(currToken, currString, startingLine);
			tokenList.push_back(newToken);
		}
		else {
			input.advance();
		}
	}
	return;
}
