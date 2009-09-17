#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100000

void insertion_sort(int *a, int *w,int n)
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

void merge(int *a,int *w,int n)
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

void merge_sort(int *a,int *w, int n)
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
      insertion_sort(a,w,n);
  }
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
    printf("%d\n", number_list[i]);
  }
  
  return EXIT_SUCCESS;
}
