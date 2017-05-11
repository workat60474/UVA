#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 800
#define inf 100000000
double adj[N][N];
double d[N];
int parent[N];
bool visit[N];
struct Point{
	int v1,v2;
};
Point p[N];

void init(int v){
	for(int i=1;i<=v;i++) {
	//visit[i]=false;
	d[i]=inf;
	}
	for(int i=0;i<N;i++) visit[i]=false;
}
double prim(int source,int v){
	init(v);
	 d[source]=0;
	double wei=0;
	double min;
	int a;
	int b;
	 parent[source]=0;
		for(int i=1;i<=v;i++) 
	{
		min=inf;
		for(int j=1;j<=v;j++) 
			if(visit[j]==false && d[j]<min) 
			{
				min=d[j];
				a=j;
			}
		visit[a]=true;
		if(min>0) 
		{
			//printf("%d %d\n",a,parent[a]);
			wei+=min;
		}
		for( b=1;b<=v;b++) 
		{
			if(visit[b]==false && d[b]>adj[a][b])
			{
				d[b]=adj[a][b];
				parent[b]=a;
			}
		}	
	}
return wei;
}
int main(){
	
	int v;
	while(scanf("%d",&v)!=EOF)
	{
	double wei=0;
	int exist_edge;
	//scanf("%d",&v);
	for(int i=1;i<=v;i++)
	{
		scanf("%d %d",&p[i].v1,&p[i].v2);
	}
	for(int i=1;i<=v;i++) 
		for(int j=1;j<=v;j++)
		{
			if(i!=j) adj[i][j]=adj[j][i]=sqrt(pow(p[i].v1-p[j].v1,2)+pow(p[i].v2-p[j].v2,2));
		}
	scanf("%d",&exist_edge);
	int n1,n2;
		for(int i=0;i<exist_edge;i++)
		{
			scanf("%d %d",&n1,&n2);
		//	wei+=adj[n1][n2];
			adj[n1][n2]=adj[n2][n1]=0;
		}
	wei+=prim(1,v);
	printf("%.2f\n",wei);

	}
return 0;
}
