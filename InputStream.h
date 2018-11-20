#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H

#include<fstream>
#include<list>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>

class InputStream {
private:
	struct inputChar {
		char parseChar;
		int lineNum;
	};
	std::vector<inputChar> parseList;

public:
	InputStream(FILE* in);
  InputStream(const InputStream&) = delete;
	~InputStream();
	char getCurrent();
	char getNext();
	int getLine();
	int getSize();
	void advance();
};

#endif
