#ifndef ID_H
#define ID_H
#include <openssl/rand.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define KEY_SIZE 32

struct id {
    unsigned char key[3];
    short indexs[3];
    int DotProduct;
    short Magnitude;
    char tag[4];
};
typedef struct id ID;

char* IDtoString(ID id);
void SaveInFile(const char* filename, ID *id);
ID ReadOfFile(const char* filename);
char CheckID(ID id, unsigned char* key, short key_length);
ID CreateID(unsigned char* key, short key_length, const char* tag);
#endif