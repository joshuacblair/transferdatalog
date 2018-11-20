#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include<list>

#include"Scheme.h"
#include"Fact.h"
#include"Rule.h"
#include"Query.h"
#include"Domain.h"

typedef std::list<Scheme*> S_List;
typedef std::list<Fact*> F_List;
typedef std::list<Rule*> R_List;
typedef std::list<Query*> Q_List;

typedef S_List::iterator S_Itr;
typedef F_List::iterator F_Itr;
typedef R_List::iterator R_Itr;
typedef Q_List::iterator Q_Itr;


class DatalogProgram {
	private:
		S_List sList;
		F_List fList;
		R_List rList;
		Q_List qList;
		Domain dom;
	public:
		DatalogProgram();
    DatalogProgram(const DatalogProgram&) = delete;
		~DatalogProgram();
		void addScheme(Scheme *s);
		void addFact(Fact *f);
		void addRule(Rule *r);
		void addQuery(Query *q);
		void addStrDom(Fact *f);
		
		std::string toString();

};

#endif //DATALOGPROGRAM_H
