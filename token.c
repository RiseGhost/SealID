#include "token.h"
#include <string.h>

token CreateSignature(){
  token s;
  RAND_bytes(s.key,KEY_SIZE);
  s.id = CreateID(s.key,KEY_SIZE);
  return s;
}

char* SignatureToString(token s){
  char* str_id = IDtoString(s.id);
  const char prefix[] = "Key - ";
  char* str = (char*) malloc(strlen(prefix) + KEY_SIZE * 2 + strlen(str_id) + 6);
  strcpy(str,prefix);
  for (short index = 0; index < KEY_SIZE ; index++){
    sprintf(&str[strlen(prefix) + index * 2],"%02x",s.key[index]);
  }
  sprintf(&str[KEY_SIZE * 2 + strlen(prefix)],"\tId - %s",str_id);
  free(str_id);
  return str;
}