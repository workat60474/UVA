#include<cstdio>
#include<cstring>
using namespace std;
#define N 105
int llink[N];
int rlink[N];
bool used[N];
int edge[N][N];

bool dfs(int now,int m)
{
	for(int next=0;next<m;next++)
	{
		if(!used[next] && edge[now][next])
		{	
			used[next]=1;
			if(rlink[next]==-1 || dfs(rlink[next],m))
			{
				llink[now]=next;
				rlink[next]=now;
				return 1;
			}
		}
	}
		return false;
}
int bipartite(int nl,int nr)
{
	int ans=0;
//	memset(llink,-1,(nl+1)*sizeof(int));
//	memset(rlink,-1,(nr+1)*sizeof(int));
	memset(llink,-1,sizeof(llink));
	memset(rlink,-1,sizeof(rlink));
	for(int i=0;i<nl;i++)
	{
//	memset(used,false,(nr+1)*sizeof(bool));
	memset(used,false,sizeof(used));
	if(dfs(i,nr)) ans++;
	}
	return ans;
}	
int main()
{
int n,m,k;
	while(scanf("%d",&n)==1 && n)
	{
		memset(edge,0,sizeof(edge));
	 scanf("%d %d",&m,&k);
	 int x,i,y;
		for(int j=0;j<k;j++)
		{
		 scanf("%d %d %d",&i,&x,&y);
		if(x!=0 && y!=0) edge[x][y]=1;
		else edge[x][y]=0;
		}
		printf("%d\n",bipartite(n,m));
	}	
return 0;
}
