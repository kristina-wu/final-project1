#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
BitNode *BinTreeCreat(BitNode *BT) //按先序次序构造二叉树
{
    char c;
    getchar();
    if(c==' ')BT=NULL;
    else
    {
        BT->c=c;
        BT->lchild=BinTreeCreat(BT->lchild); //注意因为有返回值，必须有左值
        BT->rchild=BinTreeCreat(BT->rchild);
    }
    return BT;
}
int BinTreeEmpty(BitNode *BT)//检查二叉树是否为空
{
    if(BT==NULL)return 1;
    else return 0;
}
void PreOrderTraverse(BitNode *BT)//先序遍历树
{
    if(BT)
    {
        printf("%d",BT->c);
        PreOrderTraverse(BT->lchild);
        PreOrderTraverse(BT->rchild);
    }
}
int BinTreeDepth(BitNode *BT)//求二叉树的深度
{
    int dep1,dep2;
    if(BT==NULL)return 0;
    else
    {
        dep1=BinTreeDepth(BT->lchild);
        dep2=BinTreeDepth(BT->rchild);
        if(dep1>dep2)return 1+dep1;
        else return 1+dep2;
    }
}

void BinTreeClear(BitNode **BT)//清除二叉树
{
    if(*BT)
    {
        BinTreeClear(&(*BT)->lchild);
        BinTreeClear(&(*BT)->rchild);
        free(*BT);
        *BT=NULL;
    }
}

