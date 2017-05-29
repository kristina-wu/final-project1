#include<stdio.h>
#include"include/queue.h"
#include"include/stack.h"
#include"include/tree.h"
typedef struct node{
    datatype data;
    struct node * next;
}linknode,*linkstack;
typedef struct  
{  
    data_t data[N]; //用数组作为队列的储存空间  
    int front,rear; //指示队头位置和队尾位置的指针  
}sequeue_
int main
{
   char s[100];
   int a,b;
   scanf("%d",&a);
   scanf("%s",&s);
   swith(s)
   case "队列": {sequeue_t *CreateEmptySequeue();
                EmptySequeue(sequeue_t *queue);
                EnQueue(sequeue_t *queue, a);
                DeQueue(sequeue_t *queue, b);
                FullSequeue(sequeue_t *queue);
                DestroySequeue(sequeue_t *queue);
                break;
                }
   case "栈"：{linkstack create() ;
              isempty(linkstack h);
              push(linkstack h,a);
              pop(linkstack h);
              break;
              }
}
