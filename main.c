#include "SeqList.h"
#include<stdio.h>
int main()
{
    SqList L,Lb,Lc;
    InitList_Sq(&L);
     for(int i=1;i<=15;i++)
    {
        ListInsert_Sq(&L,i,i*3);
    }
    ElemType x;
    printList(&L);
    ListDelete_Sq(&L,15,&x);
    printList(&L);
    printf("the deleted ele is %d \n",x);
   int flag= LocateElem_Sq(&L,33,f);
   if(flag>0){
       printf("position:%d \n",flag);
   }
   else
   {
       printf("Not Found!\n");
   }

    InitList_Sq(&Lb);
    for(int i=1;i<=5;i++)
    {
        ListInsert_Sq(&Lb,i,i);
    }
    printf("*****Lb*****\n");
    printList(&Lb);
     printf("*****Lb*****\n");
    printList(&L);
    printf("****MergeList******\n");
    
    MergeList_Sq(&L,&Lb,&Lc);
    printList(&Lc);



    

}