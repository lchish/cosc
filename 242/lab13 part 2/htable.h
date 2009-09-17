#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>

typedef struct htablerec *htable;

extern htable htable_new(int capacity);
extern int htable_insert(htable h,char *s);
extern int htable_search(htable h,char *s);
extern void htable_print(htable h, FILE *stream);
extern void htable_delete(htable h);

#endif
