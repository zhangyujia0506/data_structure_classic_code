#include <stdio.h>
#include <malloc.h>

#define bool int
#define false 0
#define true 1
#define OVERFLOW -2
typedef char DataType;
typedef struct Node
{ 
	DataType data; 
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;
typedef BiTNode* Elemtype;
typedef enum{L,R} tagtype;  
typedef struct
{
	Elemtype data[100];
	int top;
}Stack;
Stack s;
void CreateBiTree(BiTree *T)
{
	char ch;
	scanf("%c",&ch);
	if (ch==' ')   *T=NULL;
	else {
		if(!(*T=(BiTNode*)malloc(sizeof(BiTNode))))  exit(OVERFLOW);
		(*T)->data=ch;
		CreateBiTree(&(*T)->LChild);
		CreateBiTree(&(*T)->RChild);
	}
}

void Visit(char ch)
{ 
	printf("%c  ",ch);
}

void PreOrderTraverse(BiTree root)  
/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
{ 
	if(root!=NULL)
	{ 
		Visit(root->data);       /*���ʸ����*/ 
		PreOrderTraverse(root->LChild);  /*�������������*/
		PreOrderTraverse(root->RChild);  /*�������������*/
	}
} 

void InOrderTraverse1(BiTree root)   
/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
{ 
	if(root!=NULL)
	{ 
		InOrderTraverse1(root->LChild);   /*�������������*/
		Visit(root->data);     /*���ʸ����*/
		InOrderTraverse1(root->RChild);   /*�������������*/
	}
} 

void init(Stack *s)
{
	s=(Stack *)malloc(sizeof(Stack));
	s->top = -1;
}
bool isFull(Stack *s)
{
	if(s->top == 99) return true;
	else return false;
}
bool isEmpty(Stack *s)
{
	if(s->top == 0) return true;
	else return false;
}
void push(Stack *s,Elemtype elem)
{
	if(isFull(s)) return;
	s->top++;
	s->data[s->top] = elem;
}
void pop(Stack *s,Elemtype *elem)
{
    if(isEmpty(s)) return;
    *elem = s->data[s->top];
    s->top--;
}
void InOrderTraverse(BiTree root)  //����������ǵݹ����   
{  
	BiTNode *p;
	p = root;  
	init(&s);
    while(p != NULL || !isEmpty(&s))  //����������pΪ����ջΪ��
	{
		if(p != NULL)  //Ѱ������˵�������
		{
			push(&s,p);  //����ڵ�������������ýڵ���ջ  
			p = p->LChild;  //��ǰָ��ָ����һ��������
		}  
		else				//�������ѱ�������
		{  
			pop(&s,&p);		//�õ�Ҫ���ʵĽڵ�
			Visit(p->data);  //���ʽڵ�
			p = p->RChild;  //����������
		}
	}
}

void PostOrderTraverse(BiTree root)   
/* ���������������rootΪָ�������(��ĳһ����)������ָ��*/
{ 
	if(root!=NULL)
	{ 
		PostOrderTraverse(root->LChild); /*�������������*/
		PostOrderTraverse(root->RChild); /*�������������*/
		Visit(root->data);    /*���ʸ����*/
	}
}

void main() { 
	BiTree T; 
	printf("���������������:\n");
	CreateBiTree(&T); 
	printf("�����������Ϊ:");
	PreOrderTraverse(T); 
	printf("\n�����������Ϊ:"); 
	InOrderTraverse(T); 
	printf("\n�����������Ϊ:"); 
	InOrderTraverse1(T); 
	printf("\n�����������Ϊ:");
	PostOrderTraverse(T);
	getch();
}
