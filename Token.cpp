#include "Token.h"

Token::Token(tokenType tokenVal, std::string value, int line) {
	token = tokenVal;
	data = value;
	lineNumber = line;
}

Token::~Token() {

}

tokenType Token::getToken() {
	return token;
}

std::string& Token::getData() {
	std::string& grabbed = data;
	grabbed.erase(0,1);
	grabbed.erase(grabbed.size() - 1);
	return grabbed;
}

int Token::getLine() {
	return lineNumber;
}

std::string Token::toString() {
	std::ostringstream out;
	out << "(";
	switch (token) {
	case COMMA:
		out << "COMMA";
		break;
	case PERIOD:
		out << "PERIOD";
		break;
	case Q_MARK:
		out << "Q_MARK";
		break;
	case LEFT_PAREN:
		out << "LEFT_PAREN";
		break;
	case RIGHT_PAREN:
		out << "RIGHT_PAREN";
		break;
	case COLON:
		out << "COLON";
		break;
	case COLON_DASH:
		out << "COLON_DASH";
		break;
	case MULTIPLY:
		out << "MULTIPLY";
		break;
	case ADD:
		out << "ADD";
		break;
	case SCHEMES:
		out << "SCHEMES";
		break;
	case FACTS:
		out << "FACTS";
		break;
	case RULES:
		out << "RULES";
		break;
	case QUERIES:
		out << "QUERIES";
		break;
	case ID:
		out << "ID";
		break;
	case STRING:
		out << "STRING";
		break;
	case COMMENT:
		out << "COMMENT";
		break;
	case WHITESPACE:
		out << "WHITESPACE";
		break;
	case UNDEFINED:
		out << "UNDEFINED";
		break;
	case END:
		out << "EOF";
		break;
	}
	out << "," << data << "," << lineNumber << ")";
	return out.str();
}
