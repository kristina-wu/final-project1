#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
    datatype data;
    struct node * next;
}linknode,*linkstack;

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
int push(linkstack h,datatype data)  // 入栈
{
    linkstack p;
    if((p = (linkstack)malloc(sizeof(linknode)))==NULL)
    {
        perror("malloc");
        return -1;
    }
    p->data = data;
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
datatype pop(linkstack h)   // 出栈
{
    datatype data;
    linkstack p = NULL;
    if(isempty(h))
    {
        return 0;
    }
    p = h->next;
    h->next = p->next;
    data = p->data;
    free(p);
    return data;
    
}
void show(linkstack h)
{
    linkstack p = NULL;
    if(isempty(h))
    {
        printf("is empty!\n");
        return ;
    }
    p = h->next;
    while(p != NULL)
    {
        printf("data = %d\n",p->data);
        p = p->next;
    }

}
