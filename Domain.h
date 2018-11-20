#ifndef DOMAIN_H
#define DOMAIN_H

#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

class Domain {
	private:
		std::vector<std::string> stringList;
	public:
		Domain() {}
    Domain(const Domain&) = delete;
		~Domain() {}

		int getSize() {
			return stringList.size();
		}

		void addString(std::string t) {
			stringList.push_back(t);
		}

		void removeDup() {
			std::vector<std::string>::iterator itr;
			std::sort(stringList.begin(), stringList.end());

			itr = std::unique(stringList.begin(), stringList.end());
			stringList.resize(std::distance(stringList.begin(), itr));
			return;
		}

		std::string toString() {
			std::ostringstream os;
			if (stringList.size() > 0) {
				for(size_t i = 0; i < stringList.size() - 1; i++) {
					os << "  " << stringList.at(i) << std::endl;
				}
				os << "  " << stringList.at(stringList.size()-1);
			}
			return os.str();			
		}
};

#endif // DOMAIN_H
