#include <openssl/evp.h>
#include "id.h"
#include "token.h"
#define SIZE 8

int main(void){
    Token t = CreateToken("EXPL");
    printf("Token de assinatura ->\n\t %s\n", TokenToString(t));
    printf("Key valida o id -> %i\n",CheckID(t.id,t.key,sizeof(t.key)));
    return 0;
}