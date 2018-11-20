#ifndef PRED_H
#define PRED_H

#include<string>
#include<sstream>
#include<vector>

#include"Para.h"

class Pred {
	private:
		std::string name;
		std::vector<Para*> paraList;
	public:
		Pred() {}
    Pred(const Pred&) = delete;
		~Pred() {
			for (size_t i = 0; i < paraList.size(); i++) {
				 if (paraList.at(i) != NULL) {
					 delete paraList.at(i);
					 paraList.at(i) = NULL;
				 }
			 }
		}

		void addName(std::string &t) {
			name = t;
			return;
		}

		void addPara(Para *t) {
			paraList.push_back(t);
			return;
		}

		std::string toString() {
			std::ostringstream os;
			os << name << "(";
			for(size_t i = 0; i < paraList.size() - 1; ++i) {
				os << paraList.at(i)->toString() << ",";
			}
			os << paraList.at(paraList.size() - 1)->toString() << ")";	
			return os.str();
		}
};

#endif //PRED_H
