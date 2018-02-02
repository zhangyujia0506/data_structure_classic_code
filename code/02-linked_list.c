/* Note:Your choice is C IDE */
#include "stdio.h"
#include "malloc.h"
#define OK 1
#define OVERFLOW -1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct LNode{
     ElemType      data;
     struct LNode   *next;
}LNode,*LinkList;

void Print(LinkList);
void Createlist_L(LinkList *,int);
Status ListInsert_L(LinkList *,int,ElemType);
Status ListDelete_L(LinkList *,int,ElemType *);
Status MergeList_L(LinkList *, LinkList *, LinkList *);

void main()
{
    LinkList L;
	LinkList la,lb,lc;
	int i;
	ElemType e;
	//--------Create-----------------
	Createlist_L(&L,5);
	printf("The values of Linklist:\n");
	Print(L);
	//--------INSERT-----------------
	printf("The num of Linklist Insert:\n");
	scanf("%d",&i);
	printf("The values of Linklist Insert:\n");
	scanf("%d",&e);
	ListInsert_L(&L,i,e);
	printf("The values of Linklist:\n");
	Print(L);
	//--------Delete-----------------
	printf("The num of Linklist Delete:\n");
	scanf("%d",&i);
	ListDelete_L(&L,i,&e);
	printf("The values of Linklist:\n");
	Print(L);
	//-----------MergeList------------
	printf("The values of Linklist la:\n");
	Createlist_L(&la,5);
	printf("The values of Linklist lb:\n");
	Createlist_L(&lb,5);
	printf(" The la:");
	Print(la);
	printf(" The lb:");
	Print(lb);
	MergeList_L(&la,&lb,&lc);
	printf(" The lc:");
	Print(lc);
	getch();
}
void Print(LinkList L){
	LinkList p;
	p=L->next;
	while(p){printf("%d  ",p->data);p=p->next;}
	printf("\n");
}
void Createlist_L(LinkList *L,int n){
	int i;
	LinkList p;
	(*L)=(LinkList)malloc(sizeof(LNode));
	(*L)->next=NULL;
	for(i=n;i>0;--i){
    	p=(LinkList)malloc(sizeof(LNode));
    	scanf("%d",&p->data);
    	p->next=(*L)->next;
    	(*L)->next=p;
    }
}
Status ListInsert_L(LinkList *L,int i,ElemType e){
	LinkList p,s;
	int j;
	p=*L;j=0;
	while(p&&j<i-1){p=p->next;++j;}
	if(!p||j>i-1)return ERROR;
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;s->next=p->next;
	p->next=s;
	return OK;
}
Status ListDelete_L(LinkList *L,int i,ElemType *e){
	LinkList p,q;
	int j;
	p=*L;j=0;
	while(p->next&&j<i-1){
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1) return ERROR;
	q=p->next;p->next=q->next;
	*e=q->data;free(q);
	return OK;
}
Status MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc){
	LinkList pa,pb,pc;
	pa=(*La)->next;pb=(*Lb)->next;
	(*Lc)=pc=(*La);
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;pc=pa;pa=pa->next;
		} else {
			pc->next=pb;pc=pb;pb=pb->next;
		}
	}
	while(pa) {
        pc->next = pa;pa = pa->next;pc = pc->next;
    }
    while(pb) {
        pc->next = pb;pb = pb->next;pc = pc->next;
    }
}
