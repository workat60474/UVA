#include<cstdio>
#include<algorithm>
#define N 1000001
using namespace std;
struct Edge{
int v1,v2;
int wei;
};
bool operator<(const Edge& e1,const Edge& e2)
{
	return e1.wei<e2.wei;
}
Edge e[N];
int p[N];
void init(int v)
{
	for(int i=0;i<=v;i++) p[i]=i;
}
int find(int x)
{
	return x==p[x]?x:(p[x]=find(p[x]));
}
void Union(int x,int y)
{
	p[find(x)]=find(y);
}
int kruskal(int v,int e_n)
{	
	int cost=0;
	init(v);
	int i,j;
	sort(e,e+e_n);
	for( i=0, j=0;i<v-1 && j<e_n;j++)
	{
		if(find(e[j].v1)==find(e[j].v2)) 
			continue;
		Union(e[j].v1,e[j].v2);
		cost+=e[j].wei;
		i++;
	}
	return cost;
}
int main()
{
	int n,e_n;
	int a,b,w;
	bool first=1;
	while(scanf("%d",&n)!=EOF)	
	{
		int oldcost=0,newcost;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			oldcost+=w;
		}
		int k,m;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
		scanf("%d%d%d",&e[i].v1,&e[i].v2,&e[i].wei);
		}
		scanf("%d",&m);	
		for(int i=0;i<m;i++)
		scanf("%d%d%d",&e[i+k].v1,&e[i+k].v2,&e[i+k].wei);	
		newcost=kruskal(n,k+m);
		if(first) first=false;
		else printf("\n");
		printf("%d\n%d\n",oldcost,newcost);
	}	


}
