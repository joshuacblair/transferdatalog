#include"Para.h"

Para::Para() {
	expression = NULL;
}

Para::~Para() {
	if (expression != NULL) {
		delete expression;
	}
}


void Para::addData(std::string &t) {
	data = t;
	return;
}

void Para::addExp(Exp *t) {
	expression = t;
	return;
}

std::string Para::toString() {
	std::ostringstream os;
	if (data.length() > 0) {
		os << data;
	}
	else {
		os << expression->toString();
	}
	return os.str();
}
