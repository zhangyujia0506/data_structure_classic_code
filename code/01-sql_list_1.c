/* Note:Your choice is C IDE */
#include "stdio.h"
#include "malloc.h"
#define OK 1
#define OVERFLOW -1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef int Status;
typedef  struct{
	ElemType  *elem;
	int  length;
	int  listsize;
} sqlist;

Status InitList_sq(sqlist *L);
Status ListInsert_Sq(sqlist *L,int i,ElemType e);
Status ListDelete_Sq(sqlist *L,int i,ElemType *e);

void main()
{
	sqlist La;
	int i;
	int n=5;
	ElemType e;
	/*------------------INIT-----------------*/
	if(InitList_sq(&La)) {
		printf("Inite is ok!\n");
   		printf("Length: %d\n",La.length);
    	printf("Listsize: %d\n\n",La.listsize);
  	} else {
  		printf("error!");
	}
	/*--------------顺序表La输入初始值---------------*/
	printf("Please input the values of sq:\n");
	for(i=1;i<=n;i++) {
		scanf("%d",&e) ;
    	if(ListInsert_Sq(&La,i,e)!=OK)  break;
 	}
	for(i=1;i<=La.length;i++)
  		printf("e[%d]=%d\n",i-1,La.elem[i-1]);
	printf("Length: %d\n\n",La.length);
	/*-------------INSERT-----------------*/
	printf("Please input the place of insert:\n");
	scanf("%d",&i);
	printf("Please input the elemvalue:\n");
	scanf("%d",&e);
	if(ListInsert_Sq(&La,i,e)==OK){
  		for(i=1;i<=La.length;i++)
  			printf("e[%d]=%d\n",i-1,La.elem[i-1]);
    	printf("Length: %d\n\n",La.length);
	}
	/*-------------DELETE----------------*/
	printf("Please input the place of delete:\n");
	scanf("%d",&i);
	if(ListDelete_Sq(&La,i,&e)==OK)
		printf("The deleted elem is: %d\n",e);
	for(i=1;i<=La.length;i++)
    	printf("e[%d]=%d\n",i-1,La.elem[i-1]);
	printf("Length: %d\n",La.length);
    getch();
}

/*-------------初始化顺序表L----------*/
Status InitList_sq(sqlist *L){
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) exit(OVERFLOW);
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}
/*------------顺序表L插入----------*/
Status ListInsert_Sq(sqlist *L,int i,ElemType e){
	ElemType *newbase,*p,*q;
	if(i<1||i>L->length+1) return ERROR;
	if(L->length>=L->listsize){
		newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*
		sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L->elem=newbase;
		L->listsize=L->listsize+LISTINCREMENT;
	}
	q=&(L->elem[i-1]);
	for(p=&(L->elem[L->length-1]);p>=q;--p) *(p+1)=*p;
	*q=e;
	++L->length;
	return OK;
}
/*------------顺序表L删除----------*/
Status ListDelete_Sq(sqlist *L,int i,ElemType *e){
	ElemType *p,*q;
	if(i<1||i>L->length) return ERROR;
	p=&(L->elem[i-1]);
	*e=*p;
	q=L->elem+L->length-1;
	/*printf("%d,%d,%d,%d",p,L->elem,L->length,q);*/
	for(++p;p<=q;++p) *(p-1)=*p;
	--L->length;
	return OK;
}
