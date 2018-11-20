#ifndef HEADPRED_H
#define HEADPRED_H

#include<string>
#include<sstream>
#include<vector>

class HeadPred {
	private:
		std::string name;
		std::vector<std::string> iDList;
	public:
		HeadPred() {}
    HeadPred(const HeadPred&) = delete;
		~HeadPred() {}

		void addName(std::string &t) {
			name = t;
			return;
		}

		void addID(std::string &t) {
			iDList.push_back(t);
			return;
		}

		std::string toString() {
			std::ostringstream os;
			os << name << "(";
			for(size_t i = 0; i < iDList.size() - 1; ++i) {
				os << iDList.at(i) << ",";
			}
			os << iDList.at(iDList.size() - 1) << ")";
			return os.str();			
		}
};

#endif //HeadPred_H
