#include <stdlib.h>
#include "queue.h"
#include "mylib.h"

struct queuerec{
   int *items;/* what is being held in the queue*/
   int size;
   int head;
   int tail;
};
   
queue queue_new(int size){
   queue result = emalloc(sizeof *result);
   result->items = emalloc(sizeof result->items[0] * size);
   result->size = size;
   result->head = 0;
   result->tail = 0;
   return result;
}

int queue_remove(queue q){
   int x = q->items[q->head];
   if(q->head == q->size-1){
      q->head = 0;
   }else{
      q->head++;
   }
   return x;
}

void queue_add(queue q,int item){
   q->items[q->tail] = item;
   if(q->tail == q->size-1){
      q->tail = 0;
   }else{
      q->tail++;
   }
}

void print_queue(queue q){
   int i;
   for(i = q->head; i != q->tail; i++){
      printf("%d\n",q->items[i]);
   }
}

int queue_empty(queue q){
   return q->head == q->tail ? 1 : 0;
}

queue queue_delete(queue q){
   free(q->items);
   free(q);
   return q;
}
