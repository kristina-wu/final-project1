#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct node{
    int b;
    struct node * next;
}linknode,*linkstack;
   linkstack create() ;
   int isempty(linkstack h);
   int push(linkstack h,int data);
   int pop(linkstack h);

#endif
