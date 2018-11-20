#ifndef LL_H
#define LL_H

#include<list>
#include<iostream>
#include"Token.h"
#include"Domain.h"
#include"datalogProgram.h"
#include"Fact.h"
#include"HeadPred.h"
#include"Para.h"
#include"Exp.h"
#include"Pred.h"
#include"Query.h"
#include"Rule.h"
#include"Scheme.h"

void idlist(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Scheme *currScheme);
void idlist(std::list<Token>::iterator &itr, std::list<Token> &tokenList, HeadPred *currHeadPred);

void schemeList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);
void scheme(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);

void stringList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Fact &currFact);

void fact(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);
void factList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);

HeadPred* headpred(std::list<Token>::iterator &itr, std::list<Token> &tokenList);
char op(std::list<Token>::iterator &itr, std::list<Token> &tokenList);

Exp* expression(std::list<Token>::iterator &itr, std::list<Token> &tokenList);

Para* parameter(std::list<Token>::iterator &itr, std::list<Token> &tokenList);
void paraList(std::list<Token>::iterator &itr, std::list<Token> &tokenList);

Pred* pred(std::list<Token>::iterator &itr, std::list<Token> &tokenList);

void predList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Rule *currRule);
void predList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, Query *currQuery);

void rule(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);
void ruleList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);

void queryList(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);
void query(std::list<Token>::iterator &itr, std::list<Token> &tokenList, DatalogProgram &master);

void parser(std::list<Token> &tokenList);

#endif //LL_H
