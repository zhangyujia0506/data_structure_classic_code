#include<stdio.h>
#define MAXSIZE  12500
typedef int ElemType;
typedef struct
{
    int i,j;
    ElemType e;
}Triple;

typedef struct
{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

TSMatrix a,b;

int transmat(TSMatrix a,TSMatrix b)
{
	int p,q,col,t,m;
	b.mu=a.nu;
	b.nu=a.mu;
	b.tu=a.tu;
	t=a.tu;
	if(t)
	{
		q=1;
		for(col=1;col<=a.nu;col++)
			for(p=1;p<=t;p++)
				if(a.data[p].j==col)
				{
					b.data[q].j=a.data[p].i;
					b.data[q].i=a.data[p].j; 
					b.data[q].e=a.data[p].e;
					++q;
				}
	}
	printf("���B��������� ���� �ͷ���Ԫ�ظ���\n");
	printf("\t  %d %d %d\n",b.mu,b.nu,b.tu);
	printf("���B������к� �к� �ͷ���Ԫ�ص�ֵ\n");
	for(m=1;m<=t;++m)
		printf("\t  %d %d %d\n",b.data[m].i,b.data[m].j,b.data[m].e);
	return 1;
}

int fasttran(TSMatrix a,TSMatrix b)
{
	int num[101],pot[101];
	int t,p,q,col,k,m;
	b.mu=a.nu;
	b.nu=a.mu;
	b.tu=a.tu;
	t=a.tu;
    if(t)
	{
		for(col=1;col<=a.nu;++col)
			num[col]=0;
		for(k=1;k<=t;++k)
			num[a.data[k].j]++;
		pot[1]=1;
		for(col=2;col<=a.nu;col++)
			pot[col]=pot[col-1]+num[col-1];
		for(p=1;p<=t;p++)
		{
			col=a.data[p].j;
			q=pot[col];
			b.data[q].j=a.data[p].i;
			b.data[q].i=a.data[p].j;
			b.data[q].e=a.data[p].e;
			pot[col]++;
		}
	}
    printf("���B��������� ���� �ͷ���Ԫ�ظ���\n");
	printf("\t  %d %d %d\n",b.mu,b.nu,b.tu);
	printf("���B������к� �к� �ͷ���Ԫ�ص�ֵ\n");
	for(m=1;m<=t;++m)
		printf("\t  %d %d %d\n",b.data[m].i,b.data[m].j,b.data[m].e);
	return 1;
}

void main()
{
	
	int m,t,n;
	printf("������A��������� ���� �ͷ���Ԫ�ظ���\n");
	scanf("%d %d %d",&a.mu,&a.nu,&a.tu);
	t=a.tu;
	printf("������A������к� �к� �ͷ���Ԫ�ص�ֵ\n");
	for(m=1;m<=t;++m)	
		scanf("%d %d %d",&a.data[m].i, &a.data[m].j, &a.data[m].e);
	
    printf("���A��������� ���� �ͷ���Ԫ�ظ���\n");
	printf("\t  %d %d %d\n",a.mu,a.nu,a.tu);
	printf("���A������к� �к� �ͷ���Ԫ�ص�ֵ\n");
	for(m=1;m<=t;++m)
		printf("\t  %d %d %d\n",a.data[m].i,a.data[m].j,a.data[m].e);
	while(1)
	{
		printf("������ѡ��1.��ͨת��  2.����ת�� ������������\n");
		scanf("%d",&n);
		switch(n)
		{
		case 1: transmat(a,b);
			break;
		case 2:fasttran(a,b);
			break;
		default:
			goto STOP;
		}
        
	}
STOP:;
}