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
/*先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
{ 
	if(root!=NULL)
	{ 
		Visit(root->data);       /*访问根结点*/ 
		PreOrderTraverse(root->LChild);  /*先序遍历左子树*/
		PreOrderTraverse(root->RChild);  /*先序遍历右子树*/
	}
} 

void InOrderTraverse1(BiTree root)   
/*中序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
{ 
	if(root!=NULL)
	{ 
		InOrderTraverse1(root->LChild);   /*中序遍历左子树*/
		Visit(root->data);     /*访问根结点*/
		InOrderTraverse1(root->RChild);   /*中序遍历右子树*/
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
void InOrderTraverse(BiTree root)  //二叉树中序非递归遍历   
{  
	BiTNode *p;
	p = root;  
	init(&s);
    while(p != NULL || !isEmpty(&s))  //结束条件：p为空且栈为空
	{
		if(p != NULL)  //寻找最左端的左子树
		{
			push(&s,p);  //如果节点有左子树，则该节点入栈  
			p = p->LChild;  //当前指针指向下一个左子树
		}  
		else				//左子树已遍历结束
		{  
			pop(&s,&p);		//得到要访问的节点
			Visit(p->data);  //访问节点
			p = p->RChild;  //遍历右子树
		}
	}
}

void PostOrderTraverse(BiTree root)   
/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
{ 
	if(root!=NULL)
	{ 
		PostOrderTraverse(root->LChild); /*后序遍历左子树*/
		PostOrderTraverse(root->RChild); /*后序遍历右子树*/
		Visit(root->data);    /*访问根结点*/
	}
}

void main() { 
	BiTree T; 
	printf("请输入二叉树序列:\n");
	CreateBiTree(&T); 
	printf("先序遍历序列为:");
	PreOrderTraverse(T); 
	printf("\n中序遍历序列为:"); 
	InOrderTraverse(T); 
	printf("\n中序遍历序列为:"); 
	InOrderTraverse1(T); 
	printf("\n后序遍历序列为:");
	PostOrderTraverse(T);
	getch();
}
