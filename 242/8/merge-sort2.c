#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100000

void merge(int *a,int *w,int n)
{
  int i=0,j=(n/2),count = 0;/*i left half j right half*/
  while(i < n/2 && j < n - (n/2)){
    if(a[i] < a[j]){
      w[count] = a[i];
      count++;
      i++;
    }else{
      w[count] = a[j];
      j++;
      count++;
    }
    while(i < n/2){
      w[count] = a[i];
      count++;
      i++;
    }
    while(j < n - (n/2)){
      w[count] = a[j];
      count++;
      j++;
    }
  }
}

void merge_sort(int *a,int *w, int n)
{
  int i;
  if(n < 2){
    return;
  }else{
    merge_sort(a,w,n/2);/* first half */
    merge_sort(a + (n/2), w, n - (n/2));/* second half */

    merge(a,w,n);

    for(i = 0; i < n;i++){
      a[i] = w[i];
    }
  }/*else*/
}

int main(void)
{
  int i,num_items = 0;
  int number_list[ARRAY_SIZE];
  int sorted_number_list[ARRAY_SIZE];

  while(num_items < ARRAY_SIZE && 1 == scanf("%d",&number_list[num_items])){
    num_items++;
  }

  merge_sort(number_list, sorted_number_list,num_items);

  for(i = 0; i < num_items;i++){
    printf("%d\n", sorted_number_list[i]);
  }

  return EXIT_SUCCESS;
}