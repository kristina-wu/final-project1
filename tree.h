#define MAX_TREE_SIZE 100
 
typedef struct{
    TElemType data;
    int parent; /* 父节点位置域 */
} PTNode;
 
typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int n; /* 节点数 */
} PTree;
void CreateTree(PTree *T){
    LinkQueue q;
    QElemType p,qq;
    int i=1,j,l;
    char c[MAX_TREE_SIZE]; /* 临时存放孩子节点数组 */ 
    InitQueue(&q); /* 初始化队列 */
    printf("请输入根节点(字符型，空格为空): ");
    scanf("%c%*c",&T->nodes[0].data); /* 根节点序号为0，%*c吃掉回车符 */
    if(T->nodes[0].data!=Nil) /* 非空树 */  {
        T->nodes[0].parent=-1; /* 根节点无父节点 */
        qq.name=T->nodes[0].data; 
        qq.num=0;
        EnQueue(&q,qq); /* 入队此节点 */
        while(i<MAX_TREE_SIZE&&!QueueEmpty(q)) /* 数组未满且队不空 */    {
            DeQueue(&q,&qq); /* 节点加入队列 */
            printf("请按长幼顺序输入节点%c的所有孩子: ",qq.name);
            gets(c);
            l=strlen(c);
            for(j=0;j<l;j++){
                T->nodes[i].data=c[j];
                T->nodes[i].parent=qq.num;
                p.name=c[j]; 
                p.num=i;
                EnQueue(&q,p); /* 入队此节点 */
                i++;
              }
          }
          if(i>MAX_TREE_SIZE){
              printf("节点数超过数组容量\n");
              exit(OVERFLOW);
          }
          T->n=i;
      }
      else
          T->n=0;
 }
 Status TreeEmpty(PTree *T){
    /* 初始条件：树T存在。操作结果：若T为空树，则返回TRUE，否则返回FALSE */  
    return T->n==0;
}
int TreeDepth(PTree *T){
    /* 初始条件：树T存在。操作结果：返回T的深度 */
    int k,m,def,max=0;
    for(k=0;k<T->n;++k){
        def=1; /* 初始化本节点的深度 */
        m=T->nodes[k].parent;
        while(m!=-1){
            m=T->nodes[m].parent;
            def++;
        }
        if(max<def)
            max=def;
    }
    return max; /* 最大深度 */
}
TElemType Root(PTree *T){
    /* 初始条件：树T存在。操作结果：返回T的根 */
    int i;
    for(i=0;i<T->n;i++)
      if(T->nodes[i].parent<0)
        return T->nodes[i].data;
    return Nil;
}
TElemType Value(PTree *T,int i){
    /* 初始条件：树T存在，i是树T中节点的序号。操作结果：返回第i个节点的值 */
    if(i<T->n)
        return T->nodes[i].data;
    else
        return Nil;
}
Status Assign(PTree *T,TElemType cur_e,TElemType value){ 
/* 初始条件：树T存在，cur_e是树T中节点的值。操作结果：改cur_e为value */  
  int j;  
  for(j=0;j<T->n;j++)
  {
    if(T->nodes[j].data==cur_e)  
    {     
       T->nodes[j].data=value;    
       return OK;   
     }  
  } 
  return ERROR;
}获取节点的父节点
TElemType LeftChild(PTree *T,TElemType cur_e)
{ /* 初始条件：树T存在，cur_e是T中某个节点 */  /* 操作结果：若cur_e是T的非叶子节点，则返回它的最左孩子，否则返回"空"*/  
  int i,j;  
  for(i=0;i<T->n;i++) 
    if(T->nodes[i].data==cur_e) /* 找到cur_e，其序号为i */     
      break;  
       for(j=i+1;j<T->n;j++) /* 根据树的构造函数，孩子的序号>其父节点的序号 */   
          if(T->nodes[j].parent==i) /* 根据树的构造函数，最左孩子(长子)的序号<其它孩子的序号 */      
              return T->nodes[j].data;  
    return Nil;
 }
 TElemType RightSibling(PTree *T,TElemType cur_e)
 { /* 初始条件：树T存在，cur_e是T中某个节点 */  /* 操作结果：若cur_e有右(下一个)兄弟，则返回它的右兄弟，否则返回"空"*/ 
    int i; 
    for(i=0;i<T->n;i++)  
     if(T->nodes[i].data==cur_e) /* 找到cur_e，其序号为i */      
      break; 
    if(T->nodes[i+1].parent==T->nodes[i].parent)  /* 根据树的构造函数，若cur_e有右兄弟的话则右兄弟紧接其后 */  
    return T->nodes[i+1].data; 
  return Nil;
 }
 void Print(PTree *T)
 { /* 输出树T。加 */  
    int i;  
    printf("节点个数=%d\n",T->n); 
    printf(" 节点 父节点\n"); 
    for(i=0;i<T->n;i++)  
    {   
      printf("    %c",Value(T,i)); /* 节点 */    
      if(T->nodes[i].parent>=0) /* 有父节点 */  
      printf("    %c",Value(T,T->nodes[i].parent)); /* 父节点 */   
      printf("\n"); 
    }
  }
  Status deleted[MAX_TREE_SIZE+1]; /* 删除标志数组(全局量) */
  void DeleteChild(PTree *T,TElemType p,int i)
  { /* 初始条件：树T存在，p是T中某个节点，1≤i≤p所指节点的度 */  /* 操作结果：删除T中节点p的第i棵子树 */  
    int j,k,n=0;  
    LinkQueue q;  
    QElemType pq,qq; 
    for(j=0;j<=T->n;j++)  
        deleted[j]=0; /* 置初值为0(不删除标记) */ 
    pq.name='a'; /* 此成员不用 */  
    InitQueue(&q); /* 初始化队列 */ 
    for(j=0;j<T->n;j++)  
        if(T->nodes[j].data==p)      break; /* j为节点p的序号 */  
    for(k=j+1;k<T->n;k++) 
    {   
       if(T->nodes[k].parent==j)      n++;  
       if(n==i)    
          break; /* k为p的第i棵子树节点的序号 */  
    }  
    if(k<T->n) /* p的第i棵子树节点存在 */ 
    {   
         n=0;    pq.num=k;    deleted[k]=1; /* 置删除标记 */    
         n++;    EnQueue(&q,pq);  
         while(!QueueEmpty(q))  
         {      
             DeQueue(&q,&qq);     
             for(j=qq.num+1;j<T->n;j++) 
             if(T->nodes[j].parent==qq.num)     
             {       
                   pq.num=j;       
                   deleted[j]=1; /* 置删除标记 */          
                   n++;       
                   EnQueue(&q,pq);    
              }   
          }  
          for(j=0;j<T->n;j++) 
              if(deleted[j]==1)   
              {       
                  for(k=j+1;k<=T->n;k++)      
                  {          
                        deleted[k-1]=deleted[k];        
                        T->nodes[k-1]=T->nodes[k];     
                        if(T->nodes[k].parent>j)       
                            T->nodes[k-1].parent--;      
                   }
                   j--;  
              }   
     T->n-=n; /* n为待删除节点数 */  
     }
 }


