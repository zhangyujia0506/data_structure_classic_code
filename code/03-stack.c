#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "process.h"
#define OK 1
#define OVERFLOW -1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10
typedef char SElemType;
typedef int Status;

typedef struct{ 
    SElemType *base;
    SElemType *top;
    int  stacksize;         
}SqStack;

Status InitStack(SqStack *);
Status EmpyStack(SqStack *);
Status Push(SqStack*,SElemType);
Status Pop(SqStack *,SElemType *);
Status Comp(char,char);
Status brackets(SqStack *);

main(){
	SqStack S;
	printf("���������Ŵ�:");
	brackets(&S);
}
Status InitStack(SqStack *S){
	S->base=(SElemType *)malloc(STACK_INIT_SIZE *sizeof(SElemType));
	if(!S->base)exit(OVERFLOW);
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}
Status EmpyStack(SqStack *S){
	if (S->top==S->base)
	return OK;
	return ERROR;
}
Status Push(SqStack* S,SElemType e){
	if(S->top-S->base>=S->stacksize){
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)exit(OVERFLOW);
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;}
	*S->top++=e;
	return OK;
}
Status Pop(SqStack *S,SElemType *e){
	if(EmpyStack(S))return ERROR;
	*e=*--S->top;
	return OK;
}
Status Comp(char a,char b){
    if((a=='('&&b!=')')||(a=='['&&b!=']')||(a=='{'&&b!='}')){
        printf("�������Ų�ƥ��\n");
        return ERROR;}
       else return OK;
}
Status  brackets(SqStack *S){
	char a;
	char e[STACK_INIT_SIZE];
	int i;
	InitStack(S);
	gets(e);
	for(i=0;e[i]!='\0';i++){
		switch(e[i])
		{
			case '(':
			case '[':
			case '{':
			{
				Push(S,e[i]);
				break;
			}
			case ')':
			case ']':
			case '}':
			{
				if(EmpyStack(S)){
					printf("�����Ŷ���\n");
					return ERROR;break;
				} else {
					a=*(S->top-1);
					if(Comp(a,e[i])) {
						Pop(S,&e[i-1]);break;
					} else{
						printf("����ƥ�����\n");
						return ERROR;break;
					}
				}
			}
			default:
			{
				printf("ƥ�����\n");
			return ERROR;
			}
		}
	}
	if(*S->base==*S->top) {
		printf("������ȫƥ��\n"); return  OK;
	} else{
		printf("�����Ŷ���\n");return ERROR;
	} 
}
