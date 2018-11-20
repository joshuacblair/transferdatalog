#ifndef PARA_H
#define PARA_H

#include<string>
#include<sstream>

#include"Exp.h"
class Exp;

class Para {
	private:
		std::string data;
		Exp *expression;
	public:
		Para();
    Para(const Para&) = delete;
		~Para();

		void addData(std::string &t);
		void addExp(Exp *t);
		std::string toString();
};

#endif //PARA_H




