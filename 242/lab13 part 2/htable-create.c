#include <stdlib.h>
#include <stdio.h>
#include <string.h> /*for strtol*/
#include "htable.h"
#include "mylib.h"

int main(int argc,char **argv){
  long int capacity;
  htable h;
  char word[256];

  if(argc < 2){
    fprintf(stderr,"Please enter a command line argument\n");
    exit(EXIT_FAILURE);
  }
  capacity = strtol(argv[1],NULL,10);/*(const char *str, char **endptr, int base)*/

  h = htable_new(capacity);

  while(getword(word,sizeof word,stdin) != EOF){
    htable_insert(h,word);
  }

  htable_print(h,stdout);
  htable_delete(h);
  return EXIT_SUCCESS;
}
