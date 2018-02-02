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
		printf("�����%d���˵����룺",i);
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
			printf("���벻���Ϲ���\n");
			i--;
		}
		
		
	} 
	printf("��ɴ�����\n"); 
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
		printf("��%d���˳��У����룺%d\n",j,i); 
		m_pwd=ppHead->pwd;
		free(ppHead);
		ppHead=p->next;
	}
	i=ppHead->pwd;
	j=ppHead->num;
	printf("���һ��������%d�ţ�������:%d\n",j,i); 
	free(ppHead);
}

void main(){
 	int n,m,x;
 	LNode *ppHead=NULL;
 	printf("\n������������n��");
 	scanf("%d",&n);
    printf("�����뿪ʼ������m��");
 	scanf("%d",&m);
	createList(&ppHead,n); 
	printf("\n");
	printf("����˳��\n");
	jose(ppHead,m);
	printf("\nԼɪ����Ϸ����!\n");
}
