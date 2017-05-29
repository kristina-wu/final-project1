#include"include/tree.h"
Tree InitTree(){
  Tree T=NULL;
  int ch;
  ch=getchar();
  if(ch!='#'){
       T=(Tree)malloc(sizeof(TNode));
       T->firstchild=NULL;
       T->nextsibling=NULL;
       T->data=ch;
  }
  return T;
}
void deleteTree(Tree T){
    if(!T)
        return OK;
    else{
        deleteTree(T->firstchild);
        deleteTree(T->nextsibling);
        free(T);
        T=NULL;
    }
}
void TraverseTree(Tree T){
    if(T){
        visit(T->data);
        TreaverseTree(T->firstchild);
        TreaverseTree(T->nextsibling);
    }
    return 0;
}
void TreeDepth(Tree T){
    int height=0,hmax=0;
    if(T){
      Tree p=T->firstchild;
      while(p){
         height=TreeDrpth(p);
         p=p->nextsibling;
         if(hmax
            hmax=height;
      }
   }
   return hmax+1;
}
