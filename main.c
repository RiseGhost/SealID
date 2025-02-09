#include <openssl/evp.h>
#include "id.h"
#define SIZE 8

unsigned char* ReadKey(const char* filename){
    unsigned char* key = (unsigned char*) malloc(KEY_SIZE);
    FILE* file = fopen(filename,"rb");
    fread(key,1,KEY_SIZE,file);
    fclose(file);
    return key;
}

int main(int argc, char** argv){
    //int outFileName = strcmp(argv[1],"--out");
    if (argc == 2 || argc == 3){
        unsigned char* key = ReadKey(argv[1]);
        ID id = (argc == 2) ? CreateID(key,sizeof(key),"") : CreateID(key,sizeof(key),argv[2]);
        printf("ID -> %s\n", IDtoString(id));
        free(key);
    }
    else if (argc != 1){
        printf("Erro many args!!!\n");
        return -1;
    }
    else {
        unsigned char key[KEY_SIZE];
        RAND_bytes(key,KEY_SIZE);
        FILE* file = fopen("key","wb");
        fwrite(key,1,KEY_SIZE,file);
        fclose(file);
        printf("Key create with sucess! ✅\n");
    }
    return 0;
}