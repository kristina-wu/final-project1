#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/create queue.h"
#include"include/empty queue.h"
#include"include/enqueue.h"
#include"include/dequeue.h"
#include"include/create stack.h"
#include"include/empty stack.h"
#include"include/push stack.h"
#include"include/pop.h"
#include"include/inittree.h"
#include"include/insert tree.h"
#include"include/delete tree.h"
#include"include/travel tree.h"
#include"include/tree depth.h"
#define N 64  //队列中数据元素的数据类型  
typedef struct  
{  
    int a[N]; //用数组作为队列的储存空间  
    int front,rear; //指示队头位置和队尾位置的指针  
}sequeue_t;
typedef struct node{
    int b;
    struct node * next;
}linknode,*linkstack;
typedef struct CSNode{
      char c;
      struct SCNode *firstchild,*nextsibling;
}TNode,*Tree;

int main()
{
   int p,*q;int t;
   scanf("%d",&p);
   sqeueue_t *queue;
   queue=CreateEmptySequeue();
   t=EmptySequeue(*queue); printf("%d",t);
   EnQueue(*queue, p);
   DeQueue(*queue, *q);
   linkstack h;
   h=linkstack create();
   t=isempty(h); printf("%d",t);
   push(h,p);
   t=pop(h);printf("%d",t);
   Tree T;
   T=InitTree();
   TraverseTree(T);
   TreeDepth(T);
   deleteTree(T);
   return 0;  
}
