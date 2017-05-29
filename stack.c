#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

linkstack create()   // 建立栈
{
    linkstack h;
    if((h = (linkstack)malloc(sizeof(linknode)))==NULL)
    {
        perror("malloc");
        return NULL;
    }
    h->next = NULL;
    return h;
}
int push(linkstack h,int data)  // 入栈
{
    linkstack p;
    if((p = (linkstack)malloc(sizeof(linknode)))==NULL)
    {
        perror("malloc");
        return -1;
    }
    p->b = data;
    p->next = h->next;
    h->next = p;
    return 0;
}
int isempty(linkstack h)  // 判断栈是否为空
{
    if(h->next==NULL)
    {
        printf("is empty\n");
        return 1;
    }
    return 0;
    
}
int pop(linkstack h)   // 出栈
{
    int data;
    linkstack p = NULL;
    if(isempty(h))
    {
        return 0;
    }
    p = h->next;
    h->next = p->next;
    data = p->b;
    free(p);
    return data;
    
}
