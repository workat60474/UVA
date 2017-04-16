#include<cstdio>
#define inf 1000000
struct edge{
int cost;
int u;
int v;
};
struct edge Edge[2001];
bool bellman_ford(int n,int m,int source)
{
	//detect if there is a negative edge 
	int distance[1001];
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) 
		if(i==source) distance[i]=0;
		else distance[i]=inf;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(distance[Edge[j].v]>distance[Edge[j].u]+Edge[j].cost) 
		distance[Edge[j].v]=distance[Edge[j].u] + Edge[j].cost;
	for(int i=0;i<m;i++) 
	if(distance[Edge[i].v]>distance[Edge[i].u] + Edge[i].cost)
	return true;	
	return false;
}
int main()
{
	int source=0;
	int Case;
	scanf("%d",&Case);
	while(Case!=0)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++) scanf("%d%d%d",&Edge[i].u,&Edge[i].v,&Edge[i].cost);
		if(bellman_ford(n,m,source)==true) printf("possible\n");
		else printf("not possible\n");
		Case--;		
	}	

return 0;
}
