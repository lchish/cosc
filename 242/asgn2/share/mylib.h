/**
 * @file mylib.h
 * @author Leslie Chisholm
 * @date September 2009
 * 
 * Header information for mylib.c
 *
 */
#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>
#include <stdio.h>

extern void *emalloc(size_t);
extern void *erealloc(void *,size_t);
extern int getword(char *,int,FILE *);
extern FILE *efopen(const char *,const char *);
#endif
