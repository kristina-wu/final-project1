#ifndef _ARRAY_H
#define _ARRAY_H
typedef struct BitNode
{
    char c;
    struct BitNode *lchild,*rchild;
}BitNode,*BitTree;
BitNode *BinTreeCreat(BitNode *BT);
int BinTreeEmpty(BitNode *BT);
void PreOrderTraverse(BitNode *BT);
int BinTreeDepth(BitNode *BT);
void BinTreeClear(BitNode **BT);

#endif
