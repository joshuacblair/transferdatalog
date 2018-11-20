#ifndef LEXICAL_H
#define LEXICAL_H

#include "InputStream.h"
#include "Token.h"

void tokenizer(InputStream &input, std::list<Token> &tokenList);

#endif //LEXICAL_H
