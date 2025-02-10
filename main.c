#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include "id.h"
#define SIZE 8

unsigned char* ReadKey(const char* filename){
    unsigned char* key = (unsigned char*) malloc(KEY_SIZE);
    FILE* file = fopen(filename,"rb");
    fread(key,1,KEY_SIZE,file);
    fclose(file);
    return key;
}

// Retorna o nome do ficheiro onde será guardado o output
char* GetSaveFileName(int argc, char** argv){
    for (int index = 0; index < argc; index++){
        if (strcmp(argv[index],"--save") == 0){
            return (index == argc - 1) ? "" : argv[index + 1];
        }
    }
    return "";
}

// Altera o argv[] para remover as flags "--save filename"
char** RemoveSaveFileName(int argc,char **argv){
    char** new_argv = (char**) malloc((argc - 2) * sizeof(char*));
    int i = 0;
    for (int index = 0; index < argc; index++){
        if (strcmp(argv[index],"--save") != 0){
            new_argv[i] = (char*) malloc(strlen(argv[index]));
            strcpy(new_argv[i],argv[index]);
            i++;
        }
        else{
            index++;
        }
    }
    return new_argv;
}

int main(int argc, char** argv){
    //int outFileName = strcmp(argv[1],"--out");
    char* SaveFileName = GetSaveFileName(argc,argv);
    char** flags = (strcmp(SaveFileName,"") == 0) ? argv : RemoveSaveFileName(argc,argv);
    int flags_number = (strcmp(SaveFileName,"") == 0) ? argc : argc - 2;
    if (flags_number >= 2){
        unsigned char* key = ReadKey(flags[1]);
        ID id = (flags_number == 2) ? CreateID(key,sizeof(key),"") : CreateID(key,sizeof(key),flags[2]);
        if (strcmp(SaveFileName,"") != 0) SaveInFile(SaveFileName,&id);
        else printf("ID -> %s\n", IDtoString(id));
        free(key);
        return 0;
    }
    else if (flags_number != 1){
        printf("Erro many args!!!\n");
        return -1;
    }
    else {
        unsigned char key[KEY_SIZE];
        RAND_bytes(key,KEY_SIZE);
        FILE* file = fopen((strcmp(SaveFileName,"") == 0) ? "key" : SaveFileName,"wb");
        fwrite(key,1,KEY_SIZE,file);
        fclose(file);
        printf("Key create with sucess! ✅\n");
    }
    return 0;
}