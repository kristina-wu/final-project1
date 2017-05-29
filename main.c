#include<stdio.h>
#include<stdlib.h>

#include"include/queue.h"
#include"include/stack.h"
#include"include/tree.h"

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
typedef struct BitNode
{
    int c;
    struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

int main()
{
    int p,*q;int t,d;
    scanf("%d",&p);
    sequeue_t *queue;
    queue=CreateEmptySequeue();
    t=EmptySequeue(queue); printf("%d",t);
    EnQueue(queue, p);
    DeQueue(queue, q);
    linkstack h;
    h=create();
    t=isempty(h); printf("%d",t);
    push(h,p);
    t=pop(h);printf("%d",t);
    BitTree T;
    T=BinTreeCreat(T);
    t=BinTreeEmpty(T);printf("%d",t);
    d=BinTreeDepth(T);
    PreOrderTraverse(T);
    BinTreeClear(&T);
    return 0;
}
