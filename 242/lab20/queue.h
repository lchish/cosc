#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct queuerec *queue;

extern queue queue_new(int size);
extern int queue_empty(queue q);
extern int queue_remove(queue q);
extern void queue_add(queue q, int item);
extern queue queue_delete(queue q);
#endif
