#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(void){
   queue q = queue_new(3);
   q = queue_add(q,5);
   print_queue(q);
   q = queue_add(q,20);
   print_queue(q);
   q = queue_add(q,12);
   print_queue(q);
   q = queue_remove_first(q);
   print_queue(q);
   return EXIT_SUCCESS;
}
