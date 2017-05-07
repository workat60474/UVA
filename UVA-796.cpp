#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#define N 1010
using namespace std;
int visit[N];
int low[N];
int adj[N][N];
int t,ans;
vector< pair<int,int> > bri;
void init(int n)
{
	ans=t=0;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++) 
		adj[i][j]=0;
		low[i]=visit[i]=0;
	}
	bri.clear();
}
void dfs(int p,int i,int n)
{
	low[i]=visit[i]=++t;
	for(int j=0;j<n;j++)
	{
		if(adj[i][j])
		{
			if(!visit[j])
			{
				dfs(i,j,n);
				low[i]=min(low[i],low[j]);
				if(low[j]>visit[i])
				{
					ans++;
			bri.push_back(make_pair(min(i,j),max(i,j)));
				}
			}
			else if(j!=p) 
			{
				low[i]=min(low[i],visit[j]);
			}
		}
	}
	

}

 	
int main()
{	
	int n;
	while(scanf("%d",&n)!=EOF) 
	{	
		init(N);
		int node1,node2,nofcon;
	for(int j=0;j<n;j++)
	{
		scanf("%d",&node1);
	//	printf("node1=%d\n",node1);
		scanf(" (%d)",&nofcon);
	//	printf("number of con=%d\n",nofcon);
		for(int i=0;i<nofcon;i++)
		{
			scanf("%d",&node2);
			adj[node1][node2]=1;	
		}
	}
		for(int i=0;i<n;i++)
		if(!visit[i]) dfs(i,i,n);
		
		printf("%d critical links\n",ans);
		sort(bri.begin(),bri.end());
		for(int i=0;i<bri.size();i++)
		printf("%d - %d\n",bri[i].first,bri[i].second);
		printf("\n");
	}

	return 0;
}
