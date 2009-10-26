/**
 * @file mylib.c
 * @author Leslie Chisholm
 * @date September 2009
 * 
 * This file implements commonly used library functions for
 * allocating memory, reallocating memory, file handling 
 * and reading in words.
 *
 */

#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc,realloc,exit */
#include <assert.h> /* for assert*/
#include <ctype.h>
#include <stdio.h>

#include "mylib.h"
/**
 * Checks for errors when opening files. Exits if unable to open
 * @param filename name of file to open.
 * @param mode mode to use, r for read w for write etc.
 * @return the file if it was able to be opened.
 */
FILE *efopen(const char *filename,const char *mode)
{
  FILE *result = fopen(filename,mode);
  if(result == NULL){
    fprintf(stderr,"Can't open file '%s' using mode %s.\n",filename,mode);
    exit(EXIT_FAILURE);
  }
  return result;
}
/**
 * Checks for errors when allocating memory. Exits if unable to allocate.
 * @param s number of bytes to allocate.
 * @return pointer to allocated memory.
 */
void *emalloc(size_t s)
{
  void *result = malloc(s);
  if(result == NULL)
    {
      fprintf(stderr,"memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
  return result;
}
/**
 * Checks for errors when reallocating memory. Exits if unable to reallocate.
 * @param p pointer to old memory location.
 * @param s number of bytes to allocate.
 * @return pointer to new memory location.
 */
void *erealloc(void *p,size_t s)
{
  void *result = realloc(p,s);
  if(result == NULL)
    {
      fprintf(stderr,"memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
  return result;
}
/**
 *
 * Used to read a word from a filestream.
 * @param s 
 * @param limit maximum length of a word.
 * @param stream filestream to read words from.
 * @return word read in.
 */
int getword(char *s, int limit, FILE *stream)
{
  int c;
  char *w = s;
  assert(limit > 0 && s!= NULL && stream != NULL);

  /*Skip to the start of the word*/
  while(!isalnum(c = getc(stream)) && EOF != c)
    ;
  if(EOF == c ){
    return EOF;
  }else if(--limit > 0){/*reduce limit by 1 to allow for the \0*/
    *w++ = tolower(c);
  }
  while(--limit > 0){
    if(isalnum(c = getc(stream))){
      *w++ = tolower(c);
    }else if('\'' == c){
      limit++;
    }else{
      break;
    }
  }
  *w = '\0';
  return w-s;
}
