#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#include "mylib.h"

void print_key(char *s,colour_t c)
{
  if(c == BLACK){
  printf("black:\t%s\n",s);
  }else{
    printf("red:\t%s\n",s);
  }
}

int main(void){
  rbt b;
  char word[256];

  b = rbt_new();
  while(getword(word,sizeof word,stdin) != EOF){
    b = rbt_insert(b,word);
  }
  /*rbt_inorder(b,print_key);*/
  rbt_preorder(b,print_key);
  /*b = rbt_remove(b,"b");*/
  /*rbt_inorder(b,print_key);*/
  b = rbt_delete(b);

  return EXIT_SUCCESS;
}
