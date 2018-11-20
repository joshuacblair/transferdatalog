#include "InputStream.h"

InputStream::InputStream(FILE* in) {
	int lineNum = 1;
	char read = '\0';
	while (EOF != fscanf(in, "%c", &read)) {
		if (read == '\r' || read == '\n') {
			++lineNum;
		}
		inputChar current;
		current.lineNum = lineNum;
		current.parseChar = read;
		parseList.push_back(current);
	}
	inputChar current;
	current.lineNum = lineNum;
	current.parseChar = EOF;
	parseList.push_back(current);
}

	InputStream::~InputStream() {


}

char InputStream::getCurrent() {
	if (parseList.empty()) {
		return ' ';
	}
	return parseList.at(0).parseChar;
}

char InputStream::getNext() {
	if (parseList.size() > 1) {
		return parseList.at(1).parseChar;
	}
	return 0;
}

int InputStream::getLine() {
  int lineNum = 0;
  if ( parseList.size() > 0 ) {
	  lineNum = parseList.front().lineNum;
  }

  return (lineNum);
}

int InputStream::getSize() {
	return parseList.size();
}

void InputStream::advance() {
	if (parseList.empty()) {
		return;
	}
	else {
		parseList.erase(parseList.begin());
	}
	return;
}

