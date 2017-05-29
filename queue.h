#ifndef _ARRAY_H
#define _ARRAY_H
typedef struct
{
    int a[60]; //用数组作为队列的储存空间
    int front,rear; //指示队头位置和队尾位置的指针
}sequeue_t;
sequeue_t *CreateEmptySequeue();
int EmptySequeue(sequeue_t *queue);
int EnQueue(sequeue_t *queue, int x);
int DeQueue(sequeue_t *queue, int *x);
int FullSequeue(sequeue_t *queue);
void DestroySequeue(sequeue_t *queue);

#endif
