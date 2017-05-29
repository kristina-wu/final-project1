#include"include/queue.h"

sequeue_t *CreateEmptySequeue()  //建立队
{  
    sequeue_t *queue;  
    queue = (sequeue_t *)malloc(sizeof(sequeue_t));  
    if (NULL == queue) return NULL;  
      
    queue->front = queue->rear = 0;  
  
    return queue;  
}  
void DestroySequeue(sequeue_t *queue)  // 摧毁队
{  
    if (NULL != queue)   
    {  
        free(queue);  
    }  
}  
int EmptySequeue(sequeue_t *queue)  // 判断队是否为空
{  
    if (NULL == queue)   
        return -1;  
  
    return (queue->front == queue->rear ? 1 : 0);  
}  
int FullSequeue(sequeue_t *queue)  //判读队是否满
{  
    if (NULL == queue) return -1;  
  
    return ((queue->rear + 1) % N == queue->front ? 1 : 0);  
}  
void ClearSequeue(sequeue_t *queue)  // 清空队
{  
    if (NULL == queue) return;  
      
    queue->front = queue->rear = 0;  
  
    return;  
} 
int EnQueue(sequeue_t *queue, data_t x)  //入队
{  
    if (NULL == queue) return - 1;  
  
    if (1 == FullSequeue(queue)) return -1; /* full */  
  
    queue->rear = (queue->rear + 1) % N;  
    queue->data[queue->rear] = x;  
  
    return 0;  
}  
int DeQueue(sequeue_t *queue, data_t *x)  // 出队
{  
    if (NULL == queue) return -1;  
  
    if (1 == EmptySequeue(queue)) return -1; /* empty */  
  
    queue->front = (queue->front + 1) % N;  
  
    if (NULL != x) {  
        *x = queue->data[queue->front];  
    }  
  
    return 0;  
}  

