#include"ll.h"

void idlist(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Scheme *currScheme) {
	while(itr != tokenList.end()) {
		if (itr->getToken() == COMMA) {
			++itr;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == ID) {
			currScheme->addID(itr->getData());
			++itr;
			if (itr->getToken() != COMMA) {
				break;
			}
		}
		else {
			throw(*itr);
		}

	}
	return;
}

void idlist(std::list<Token>::iterator &itr, std::list<Token> &tokenList, HeadPred *currHeadPred) {
	while(itr != tokenList.end()) {
		if (itr->getToken() == COMMA) {
			++itr;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == ID) {
			currHeadPred->addID(itr->getData());
			++itr;
			if (itr->getToken() != COMMA) {
				break;
			}
		}
		else {
			throw(*itr);
		}

	}
	return;
}

void schemeList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	while(itr != tokenList.end()) {
		switch(itr->getToken()) {
			case ID:
				scheme(itr, tokenList, master);
				break;
			case FACTS:
				break;
			default:
				throw(*itr);
		}
		if (itr->getToken() == FACTS) {
			break;
		}	
		if (itr->getToken() == END) {
			throw(*itr);
		}
	}	
	return;
}

void scheme(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	Scheme * currScheme = new Scheme();
	try {
		switch(itr->getToken()) {
			case ID:
				currScheme->addName(itr->getData());
				itr++;
				if (itr->getToken() == LEFT_PAREN) {
					itr++;
				}
				else {
					throw(*itr); 
				}
				if (itr->getToken() == ID) {
					currScheme->addID(itr->getData());
					itr++;
				}
				else {
					throw(*itr); 
				}
				if (itr->getToken() == COMMA) {
					idlist(itr, tokenList, currScheme);
				}
				if (itr->getToken() == RIGHT_PAREN) {
					++itr;
					break;
				}
				else {
					throw(*itr);
				}
				break;
			default:
				throw(*itr); 
		}
	master.addScheme(currScheme);
	}
	catch(Token& t) {
		if (currScheme != NULL) {
			delete currScheme;
			currScheme = NULL;
		}
		throw(*itr);
	}
	
	return;
}

void stringList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Fact *currFact) {
	while(itr != tokenList.end()) {
		if (itr->getToken() == COMMA) {
			++itr;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == STRING) {
			currFact->addString(itr->getData());
			++itr;
			if (itr->getToken() != COMMA) {
				break;
			}
		}
		else {
			throw(*itr);
		}
	}
	return;
}

void fact(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	Fact * currFact = new Fact();
	try {
		if (itr->getToken() == ID) {
			currFact->addName(itr->getData());
			itr++;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == LEFT_PAREN) {
			itr++;
		}
		else {
			throw(*itr); 
		}
		if (itr->getToken() == STRING) {
			currFact->addString(itr->getData());
			itr++;
		}
		else {
			throw(*itr); 
		}
		if (itr->getToken() == COMMA) {
			stringList(itr, tokenList, currFact);
		}
		if (itr->getToken() == RIGHT_PAREN) {
		++itr;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == PERIOD) {
			++itr;
		}
		else {
			throw(*itr);
		}

	master.addFact(currFact);
	master.addStrDom(currFact);
	
	}		
	catch(Token& t) {
		if (currFact != NULL) {
			delete currFact;
			currFact = NULL;
		}
		throw(*itr);
	}
	
	return;
}

void factList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	while(itr != tokenList.end()) {
		switch(itr->getToken()) {
			case ID:
				fact(itr, tokenList, master);
				break;
			case END:
			case RULES:
				break;
			default:
				throw(*itr);
		}
		if (itr->getToken() == RULES) {
			break;
		}
		if (itr->getToken() == END) {
			throw(*itr);
		}
	}	
	return;
}

