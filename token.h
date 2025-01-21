#ifndef TOKEN_H
#define TOKEN_H
#include "id.h"

struct token{
    unsigned char key[KEY_SIZE];
    ID id;
};
typedef struct token token;

token CreateSignature();
char* SignatureToString(token s);
#endif