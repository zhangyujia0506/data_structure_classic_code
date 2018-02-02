#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define M 20
typedef struct{
	int V[M];
	int R[M][M];
	int vexnum;
} Graph;
typedef struct{
	int V[M];
	int front;
	int rear;
} Queue;
int visited[M];
void creatgraph(Graph *g,int n)
{
	int i,j,r1,r2;
	g->vexnum=n;
	for(i=1;i<=n;i++)
		g->V[i]=i;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		 g->R[i][j]=0;
	printf("Please input R(0,0 END):\n");
	scanf("%d,%d",&r1,&r2);
	while(r1!=0&&r2!=0) {
		g->R[r1][r2]=1;
		g->R[r2][r1]=1;
		scanf("%d,%d",&r1,&r2);
	}
}
void printgraph(Graph *g)
{
	int i,j;
	for(i=1;i<=g->vexnum;i++) {
		for(j=1;j<=g->vexnum;j++) {
			printf("%2d ",g->R[i][j]);
		}
		printf("\n");
	}
}
void visitvex(Graph *g,int vex)
{ 
	printf("%d ",g->V[vex]);
}
int firstadjvex(Graph *g,int vex)
{
	int w,i;
	for(i=1;i<=g->vexnum;i++) {
		if(g->R[vex][i]==1&&visited[i]==0) {
			w=i;
			break;
		} else {
			w=0;
		}
	}
	return w;
}
int nextadjvex(Graph *g,int vex,int w)
{
	int t;
	t=firstadjvex(g,w);
	return t;
}
void dfs(Graph *g,int vex)
{
	int w;
	visited[vex]=1;
	visitvex(g,vex);
	for(w=firstadjvex(g,vex);w>0;w=nextadjvex(g,vex,w))
		if(!visited[w])
			dfs(g,w);
}
void dfstraverse(Graph *g)
{
	int i;
	for(i=1;i<=g->vexnum;i++)
		visited[i]=0;
	for(i=1;i<=g->vexnum;i++)
		if(!visited[i])
			dfs(g,i);
}
void initqueue(Queue *q)
{
	q->front=0;
	q->rear=0;
}
int quempty(Queue *q)
{
	if(q->front==q->rear)
		return 0;
	else
		return 1;
}
int enqueue(Queue *q,int e)
{
	if((q->rear+1)%M==q->front) {
		printf("The queue is overflow!\n");
		return 0;
	} else {
		q->V[q->rear]=e;
		q->rear=(q->rear+1)%M;
		return 1;
	}
}
int dequeue(Queue *q) 
{
	int t;
	if(q->front==q->rear) {
		printf("The queue is empty!\n");
		return 0;
	} else {
		t=q->V[q->front];
		q->front=(q->front+1)%M;
		return t;
	}
}
void bestraverse(Graph *g) { 
	int i;
	Queue *q=(Queue *)malloc(sizeof(Queue));
	for(i=1;i<=g->vexnum;i++)
		visited[i]=0;
	initqueue(q);
	for(i=1;i<=g->vexnum;i++) {
		if(!visited[i]) {
			visited[i]=1;
			visitvex(g,g->V[i]);
			enqueue(q,g->V[i]);
			while(!quempty(q)) {
				int u,w;
				u=dequeue(q);
				for(w=firstadjvex(g,u);w>0;w=nextadjvex(g,u,w)) {
					if(!visited[w]) {
						visited[w]=1;
						visitvex(g,w);
						enqueue(q,w);
					}
				}
			}
		}
	}
}
void main() 
{ 
	int a;
	Graph *g=(Graph *)malloc(sizeof(Graph));
	char menu;
	printf("Please input the number of vertex:\n");
	scanf("%d",&a);
	creatgraph(g,a);
	printf("This is the linjiejuzhen of graph:\n");
	printgraph(g);
input:
	printf("Please input z or x or c ,Breadth_first: z  Depth_first: x quit: c\n");
	while((menu=getchar())=='\n');
	if(menu=='z') {
		printf("Breadth_first:\n");
		bestraverse(g);
		printf("\n");
		goto input;
	} else if(menu=='x') {
		printf("Depth_first:\n");
		dfstraverse(g);
		printf("\n");
		goto input;
	} else if(menu=='c') {
		exit(0);
	} else {
		printf("Input error!Please input z or x!\n");
	}
}
