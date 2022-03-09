#include "SeqList.h"
#include<stdio.h>
#include<malloc.h>
Status f(ElemType a,ElemType b)
 {
     if (a==b) return OK;
     else return 0;
 }

Status InitList_Sq(SqList* L){
    L->elem=(ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    if(!L->elem) return ERROR;
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return OK;
}


Status ListInsert_Sq(SqList* L,int pos,ElemType e)
{
    if(pos<1||pos>L->length+1) return ERROR;
    if(L->length==L->listsize)
    {
        ElemType* newbase=(ElemType*)realloc(L->elem,(sizeof(ElemType)*(L->listsize+LISTINCREMENT)));
        if (!newbase) return ERROR;
        L->elem=newbase;
        L->listsize+=LISTINCREMENT;
    }
    
    ElemType *p;
    ElemType* q=L->elem+pos-1;//q指向被插入位置
    for(p=L->elem+L->length-1;p>=q;p--)
    {
        *(p+1)=*p;
    }
    *q=e;
    L->length++;
    return OK;
}

Status ListDelete_Sq(SqList* L,int pos,ElemType *x){
    if(pos<1||pos>L->length) return ERROR;
    
    ElemType *p,*q;
    p=L->elem+pos-1;//p指向被删元素位置
    *x=*p;
    
    q=L->elem+L->length-1;
    for(++p;p<=q;p++)
    {
        *(p-1)=*p;
    }
    L->length--;
    return OK;
}


Status LocateElem_Sq(SqList* L,ElemType e,Status (*compare)(ElemType,ElemType)){
    int i=1;
    ElemType* p=L->elem;
    while(i<=L->length&&!(*compare)(*p,e))
    {
        p++;i++;
    }
    if(i<=L->length) return i;
    return 0;
}

void printList(SqList* L)
{
    for(int i=0;i<L->length;i++)
    {
        printf("%d ",L->elem[i]);
    }
    putchar('\n');
}

Status MergeList_Sq(SqList *La,SqList* Lb,SqList* Lc){
    Lc->length=La->length+Lb->length;
    Lc->listsize=Lc->length=La->length+Lb->length;
    Lc->elem=(ElemType*)malloc(sizeof(ElemType)*Lc->length);
    
    if(!Lc->elem) return ERROR;

    ElemType* pa,*pb,*pc,*pa_last,*pb_last;
    pa=La->elem;
    pb=Lb->elem; 
    pc=Lc->elem;
    pa_last=&(La->elem[La->length-1]);
    pb_last=&(Lb->elem[Lb->length-1]);
   
    while(pa<=pa_last&&pb<=pb_last)
    {
        if(*pa<*pb){
            *pc=*pa;
            pa++;
            pc++;
        }
        else{
            *pc=*pb;
            pb++;
            *pc++;
        }
    }
    while(pa<=pa_last){
        *pc=*pa;
        pa++;
        pc++;
    }
    while(pb<=pb_last)
    {
        *pc=*pb;
         pb++;
         pc++;
    }
    return OK;
}

