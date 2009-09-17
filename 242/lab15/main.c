#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "mylib.h"

void print_key(char *s)
{
  printf("%s\n",s);
}

int main(void){
  bst b;
  char word[256];

  b = bst_new();
  while(getword(word,sizeof word,stdin) != EOF){
    b = bst_insert(b,word);
  }
  bst_inorder(b,print_key);
  /*bst_preorder(b,print_key);*/
  b = bst_remove(b,"b");
  bst_inorder(b,print_key);
  b = bst_delete(b);

  return EXIT_SUCCESS;
}
