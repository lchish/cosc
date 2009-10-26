#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"


struct htablerec{
   int capacity;
   int num_keys;
   int *freq;
   char **keys;
};

htable htable_new(int capacity){
   int i;
   htable result = emalloc(sizeof *result);
   result->num_keys = 0;
   result->capacity = capacity;
   result->freq = emalloc(sizeof result->freq[0] * result->capacity);
   result->keys = emalloc(sizeof result->keys[0] * result->capacity);
   for(i=0;i< result->capacity;i++){
      result->freq[i] = 0;
      result->keys[i] = NULL;
   }
   return result;
}
static unsigned int htable_step(htable h,unsigned int i_key){
  return 1 + (i_key % (h->capacity -1));
}
static unsigned int htable_word_to_int(char *word){
   unsigned int result = 0;

   while (*word != '\0'){
      result = (*word++ + 31 * result);
   }
   return result;
}

int htable_insert(htable h,char *s){

  int i = htable_word_to_int(s) % h->capacity; /* get the position of the word */
  int step = htable_step(h,i);

   /* go looking for that position */
   if(h->keys[i] == NULL){/* space is empty */
     h->keys[i] = emalloc(strlen(s) * sizeof s[0]);/*allocate memory*/
      strcpy(h->keys[i],s);/*copy string into destination*/
      h->freq[i] = 1;
      h->num_keys++;
      return 1;
   }
   else if(strcmp(h->keys[i],s) == 0){/* i is a copy of what we were looking for*/
      return h->freq[i]++;
   }
    /*position is not empty or what were looking for*/
   else{
     while(h->keys[i] != NULL && strcmp(h->keys[i],s) != 0 ){/*while the current position is not empty and is not what were looking for*/
       i +=step;
     }
     if(h->keys[i] == NULL){/*null position so fill it with something*/
       h->keys[i] = emalloc(strlen(s) * sizeof s[0]);/*allocate memory for s*/
       strcpy(h->keys[i],s);
       h->freq[i] = 1;
       h->num_keys++;
     }
     else if(strcmp(h->keys[i],s) == 0){
       h->freq[i]++;
       return h->freq[i];
     }
     else{
       return 0;/*not found*/
     }
   }
   return 0;/*silences warnings*/
}

int htable_search(htable h,char *s){
  int collisions = 0;
  int i = htable_word_to_int(s) % h->capacity;
  int step = htable_step(h,i);
  while(h->keys[i] != NULL && strcmp(h->keys[i],s) != 0 && collisions != h->capacity){
    i +=step;
    collisions++;
  }
  if(collisions == h->capacity){
    return 0;/*not found*/
  }else{
    return h->freq[i];
  }
}

void htable_print(htable h,FILE *stream){
  int i;
  for(i=0;i<h->capacity;i++){
    if(h->keys[i] != NULL){
      fprintf(stream,"Frequency: %d\tWord: %s\n",h->freq[i],h->keys[i]);
    }
  }
}

void htable_delete(htable h){
   int i;
   free(h->freq);
   for(i=0;i<h->num_keys;i++){
      free(h->keys[i]);
   }
   free(h);
}
