#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define L 40
#define inf 100000
using namespace std;
int g[L][L],f[L][L];
int ans;
int flow[L],path[L];
int ek(int n)
{
	ans=0;
	queue<int> q;
	while(1)
	{
	memset(path,0,sizeof(path));
	memset(flow,0,sizeof(flow));
	flow[1]=inf;
	
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v=1;v<=n;v++)
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
	else{
		ans+=flow[n];
		for(int u=n;u!=1;u=path[u])
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
	int Case;
	int n,m;
	int testcase=1;
	scanf("%d",&Case);
	while(Case--)
	{
		 scanf("%d %d", &n, &m);
        int T = n+m+1;    // super sink
        memset(g, 0, sizeof(g));
        memset(f, 0, sizeof(f));
	int K;
        // Input & Build graph
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &K);
            for (int j = 1, ki; j <= K; ++j) {
                scanf("%d", &ki);
                ++g[i][n+ki];
            }
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = n+1; j <= n+m; ++j) {
                if (g[i][j]) --g[i][j];  
		 else g[j][i] = 1;         }
        }
        for (int i = n+1; i <= n+m; ++i)     
            g[i][T] = 1;
	printf("Case #%d: %d\n",testcase++,ek(T));
	}
return 0;
}
