#ifndef RULE_H
#define RULE_H

#include<string>
#include<sstream>
#include<vector>

#include"HeadPred.h"
#include"Pred.h"

class Rule {
	private:
		HeadPred * head;
		std::vector<Pred*> predList;
	public:
		Rule() {
			head = NULL;
		}
    Rule(const Rule&) = delete;
		~Rule() {
			if (NULL != head) {
				delete head;
				head = NULL;
			}
			for (size_t i = 0; i < predList.size(); i++) {
				if (predList.at(i) != NULL) {
					delete predList.at(i);
					predList.at(i) = NULL;
				}
			}
		}

		void addHead(HeadPred  *t) {
			head = t;
			return;
		}

		void addPred(Pred * t) {
			predList.push_back(t);
			return;
		}
		
		std::string toString() {
			std::ostringstream os;
			os << "  " << head->toString() << " :- ";
			for(size_t i = 0; i < predList.size() - 1; ++i) {
				os << predList.at(i)->toString() << ",";
			}
			os << predList.at(predList.size() - 1)->toString() << ".";
			return os.str();			
		}
};

#endif //RULE_H
