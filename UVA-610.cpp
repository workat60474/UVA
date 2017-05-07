#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N 1005 
int low[N];
int visit[N];
int adj[N][N];
vector<int> e[N];
int t=0;
void init(int n)
{	
	t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) adj[i][j]=0;
		low[i]=visit[i]=0;
		e[i].clear();
	}
}
void dfs(int p,int i,int n)
{
	 visit[i]=low[i]=++t;
	 for(int j=1;j<=n;j++) 
	{
		if(adj[i][j]!=0) 
		{
			if(!visit[j]) 
			{
				dfs(i,j,n);
				low[i]=min(low[i],low[j]);
				if(low[j]>visit[i]) 
				{
				printf("%d %d\n",i,j);
				printf("%d %d\n",j,i);
				}
				else printf("%d %d\n",i,j);
			}	//back edge
			else if(p!=j || (j==p &&  adj[i][j]>=2))
			{	
				low[i]=min(low[i],low[j]);
			if(visit[j]>visit[i]) printf("%d %d\n",i,j);
			}
		}
	}
}
int DFS(int i, int p) {
    visit[i] = 1;
    low[i] = ++t;
    int m = low[i];
    for(int j = 0; j < e[i].size(); j++) {
        if(!visit[e[i][j]]) {
            int b = DFS(e[i][j], i);
            if(b > low[i]) {
                printf("%d %d\n", i, e[i][j]);
                printf("%d %d\n", e[i][j], i);
            } else {
                printf("%d %d\n", i, e[i][j]);
            }
            m = min(m, b);
        } else {
            if(e[i][j] != p) {
                if(low[i] >= low[e[i][j]])
                    printf("%d %d\n", i, e[i][j]);
                m = min(m, low[e[i][j]]);
            }
        }
    }
    return m;
}
int main()
{	
	int n,m;
	int case_n=1;
	while(scanf("%d%d",&n,&m)!=EOF && n && m) 
	{	
		init(n);
		int e1,e2;
		for(int i=0;i<m;i++) 
		{
			scanf("%d%d",&e1,&e2);
			adj[e1][e2]++;
			adj[e2][e1]++;
			e[e1].push_back(e2);
			e[e2].push_back(e1);
		}
		printf("%d\n\n",case_n++);
		for(int i=1;i<=n;i++) 
		if(visit[i]==0) 
		{ t=0; DFS(i,-1);}
		printf("#\n");
	}
return 0;
}