HeadPred* headpred(std::list<Token>::iterator &itr, std::list<Token> &tokenList) {
	HeadPred * currHeadPred = new HeadPred();
	try {
		currHeadPred->addName(itr->getData());
		itr++;
		if (itr->getToken() == LEFT_PAREN) {
			itr++;
		}
		else {
			throw(*itr); 
		}
		if (itr->getToken() == ID) {
			currHeadPred->addID(itr->getData());
			itr++;
		}
		else {
			throw(*itr); 
		}
		if (itr->getToken() == COMMA) {
			idlist(itr, tokenList, currHeadPred);
		}
		if (itr->getToken() == RIGHT_PAREN) {
			itr++;
		}
		else {
			throw(*itr);
		}
	}
	catch(Token& t) {
		if (currHeadPred != NULL) {
			delete currHeadPred;
			currHeadPred = NULL;
		}
		throw(*itr);
	}

	return (currHeadPred);
}

char op(std::list<Token>::iterator &itr, std::list<Token> &tokenList) {
  char retChar = 0;
	switch(itr->getToken()) {
		case ADD:
    		retChar = '+';
     		itr++;
			break;
		case MULTIPLY:
      		retChar = '*';
      		itr++;
			break;
		default:
			throw(*itr);
	}
  
	return(retChar);
}

Exp* expression(std::list<Token>::iterator &itr, std::list<Token> &tokenList) {
	Exp * exp = new Exp();
	try {
		exp->addFirst(parameter(itr, tokenList));
		exp->addOP(op(itr, tokenList));
		exp->addSecond(parameter(itr, tokenList));
		
		if (itr->getToken() == RIGHT_PAREN) {
			itr++;
		}
		else {
			throw(*itr);
		}
	}

	catch(Token& t) {
		if (exp != NULL) {
			delete exp;
			exp = NULL;
		}
		throw(*itr);
	}
	
	return(exp);
}

Para* parameter(std::list<Token>::iterator &itr, std::list<Token> &tokenList) {
	Para * currPara = new Para();
	try {
		switch(itr->getToken()) {
			case ID:
				currPara->addData(itr->getData()); 
				itr++;
				break;
			case STRING:
				currPara->addData(itr->getData());
				itr++;
				break;
			case LEFT_PAREN:
				itr++;
				currPara->addExp(expression(itr, tokenList));
				break;
			default:
				throw(*itr);
		}
	}
	catch(Token& t) {
		if (currPara != NULL) {
			delete currPara;
			currPara = NULL;
		}
		throw(*itr);
	}

	return (currPara);
}

void paraList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Pred* currPred) {
	while(itr != tokenList.end()) {
		if (itr->getToken() == RIGHT_PAREN) {
			break;
		}
		if (itr->getToken() == COMMA) {
			itr++;
		}
		else {
			throw(*itr);
		}
		if ((itr->getToken() == ID) || (itr->getToken() == STRING) || (itr->getToken() == LEFT_PAREN)) {
			currPred->addPara(parameter(itr, tokenList));
		}
		else {
			throw(*itr);
		}
	}
	return;
}

Pred* pred(std::list<Token>::iterator &itr, std::list<Token> &tokenList) {
	Pred * currPred = new Pred();
	try {
		if (itr->getToken() == END) {
			throw(*itr);
		}
		else {
			currPred->addName(itr->getData());
			itr++;
		}
	
		if (itr->getToken() == LEFT_PAREN) {
		 	itr++;
		}
		else {
			throw(*itr);
		}
	
		currPred->addPara(parameter(itr, tokenList));
		paraList(itr, tokenList, currPred);

		if (itr->getToken() == RIGHT_PAREN) {
			itr++;
		}
		else {
			throw(*itr);
		}
	}
	catch(Token& t) {
		if (currPred != NULL) {
			delete currPred;
			currPred = NULL;
		}
		throw(*itr);
	}

	return(currPred);
}

