/**
 * @file htable.c
 * @author Leslie Chisholm
 * @date September 2009
 *
 * This file implements a hash-table ADT for the Cosc242 programming assignment
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

/**
 * Htable struct holds the capacity of the htable, the number of
 * keys it currently holds, the array of keys, the frequency of 
 * a given key and the number of collisions it took to insert the 
 * key.
 */
struct htablerec{
  int capacity;
  int num_keys;
  char **keys;
  int *freqs;
  int *stats;
  hashing_t method;
};
/**
 * Creates and allocates memory for a hash table.
 * @param capacity the capacity of the hash-table.
 * @param method hashing method to use (either linear or double)
 * @return the newly created hash-table.
 */
htable htable_new(int capacity,hashing_t method){
  int i;
  htable result = emalloc(sizeof *result);
  result->method = method;
  result->num_keys = 0;
  result->capacity = capacity;
  result->freqs = emalloc(sizeof result->freqs[0] * result->capacity);
  result->keys = emalloc(sizeof result->keys[0] * result->capacity);
  result->stats = emalloc(sizeof result->stats[0] * result->capacity);
  for(i=0;i< result->capacity;i++){
    result->freqs[i] = 0;
    result->keys[i] = NULL;
  }
  return result;
}
/**
 * Calculates a hash for a given word. Used to calculate
 * where to put keys in the hash table.
 * @param word word to calculate hash for.
 * @return the hash for the word.
 */
static unsigned int htable_word_to_int(char *word){
  unsigned int result = 0;

  while (*word != '\0'){
    result = (*word++ + 31 * result);
  }
  return result;
}
/**
 * Calculates a step to use when inserting and searching the hash table.
 * Uses either double hashing or linear probing depending on the value
 * of h->method.
 * @param h hash-table to use.
 * @param i_key the hash for the word.
 */
static unsigned int htable_step(htable h,unsigned int i_key){
  if(h->method == DOUBLE_H){
    return 1 + (i_key % (h->capacity -1));
  }
  else{
    return 1;
  }
}
/**
 * Inserts a key into the hash table.
 *
 * @param h hash-table to insert a key into.
 * @param s key to insert.
 * @return frequency of the key if successful, 0 if not.
 */
int htable_insert(htable h,char *s){
  if(h->num_keys == h->capacity){
    return 0;/*hash table is full*/
  }
  unsigned int i = htable_word_to_int(s); /* get the position of the word */
  unsigned int step = htable_step(h,i);
  i %= h->capacity;
  int collisions = 0;
    if(h->keys[i] == NULL){/* space is empty */
    h->keys[i] = emalloc(strlen(s) * sizeof s[0]+1);/*allocate memory*/
    strcpy(h->keys[i],s);/*copy string into destination*/
    h->freqs[i] = 1;
    h->stats[h->num_keys++] = 0;
    return h->freqs[i];
  }
  else if(strcmp(h->keys[i],s) == 0){/* key is already in table*/
    return h->freqs[i]++;
  }
  /*position is not empty or what were looking for*/
  else{
    /*while the current position is not what were looking for*/
    while(h->keys[i] != NULL && strcmp(h->keys[i],s) != 0 &&
	  (collisions-1) != h->capacity){
      /*increment the position were looking in and take care of wrapping*/
      i += step;
      i %= h->capacity;
      collisions++;
    }
    if(h->keys[i] == NULL){/* key not already in table*/
      h->keys[i] = emalloc(strlen(s) * sizeof s[0]+1);/*allocate memory for s*/
      strcpy(h->keys[i],s);
      h->freqs[i] = 1;
      h->stats[h->num_keys++] = collisions;
      return h->freqs[i];
    }
    else if(strcmp(h->keys[i],s) == 0){
      h->freqs[i]++;
      return h->freqs[i];
    }
    else{
      return 0;/*unable to insert hash table is full*/
    }
  }
}
/**
 * Search a hash-table for a given key.
 * @param h hash-table to search.
 * @param s key to search for.
 * @return 1 if sucessful 0 if not.
 */
