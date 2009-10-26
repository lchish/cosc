#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* Selection sorting algorithm*/
void selection_sort(int *a,int n){
   int i,j,min,tmp;
   for(i = 0; i < n; i++){
      min = i;
      for(j = i + 1;j < n; j++){/* finds the next smallest */
         if(a[j] < a[min])
            min = j;
      }
      if(i != min){/* swaps i with the smallest */
         tmp = a[i];
         a[i] = a[min];
         a[min] = tmp;
      }
   }
}

int main(void){
   int my_array[ARRAY_MAX];
   int i,count = 0;
   clock_t start,end;
   /* read in input from stdin */
   while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
      count++;
   }
   /* time how long it takes the sort to run */  
   start = clock();
   selection_sort(my_array, count);
   end = clock();

   for(i = 0; i < count; i++){
      printf("%d\n",my_array[i]);
   }
  
   fprintf(stderr,"%d %f\n",count,(end - start) / (double)CLOCKS_PER_SEC);
   return EXIT_SUCCESS;
}
