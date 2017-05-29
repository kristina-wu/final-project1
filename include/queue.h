#ifndef _ARRAY_H
#define _ARRAY_H
sequeue_t *CreateEmptySequeue();
int EmptySequeue(sequeue_t *queue);
int EnQueue(sequeue_t *queue, data_t x);
int DeQueue(sequeue_t *queue, data_t *x);

#endif
