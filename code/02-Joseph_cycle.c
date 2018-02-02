#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int num;
	int pwd;
	struct LNode *next;
}LNode;
LNode *createNode(int m_num,int m_pwd)
{
	LNode *p;
	p=(LNode *)malloc(sizeof(LNode));
	
	p->num=m_num;
	p->pwd=m_pwd;
	p->next=NULL;
	return p; 
} 
void createList(LNode **ppHead,int n)
{
	int i,m_pwd;
	LNode *p,*cur;
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个人的密码：",i);
		scanf("%d",&m_pwd);
		if(m_pwd>0){
			
		p=createNode(i,m_pwd);
		if(*ppHead==NULL)
		{
			*ppHead=cur=p;
			cur->next=*ppHead;
		} else {
			p->next = cur->next;
			cur->next = p;
			cur= p;
		} 
		}else{
			printf("密码不符合规则\n");
			i--;
		}
		
		
	} 
	printf("完成创建！\n"); 
} 

void jose(LNode *ppHead,int m_pwd)
{
	int i,j;
	LNode *p,*p_del;
	for(i=1;p!=ppHead;i++){
		for(j=1;j<m_pwd;++j){
			p=ppHead;
			ppHead=ppHead->next;
		}
		p->next = ppHead->next;
		i=ppHead->pwd;
    	j=ppHead->num;
		printf("第%d个人出列，密码：%d\n",j,i); 
		m_pwd=ppHead->pwd;
		free(ppHead);
		ppHead=p->next;
	}
	i=ppHead->pwd;
	j=ppHead->num;
	printf("最后一个出列是%d号，密码是:%d\n",j,i); 
	free(ppHead);
}

void main(){
 	int n,m,x;
 	LNode *ppHead=NULL;
 	printf("\n请输入总人数n：");
 	scanf("%d",&n);
    printf("请输入开始上限数m：");
 	scanf("%d",&m);
	createList(&ppHead,n); 
	printf("\n");
	printf("出队顺序：\n");
	jose(ppHead,m);
	printf("\n约瑟夫环游戏结束!\n");
}