int htable_search(htable h,char *s){
  int collisions = 0;
  unsigned int i = htable_word_to_int(s);
  unsigned int step = htable_step(h,i);
  i %= h->capacity;
  while(h->keys[i] != NULL && strcmp(h->keys[i],s) != 0 && collisions != h->capacity){
    i += step;
    i %= h->capacity;/*increment i and account for wrapping*/
    collisions++;
  }
  if(collisions == h->capacity){
    return 0;/*not found*/
  }else{
    return h->freqs[i];
  }
}
/**
 * Print the hash-table out to a file-stream.
 * @param h hash-table to print.
 * @param stream file-stream to print to.
 */
void htable_print(htable h,FILE *stream){
  int i;
  for(i=0;i<h->capacity;i++){
    if(h->keys[i] != NULL){
      fprintf(stream,"%d\t%s\n",h->freqs[i],h->keys[i]);
    }
  }
}
/**
 * Print all info about the hash table to a file-stream.
 * @param h hash-table to print.
 * @param stream file-stream to print to.
 */
void htable_print_entire_table(htable h, FILE *stream){
  int i;
  fprintf(stream,"Pos  Freq  Stats  Word\n");
    fprintf(stream,"----------------------------------------\n");
  for(i=0;i<h->capacity;i++){
    fprintf(stream,"%d\t%d\t%d\t%s\n",i,h->freqs[i],h->stats[i],h->keys[i]==NULL ? "": h->keys[i] );
  }
}
/**
 * Unallocates all dynamic memory allocated to a hash-table.
 * @param hash-table to delete.
 */
void htable_delete(htable h){
  int i;
  free(h->freqs);
  free(h->stats);
  for(i=0;i<h->num_keys;i++){
    free(h->keys[i]);
  }
  free(h->keys);
  free(h);
}

/* Provided code*/

/**
 *
 * Note: print_stats_line() prints a line of data when given what percent full
 * the hashtable should be as its third parameter. If the hashtable is less
 * full than that, then no data will be printed.
 *
 * @param h
 * @param stream
 * @param percent_full
 */
static void print_stats_line(htable h, FILE *stream, int percent_full) {
   int current_entries = h->capacity * percent_full / 100;
   double average_collisions = 0.0;
   int at_home = 0;
   int max_collisions = 0;
   int i = 0;

   if (current_entries > 0 && current_entries <= h->num_keys) {
      for (i = 0; i < current_entries; i++) {
         if (h->stats[i] == 0) {
            at_home++;
         }
         if (h->stats[i] > max_collisions) {
            max_collisions = h->stats[i];
         }
         average_collisions += h->stats[i];
      }

      fprintf(stream, "%4d %10d %10.1f %10.2f %11d\n", percent_full,
              current_entries, at_home * 100.0 / current_entries,
              average_collisions / current_entries, max_collisions);
   }
}
/**
 * Prints out a table showing what the following attributes were like
 * at regular intervals (as determined by num_stats) while the
 * hashtable was being built.
 *
 * @li Percent At Home - how many keys were placed without a collision
 * occurring.
 * @li Average Collisions - how many collisions have occurred on
 *  average while placing all of the keys so far.
 * @li Maximum Collisions - the most collisions that have occurred
 * while placing a key.
 *
 * @param h the hashtable to print statistics summary from.
 * @param stream the stream to send output to.
 * @param num_stats the maximum number of statistical snapshots to print.
 */

void htable_print_stats(htable h, FILE *stream, int num_stats) {
   int i;

   fprintf(stream, "\nUsing %s\n\n",
           h->method == LINEAR_P ? "Linear Probing. " : "Double Hashing.");
   fprintf(stream, "Percent   Current   Percent    Average      Maximum\n");
   fprintf(stream, " Full     Entries   At Home   Collisions   Collisions\n");
   fprintf(stream, "-----------------------------------------------------\n");
   for (i = 1; i <= num_stats; i++) {
      print_stats_line(h, stream, 100 * i / num_stats);
   }
   fprintf(stream, "-----------------------------------------------------\n\n");
}