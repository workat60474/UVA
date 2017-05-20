#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
#define N 30
#define inf 100000
int path[N],flow[N];
int g[N][N],f[N][N];
int size(int n,char s)
{
	switch(s)
	{
		case 'S' :	return n;
		case 'M' :	return n+1;
		case 'L' :	return n+2;
		case 'X' :	return n+3;
		case 'T' :	return n+4;	
	}
}
int ek(int n,int source,int ter)
{
 int ans=0;
	while(1)
	{
		memset(flow,0,sizeof(flow));
		memset(path,0,sizeof(path));
		queue<int> q;
		q.push(source);
		flow[source]=inf;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int v=0;v<=ter;v++)
			{
				if(!flow[v] && g[u][v]>f[u][v])
				{
					q.push(v);
					path[v]=u;
					flow[v]=min(flow[u],g[u][v]-f[u][v]);
				}
			}
		}
		if(!flow[ter]) break;
		else
		{
			ans+=flow[ter];	
			for(int u=ter;u!=source;u=path[u])
			{
				f[path[u]][u]+=flow[ter];
				f[u][path[u]]-=flow[ter];
			}
		}
	}
return ans;
}
int main()
{
string str;
string tmp;
string end="ENDOFINPUT";
while(cin>>str && str!=end)
{
	int n;
	scanf("%d",&n);
	int s=n+5;
	int t=n+6;
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	
	for(int i=0;i<n;i++)
	{
		cin>>str;
		for(int j=size(n,str[0]);j<=size(n,str[1]);j++)
		{
			g[i][j]=1;
		}
		g[s][i]=1;
	}
	int k;
	for(int i=n;i<n+5;i++)
	{
	 scanf("%d",&k);
	 g[i][t]=k;	
	}
	cin>>tmp;
	if(ek(n,s,t)==n) printf("T-shirts rock!\n");
	else printf("I'd rather not wear a shirt anyway...\n");

}

return 0;
}
