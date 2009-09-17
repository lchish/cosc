#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"
#include "flexarray.h"

struct flexarrayrec
{
  int capacity;
  int itemcount;
  int *items;
};

flexarray flexarray_new()
{
  flexarray result = emalloc(sizeof *result);
  result->capacity =2;
  result->itemcount = 0;
  result->items = emalloc(result->capacity * sizeof result->items[0]);
  return result;
}

void flexarray_append(flexarray f, int num)
{
  if(f->itemcount == f -> capacity)
    {
      f->capacity += f->capacity;
      f->items = erealloc(f->items,f->capacity * sizeof f->items[0]);
    }
  f->items[f->itemcount++] = num;/* increment itemcount and put the num in it */
}

void flexarray_print(flexarray f)
{
  int i;
  for(i=0; i < f->itemcount;i++)
    {
      printf("%d\n",f->items[i]);
    }
}

static void insertion_sort(int *a,int n)
{
  int p,key,j;
  for(p = 1; p < n; p++){
    key = a[p];
    j = p -1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];/* swap positions */
      j = j-1;
    }
    a[j+1] = key;/* put key in the leftmost vacated poistion */
  }
}

static void merge(int *a,int *w,int n)
{
  int i=0,j=(n/2),count = 0;/*i left half j right half*/
  while(i < n/2 && j < n){
    if(a[i] < a[j]){
      w[count] = a[i];
      i++;
    }else{
      w[count] = a[j];
      j++;
    }
    count++;
  }
  while(i < n/2){
    w[count] = a[i];
    count++;
    i++;
  }
  while(j < n){
    w[count] = a[j];
    count++;
    j++;
  }
}

static void merge_sort(int *a,int *w, int n)
{
  int i;
  if(n < 2){
    return;
  }else if(n>42){
    merge_sort(a,w,n/2);/* first half */
    merge_sort(a + (n/2), w, n - (n/2));/* second half */ 

    merge(a,w,n);

    for(i = 0; i < n;i++){
      a[i] = w[i];
    }
  }else{
      insertion_sort(a,n);
  }
}

void flexarray_sort(flexarray f)
{
  int *workspace = emalloc(f->itemcount * sizeof f->items[0]);
  merge_sort(f->items,workspace,f->itemcount);
  free(workspace);
}

void flexarray_delete(flexarray f)
{
  free(f->items);
  free(f);
}