void predList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Rule * currRule) {
	while(itr != tokenList.end()) {
		if (itr->getToken() == PERIOD) {
			break;
		}
		if (itr->getToken() == COMMA) {
			itr++;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == ID) {
			currRule->addPred(pred(itr, tokenList));
		}
		else {
			throw(*itr);
		}
	}
	return;
}

void predList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Query * currQuery) {
	while(itr != tokenList.end()) {
		if (itr->getToken() == PERIOD) {
			break;
		}
		if (itr->getToken() == COMMA) {
			itr++;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == ID) {
			currQuery->addPred(pred(itr, tokenList));
		}
		else {
			throw(*itr);
		}
	}
	return;
}
void rule(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	Rule * currRule = new Rule();
	try {
		currRule->addHead(headpred(itr, tokenList));
		if (itr->getToken() == COLON_DASH) {
			itr++;
		}
		else {
			throw(*itr);
		}
		if (itr->getToken() == ID) {
			currRule->addPred(pred(itr, tokenList));
		}
		else {
			throw(*itr);
		}	
		predList(itr, tokenList, currRule);
		if (itr->getToken() == PERIOD) {
			itr++;
		}
		else {
			throw(*itr);
		}
	master.addRule(currRule);
	}
	catch(Token& t) {
		if (currRule != NULL) {
			delete currRule;
			currRule = NULL;
		}
		throw(*itr);
	}

	return;
}

void ruleList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	while(itr != tokenList.end()) {
		switch(itr->getToken()) {
			case ID:
				rule(itr, tokenList, master);
				break;
			case END:
			case QUERIES:
				break;
			default:
				throw(*itr);
		}
		if (itr->getToken() == QUERIES) {
			break;
		}	
		if (itr->getToken() == END) {
			throw(*itr);
		}
	}	
	return;
}

void queryList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	while(itr != tokenList.end()) {
		switch(itr->getToken()) {
			case ID:
				query(itr, tokenList, master);
				break;
			case END:
				break;
			default:
				throw(*itr);
		}
		if (itr->getToken() == END) {
			break;
		}
	}	
	return;
}

void query(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master) {
	Query * currQuery = new Query();
	try {
		currQuery->addPred(pred(itr, tokenList));
		if (itr->getToken() == Q_MARK) {
			itr++;
			master.addQuery(currQuery);
		}
		else {
			throw(*itr);
		}
	}	
	catch(Token& t) {
		if (currQuery != NULL) {
			delete currQuery;
			currQuery = NULL;
		}
		throw(*itr);
	}

	return;
}

void parser(std::list<Token> &tokenList) {
	std::list<Token>::iterator itr = tokenList.begin();
	DatalogProgram master;
	try {
			if(itr->getToken() == SCHEMES) {
				itr++;
			}
			else {
				throw(*itr);
			}
			if(itr->getToken() == COLON) {
				itr++;
				scheme(itr, tokenList, master);
				schemeList(itr, tokenList, master);
			}
			else {
				throw(*itr);
			}
		while(itr != tokenList.end()) {
			switch (itr->getToken()) {
				case FACTS:
					itr++;
					if(itr->getToken() == COLON) { 
						itr++;
						factList(itr, tokenList, master);
					}
					else {
						throw(*itr);
					}
					break;

				case RULES:
					itr++; 
					if(itr->getToken() == COLON) {
						itr++;
						ruleList(itr, tokenList, master);
					}
					else {
						throw(*itr);
					}
					break;

				case QUERIES:
					itr++; 
					if(itr->getToken() == COLON) {
						itr++;
						query(itr, tokenList, master);
						queryList(itr,tokenList, master);
					}
					else {
						throw(*itr);
					}
					break;
			   
				case END:
					itr++;
					std::cout << "Success!" << std::endl;
					break;
				default:
					throw(*itr);
					break;
			}
		}
		std::cout << master.toString() << std::endl;
	}
	catch(Token& t) {
		std::cout << "Failure!" << std::endl;
		std::cout << "  " << t.toString() << std::endl;
	}

	
	return;
}
