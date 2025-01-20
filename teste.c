#include <openssl/evp.h>
#include "signature.c"
#define SIZE 8

void PrintKey(unsigned  char* key){
    for (int i = 0; i < SIZE;i++){
        printf("%02x ", key[i]);
    }
    printf("\n");
}

int main(void){
    unsigned char key[SIZE];
    unsigned char iv[16];
    RAND_bytes(key,SIZE);
    RAND_bytes(iv,sizeof(iv));
    ID id = CreateID(key,SIZE);
    char* id_string = IDtoString(id);
    printf("ID -> %s\n",id_string);
    SaveInFile("data",&id);
    ID ff = ReadOfFile("data");
    printf("ID -> %s\n",IDtoString(ff));
    free(id_string);
    printf("Singature -> %s\n", SignatureToString(CreateSignature()));
    return 0;
}