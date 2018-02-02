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
	printf("输出B矩阵的行数 列数 和非零元素个数\n");
	printf("\t  %d %d %d\n",b.mu,b.nu,b.tu);
	printf("输出B矩阵的行号 列号 和非零元素的值\n");
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
    printf("输出B矩阵的行数 列数 和非零元素个数\n");
	printf("\t  %d %d %d\n",b.mu,b.nu,b.tu);
	printf("输出B矩阵的行号 列号 和非零元素的值\n");
	for(m=1;m<=t;++m)
		printf("\t  %d %d %d\n",b.data[m].i,b.data[m].j,b.data[m].e);
	return 1;
}

void main()
{
	
	int m,t,n;
	printf("请输入A矩阵的行数 列数 和非零元素个数\n");
	scanf("%d %d %d",&a.mu,&a.nu,&a.tu);
	t=a.tu;
	printf("请输入A矩阵的行号 列号 和非零元素的值\n");
	for(m=1;m<=t;++m)	
		scanf("%d %d %d",&a.data[m].i, &a.data[m].j, &a.data[m].e);
	
    printf("输出A矩阵的行数 列数 和非零元素个数\n");
	printf("\t  %d %d %d\n",a.mu,a.nu,a.tu);
	printf("输出A矩阵的行号 列号 和非零元素的值\n");
	for(m=1;m<=t;++m)
		printf("\t  %d %d %d\n",a.data[m].i,a.data[m].j,a.data[m].e);
	while(1)
	{
		printf("请输入选择：1.普通转置  2.快速转置 其它数则跳出\n");
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