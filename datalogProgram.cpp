#include<string>
#include<sstream>
#include "datalogProgram.h"

DatalogProgram::DatalogProgram() {
}

DatalogProgram::~DatalogProgram() {
	for (Q_Itr i = qList.begin(); i != qList.end(); i++) {
		if (NULL != (*i)) {
			delete (*i);
			*i = NULL;
		}
	}

	for (R_Itr i = rList.begin(); i != rList.end(); i++) {
		if (NULL != (*i)) {
			delete (*i);
			*i = NULL;
		}
	}

	for (F_Itr i = fList.begin(); i != fList.end(); i++) {
		if (NULL != (*i)) {
			delete (*i);
			*i = NULL;
		}
	}

	for (S_Itr i = sList.begin(); i != sList.end(); i++) {
		if (NULL != (*i)) {
			delete (*i);
			*i = NULL;
		}
	}
}

void DatalogProgram::addScheme(Scheme *s) {
	sList.push_back(s);
	return;
}

void DatalogProgram::addFact(Fact *f) {
	fList.push_back(f);
	return;
}

void DatalogProgram::addRule(Rule *r) {
	rList.push_back(r);
	return;
}

void DatalogProgram::addQuery(Query *q) {
	qList.push_back(q);
	return;
}

void DatalogProgram::addStrDom(Fact *f) {
	for (int i = 0; i < f->getSize(); ++i) {
		dom.addString(f->getString(i));
	}
	dom.removeDup();
	return;
}

std::string DatalogProgram::toString() {
	std::ostringstream os;
	os << "Schemes(" << sList.size() << "):" << std::endl;
	for (S_Itr i = sList.begin(); i != sList.end(); ++i) {
		os << (*i)->toString() << std::endl;
	}

	os << "Facts(" << fList.size() << "):" << std::endl;
	if (fList.size() > 0) {
		for (F_Itr i = fList.begin(); i != fList.end(); ++i) {
			os << (*i)->toString() << std::endl;
		}
	}
	
	os << "Rules(" << rList.size() << "):" << std::endl;
	if (rList.size() > 0) {
		for (R_Itr i = rList.begin(); i != rList.end(); ++i) {
			os << (*i)->toString() << std::endl;
		}
	}

	os << "Queries(" << qList.size() << "):" << std::endl;
	for (Q_Itr i = qList.begin(); i != qList.end(); ++i) {
		os << (*i)->toString() << std::endl;
	}
	os << "Domain(" << dom.getSize() << "):" << std::endl;
	os << dom.toString();
	return os.str();
}



