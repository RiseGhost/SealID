#include "id.h"
#include <string.h>
/*
    Dada uma KEY de tamanho X. Em que X representa o número de bytes da chave, e X >= 4.
    É criado um ID tendo como base as informações da chave.
    -----------     id.key     -----------
    1º -> Gerar um id.key de tamanho 3 bytes com bytes Random;
    -----------     id.indexs  -----------
    2º -> Selecionar 3 index random da KEY.
    -----------  id.DotProduct  -----------
    3º -> Criar um array Y de tamanho 3 composto pelos valores dos 3 index random selecionado da KEY.
    4º -> Calcular o Produto escalar (Dot Product) entre o array Y e o id.key.
    -----------  id.Magnitude   -----------
    5º -> Calcular o modulo do vetor composto pelas 32 coordenadas da chave
 */

char* IDtoString(ID id){
    char* str = (char*) malloc(sizeof(char) * 34);
    sprintf(str,"#%4s-%02x%02x%02x-%02x%02x%02x-%08x-%04x",
            id.tag,
            id.key[0],id.key[1],id.key[2],
            id.indexs[0],id.indexs[1],id.indexs[2],
            id.DotProduct, id.Magnitude);
    return str;
}

int DotProduct(char* key1, char* key2, short key_length){
    int product = 0;
    for (; key_length > 0; key_length--)
        product += key1[key_length - 1] * key2[key_length - 1];
    return product;
}

char RepeatedValues(short* array, short length){
    for (short i = 0; i < length - 1; i++){
        if(array[i] == array[i+1]) return 0b1;
    }
    return 0b0;
}

void SaveInFile(const char* filename, ID *id){
    FILE* file = fopen(filename,"wb");
    fwrite(id,sizeof(ID),1,file);
    fclose(file);
}

ID ReadOfFile(const char* filename){
    ID id;
    FILE* file = fopen(filename,"rb");
    fread(&id,sizeof(ID),1,file);
    fclose(file);
    return id;
}

short Magnitude(char* key, short keylength){
    double value = 0;
    for (short index = 0; index < keylength; index++){
        value += key[index] * key[index];
    }
    return sqrt(value);
}

char CheckID(ID id, unsigned char* key, short key_length){
    unsigned char key_id[3] = {
        key[id.indexs[0]],
        key[id.indexs[1]],
        key[id.indexs[2]]
    };
    return DotProduct((char*) key_id,(char*) id.key,3) == id.DotProduct && Magnitude((char*) key,key_length) == id.Magnitude;
}

ID CreateID(unsigned char* key, short key_length, const char* tag){
    srand(time(NULL));
    ID id = {0};
    if (strlen(tag) <= 4) strcpy(id.tag,tag);
    RAND_bytes(id.key,sizeof(id.key));
    for (char i = 0; i < 3; i += !RepeatedValues(id.indexs,i+1)){
        id.indexs[i] = rand() % key_length;
    }
    unsigned char id_key[3] = { key[id.indexs[0]] , key[id.indexs[1]] , key[id.indexs[2]] };
    id.DotProduct = DotProduct((char*) id_key,(char*) id.key,3);
    id.Magnitude = Magnitude((char*) key,key_length);
    return id;
}