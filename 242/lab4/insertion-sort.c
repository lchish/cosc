#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/*Insertion sorting algorithm*/
void insertion_sort(int *a,int n){
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

int main(void){
   int my_array[ARRAY_MAX];
   clock_t start, end;
   int i,count = 0;
   /* read in input from stdin */
   while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
      count++;
   }
   /* time how long it takes the sort to run */
   start = clock();
   insertion_sort(my_array, count);
   end = clock();
   
   for(i = 0; i < count; i++){
      printf("%d\n",my_array[i]);
   }
   fprintf(stderr,"%d %f\n",count, (end - start) / (double)CLOCKS_PER_SEC);
   return EXIT_SUCCESS;
}
