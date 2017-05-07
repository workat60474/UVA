#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 10005
int low[N];
vector<int> adj[N];
int visit[N];
int t;
struct e{
int pos,value;
bool operator<(const e &a) const{
	if(value!=a.value) return  value>a.value;
	return pos<a.pos;
	}	
};
e d[N];
void init(int n)
{	
	for(int i=0;i<n;i++)
	{
		adj[i].clear();
		low[i]=visit[i]=0;
		d[i].value=0;	
		d[i].pos=i;
	}	
	t=0;
}
void dfs(int p,int i) 
{
	visit[i]=low[i]=++t;
	int child=0;
	for(int j=0;j<adj[i].size();j++)	
	{
		if(!visit[adj[i][j]])
		{	int c=adj[i][j];
			dfs(i,c);
			low[i]=min(low[i],low[c]);
			if(low[c]>visit[i])
			{
			d[i].value++;
			d[c].value++;
			}
		}
		else if(adj[i][j]!=p)
		{
			low[i]=min(low[i],visit[adj[i][j]]);
		}
	}
}
int main()
{
int n,m;
	while(scanf("%d%d",&n,&m)==2&& n)
	{
		int e1,e2;
		init(n);
		while(scanf("%d %d",&e1,&e2)==2 && e1!=-1)
		{	//printf("e1=%d e2=%d\n",e1,e2);
			adj[e1].push_back(e2);
			adj[e2].push_back(e1);
		}
		for(int i=0;i<n;i++)
		if(!visit[i]) dfs(i,i);
		
		for(int i=0;i<n;i++) 
		if(d[i].value!=adj[i].size()) d[i].value++;

		sort(d,d+n);
		for(int i=0;i<m;i++) 
		printf("%d %d\n",d[i].pos,d[i].value);
		printf("\n");
	}
return 0;
}
