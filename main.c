#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

#include"queue.h"
#include"stack.h"
#include"tree.h"
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
    sequeue_t *CreateEmptySequeue();
    int EmptySequeue(sequeue_t *queue);
    int EnQueue(sequeue_t *queue, int x);
    int DeQueue(sequeue_t *queue, int *x);
    linkstack create() ;
   int isempty(linkstack h);
   int push(linkstack h,int data);
   int pop(linkstack h);
    BitNode *BinTreeCreat(BitNode *BT);
    int BinTreeEmpty(BitNode *BT);
    void PreOrderTraverse(BitNode *BT);
    int BinTreeDepth(BitNode *BT);
    void BinTreeClear(BitNode **BT);

    int p,*q;int t,d,r;
    r=scanf("%d",&p);
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
