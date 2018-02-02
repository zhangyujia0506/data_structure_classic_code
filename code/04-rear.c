#include "Stdio.h"
#include "Conio.h"
#include "malloc.h"
#define MAXSIZE 100//����
#define LINE  MAXSIZE-4
typedef int datatype;
typedef struct
{
	datatype data[MAXSIZE];
	int front; //ͷָ�룬���в���ָ�����ͷԪ��
	int rear;//βָ�룬���в���ָ�����βԪ����һλ��
}SeqQueue;

SeqQueue* InitQueue()//����һ���յĶ���
{
	SeqQueue* q;
	q=(SeqQueue*)malloc(sizeof(SeqQueue));
	q->front=q->rear=0;//ͷָ���βָ�����
	return q;
}
void EnQueue(SeqQueue* q,datatype x)//�ж϶���
{
	if((q->rear+1)% MAXSIZE == q->front) 
	exit(1);
	q->data[q->rear]=x;
	q->rear=(q->rear+1)% MAXSIZE;//���еĳ���
}
datatype DeQueue(SeqQueue* q)//�ж϶ӿ�
{
	datatype x;
	if(q->front == q->rear) exit(1);
	x=q->data[q->front];
	q->front=(q->front+1)% MAXSIZE;
	return x;
}
int QueueEmpty(SeqQueue* q)//�����Ѵ���
{
	return (q->front==q->rear);
}
datatype GetHead(SeqQueue* q)//QΪ�ǿն���
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
void YangHui(int n)//��ӡ�������
{
	SeqQueue* q;
	int j,s,t;
	printf("1\n");
	q=InitQueue();
	EnQueue(q,0);  /*ʼ*/
	EnQueue(q,1);  /*��1��*/
	EnQueue(q,1);
	for(j=1;j<=n;j++)
	{
		EnQueue(q,0); /*��j�н�����*/
		do{
			s= DeQueue(q);
			t= GetHead(q);
			if(t) printf("%d\t",t); /*��0�������*/
			else printf("\n");
			EnQueue(q,s+t);//�������ӣ��������ڵ�ĳһ���������䡰ͷ��������������Ӷ��á�
		}while(t!=0);  /*��������ǰѭ��*/
	}
	DeQueue(q);
	TraversalSq(*q);
}
int main(void)
{
	int n;
	printf("���������������ǵ�����( n >= 2 ):");
	scanf("%d",&n);
	YangHui(n-2);
	getch();
	return 0;
}