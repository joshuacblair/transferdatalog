#ifndef EXP_H
#define EXP_H

#include<string>
#include<sstream>

#include"Para.h"
class Para;

class Exp {
	private:
		Para *first;
		Para *second;
		char op;
	public:
		Exp();
    Exp(const Exp&) = delete;
		~Exp();
		void addFirst(Para *t);
		void addSecond(Para *t);
		void addOP(char t);
		std::string toString();
};

#endif //EXP_H
