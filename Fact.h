#ifndef FACT_H
#define FACT_H

#include<string>
#include<sstream>
#include<vector>

class Fact {
	private:
		std::string name;
		std::vector<std::string> stringList;
	public:
		Fact() {}
    Fact(const Fact&) = delete;
		~Fact() {}
		void addName(std::string &t) {
			name = t;
		}

		void addString(std::string &t) {
			stringList.push_back(t);
		}
		
		std::string getString(int i) {
			return stringList.at(i);
		}

		int getSize() {
			return stringList.size();
		}

		std::string toString() {
			std::ostringstream os;
			os << "  " << name << "(";
			for(size_t i = 0; i < stringList.size() - 1; ++i) {
				os << stringList.at(i) << ",";
			}
			os << stringList.at(stringList.size() - 1) << ").";	
			return os.str();			
		}
};

#endif //FACT_H
