#ifndef TOKEN_H
#define TOKEN_H

#include<string>
#include<sstream>
#include<map>

enum tokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN,
				RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY,
				ADD, SCHEMES, FACTS, RULES,
				QUERIES, ID, STRING, COMMENT,
				WHITESPACE, UNDEFINED, END};

class Token {
private:
	tokenType token;
	std::string data;
	int lineNumber;
public:
	Token(tokenType, std::string, int);
	~Token();
	tokenType getToken();
	std::string& getData();
	int getLine();
	std::string toString();
};

#endif //TOKEN_H
