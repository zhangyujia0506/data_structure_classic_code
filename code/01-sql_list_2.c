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
void Merglist_sq(sqlist La,sqlist Lb,sqlist *Lc);

void main()
{
	sqlist La,Lb,Lc;
	int i;
	int n=5;
	ElemType e;
	/*-------------MergList-----------------*/
 	InitList_sq(&La);//初始化La，Lb
 	InitList_sq(&Lb);   
	printf("Input La:");
	for(i=1;i<=5;i++)//la,lb初值；
    {
    	scanf("%d",&e) ;
    	if(ListInsert_Sq(&La,i,e)!=OK)  break;
    }
    printf("Input Lb:");
  	for(i=1;i<=5;i++)
    {
    	scanf("%d",&e) ;
    	if(ListInsert_Sq(&Lb,i,e)!=OK)  break;
    }  	//La，Lb输出
 	for(i=1;i<=La.length;i++)     printf("La[%d]=%d\n",i-1,La.elem[i-1]); 
 	for(i=1;i<=Lb.length;i++)     printf("Lb[%d]=%d\n",i-1,Lb.elem[i-1]);  
   
	Merglist_sq(La,Lb,&Lc); //合并Lc，并输出
 	for(i=1;i<=Lc.length;i++)      printf("Lc[%d]=%d\n",i-1,Lc.elem[i-1]);
	//getch();
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

void Merglist_sq(sqlist La,sqlist Lb,sqlist *Lc){
	ElemType *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La.elem; pb = Lb.elem;
	Lc->listsize = Lc->length = La.length + Lb.length;
	pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
	if(!Lc->elem) exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while( pa <= pa_last && pb <= pb_last ) {
		if( *pa <= *pb ) *pc++ = *pa++;
		else *pc++ = *pb++; 
	}
	while( pa <= pa_last ) *pc++ = *pa++;
	while( pb <= pb_last ) *pc++ = *pb++;
}
