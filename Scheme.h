#ifndef SCHEME_H
#define SCHEME_H

#include<string>
#include<sstream>
#include<vector>

class Scheme {
	private:
		std::string name;
		std::vector<std::string> iDList;
	public:
		Scheme() {}
    Scheme(const Scheme&) = delete;
		~Scheme() {}

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
			os << "  " << name << "(";
			for(size_t i = 0; i < iDList.size() - 1; ++i) {
				os << iDList.at(i) << ",";
			}
			os << iDList.at(iDList.size() - 1) << ")";
			return os.str();			
		}
};

#endif //SCHEME_H
