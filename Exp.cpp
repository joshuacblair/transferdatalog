#include"Exp.h"

Exp::Exp() {
	first = NULL;
	second = NULL;
	op = 0;
}

Exp::~Exp() {
	if (first != NULL) {
		delete first;
		first = NULL;
	}
	if (second != NULL) {
		delete second;
		second = NULL;
	}
}

void Exp::addFirst(Para *t) {
	first = t;
	return;
}

void Exp::addSecond(Para *t) {
	second = t;
	return;
}

void Exp::addOP(char t) {
	op = t;
	return;
}

std::string Exp::toString() {
	std::ostringstream os;	
	os << "(" << first->toString() << op << second->toString() << ")";
	return os.str();
}

