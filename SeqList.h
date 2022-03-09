#define LIST_INIT_SIZE 100 //初始大小
#define LISTINCREMENT 10   //每次增量
#define OK 1
#define ERROR -1
typedef int Status;
typedef int ElemType;
typedef struct{
    int length;
    int listsize;
    ElemType *elem;
}SqList;

Status InitList_Sq(SqList* L);//初始化
Status ListInsert_Sq(SqList* L,int pos,ElemType e);//在第pos个元素之前插入
Status ListDelete_Sq(SqList* L,int pos,ElemType *x);//删除第pos个元素，并带回
Status LocateElem_Sq(SqList* L,ElemType e,Status (*compare)(ElemType,ElemType));//查找元素
//查找第一个与e满足compare()元素的位置

Status MergeList_Sq(SqList *La,SqList* Lb,SqList* Lc);//合并有序表
void printList(SqList* L);
Status f(ElemType a,ElemType b);
