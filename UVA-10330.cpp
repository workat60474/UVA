#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 500
#define inf 100000
#define offset 100
using namespace std;
int g[N][N],f[N][N];
int visit[N],flow[N],path[N];
int ans;

int ek(int n)
{	ans=0;
	queue<int> q;
	n=n+offset+1;
	while(1)
   {	
	memset(path,0,sizeof(path));
	memset(flow,0,sizeof(flow));
	flow[0]=inf;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v=0;v<=n;v++)
		{
			if(!flow[v] && g[u][v]>f[u][v])
			{
				path[v]=u;
				q.push(v);
				flow[v]=min(flow[u],g[u][v]-f[u][v]);
			}
		}
	}
	if(!flow[n]) break;
	else
		{
			ans+=flow[n];
			for(int u=n;u;u=path[u])
			{
				f[path[u]][u]+=flow[n];
				f[u][path[u]]-=flow[n];
			}
		}
	}
		
return ans;
}
int main()
{
int n,m;
	while(scanf("%d",&n)!=EOF)
	{	
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		scanf("%d",&g[i+offset][i]);
		scanf("%d",&m);
		int u,v,w;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u][v+offset]=w;
		}
		int a,b;
		int c;
		scanf("%d %d",&a,&b);
		for(int i=0;i<a;i++)
		{
			scanf("%d",&c);
			g[0][c+offset]=inf;
		}
		for(int i=0;i<b;i++)
		{
			scanf("%d",&c);
			g[c][n+offset+1]=inf;
		}
		printf("%d\n",ek(n));
		
	}
return 0;
}
