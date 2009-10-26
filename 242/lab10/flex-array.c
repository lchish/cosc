#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"
#include "flexarray.h"

int main(void)
{
  int item;
  flexarray f1 = flexarray_new();

  while(1 == scanf("%d",&item))
    {
      flexarray_append(f1,item);
    }
  flexarray_sort(f1);
  flexarray_print(f1);
  flexarray_delete(f1);

  return EXIT_SUCCESS;
}
