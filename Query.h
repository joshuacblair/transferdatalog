#ifndef QUERY_H
#define QUERY_H

#include<string>
#include<sstream>
#include<vector>

class Query {
	private:
		Pred * predicate;
		
	public:
		Query() {
			predicate = NULL;
		}
    Query(const Query&) = delete;
		~Query() {
			if (NULL != predicate) {
				delete predicate;
				predicate = NULL;
			}
		}

		void addPred(Pred* pred) {
			predicate = pred;
			return;
		}
		
		std::string toString() {
			std::ostringstream os;
			os << "  " << predicate->toString() << "?";
			return os.str();			
		}
};

#endif //QUERY_H
