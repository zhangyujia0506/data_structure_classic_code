#include "Stdio.h"
#include "Conio.h"
#include "malloc.h"
#define MAXSIZE 100//行数
#define LINE  MAXSIZE-4
typedef int datatype;
typedef struct
{
	datatype data[MAXSIZE];
	int front; //头指针，队列不空指向队列头元素
	int rear;//尾指针，队列不空指向队列尾元素下一位置
}SeqQueue;

SeqQueue* InitQueue()//构造一个空的队列
{
	SeqQueue* q;
	q=(SeqQueue*)malloc(sizeof(SeqQueue));
	q->front=q->rear=0;//头指针和尾指针相等
	return q;
}
void EnQueue(SeqQueue* q,datatype x)//判断队满
{
	if((q->rear+1)% MAXSIZE == q->front) 
	exit(1);
	q->data[q->rear]=x;
	q->rear=(q->rear+1)% MAXSIZE;//队列的长度
}
datatype DeQueue(SeqQueue* q)//判断队空
{
	datatype x;
	if(q->front == q->rear) exit(1);
	x=q->data[q->front];
	q->front=(q->front+1)% MAXSIZE;
	return x;
}
int QueueEmpty(SeqQueue* q)//队列已存在
{
	return (q->front==q->rear);
}
datatype GetHead(SeqQueue* q)//Q为非空队列
{
	datatype x;
	if(q->front == q->rear) return 0;
	else
	x=q->data[q->front];
	return x;
}
void TraversalSq(SeqQueue q)
{
	do
	{
		printf("%d\t",DeQueue(&q));
	}
	while(!QueueEmpty(&q));
}
void YangHui(int n)//打印杨辉三角
{
	SeqQueue* q;
	int j,s,t;
	printf("1\n");
	q=InitQueue();
	EnQueue(q,0);  /*始*/
	EnQueue(q,1);  /*第1行*/
	EnQueue(q,1);
	for(j=1;j<=n;j++)
	{
		EnQueue(q,0); /*第j行结束符*/
		do{
			s= DeQueue(q);
			t= GetHead(q);
			if(t) printf("%d\t",t); /*非0输否则换行*/
			else printf("\n");
			EnQueue(q,s+t);//采用链队，即三角内的某一个数等于其“头顶”上两个数相加而得。
		}while(t!=0);  /*遇结束符前循环*/
	}
	DeQueue(q);
	TraversalSq(*q);
}
int main(void)
{
	int n;
	printf("请输入输出杨辉三角的行数( n >= 2 ):");
	scanf("%d",&n);
	YangHui(n-2);
	getch();
	return 0;
}