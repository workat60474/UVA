#include<cstdio>
#include<algorithm>
#define n 100
using namespace std;
int adj[n][n];
int visit[n];
int low[n];
int t=0;
int ap_num=0;
void init()
{	ap_num=t=0;
	for(int i=0;i<n;i++) 
	{	low[i]=visit[i]=0;
		for(int j=0;j<n;j++)
		{
			adj[i][j]=0;
		}
	}
}
void dfs(int par,int cur)
{
	visit[cur]=low[cur]=++t;
	int child =0;
	bool ap=false;
	
	for(int j=0;j<n;j++) 
		if(adj[cur][j] && j!=par)
	{
		if(visit[j]) //back edge
		{
			low[cur]=min(low[cur],visit[j]);
		}
		else 
		{
			child++;
			dfs(cur,j);
			low[cur]=min(low[cur],low[j]);
			if(low[j]>=visit[cur]) ap=true;
		}
	}	
	if((child>1 && cur==par ) || (cur!=par && ap))	
	ap_num++;
}
int main()
{
	int 	N;
	while(scanf("%d",&N)!=EOF && N)
	{
		init();
		int edge_start;
		int p;
		while(scanf("%d",&edge_start) && edge_start)
		{
			do{
				scanf("%d",&p);
				adj[p][edge_start]=adj[edge_start][p]=1;
			} 
			while(getchar()!='\n')	;
				
		}			
		dfs(1,1);//par cur
		printf("%d\n",ap_num);
	}
return 0;
}
