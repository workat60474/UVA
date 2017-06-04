#include<cstdio>
#include<cstring>
using namespace std;
#define N 105
int llink[N];
int rlink[N];
bool used[N];
int edge[N][N];

bool dfs(int now,int m,int u,int v)
{
	for(int next=0;next<m;next++)
	{
		if(!used[next] && edge[now][next] && (now!=u || next!=v))
		{	
			used[next]=1;
			if(rlink[next]==-1 || dfs(rlink[next],m,u,v))
			{
				llink[now]=next;
				rlink[next]=now;
				return 1;
			}
		}
	}
		return false;
}
int bipartite(int nl,int nr,int u,int v)
{
	int ans=0;
	memset(llink,-1,(nl)*sizeof(int));
	memset(rlink,-1,(nr)*sizeof(int));
//	memset(llink,-1,sizeof(llink));
//	memset(rlink,-1,sizeof(rlink));
	for(int i=0;i<nl;i++)
	{
	memset(used,false,(nr)*sizeof(bool));
//	memset(used,false,sizeof(used));
	if(dfs(i,nr,u,v)) ans++;
	}
	return ans;
}	
int main()
{
	int n;
	int xmax[N],ymax[N];
	int xmin[N],ymin[N];
	int C=1;
	while(scanf("%d",&n) && n)
	{	memset(edge,0,sizeof(edge));
		for(int i=0;i<n;i++)
		{scanf("%d %d %d %d",&xmin[i],&xmax[i],&ymin[i],&ymax[i]);}

		int x,y;

		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			for(int j=0;j<n;j++ )
			{
			if(xmin[j]<=x && x<=xmax[j] && ymin[j]<=y && y<=ymax[j])
			edge[j][i]=1;
			}
		}
		int ans=bipartite(n,n,-1,-1);
		int res[N];
		bool flag=false;
		for(int i=0;i<n;i++) res[i]=llink[i];
		printf("Heap %d\n",C++);
		for(int i=0;i<n;i++)
		{
			if(bipartite(n,n,i,res[i])<ans)
			{
			 if(flag) printf(" ");
			 printf("(%c,%d)",(i+'A'),res[i]+1);
			 flag=1;
			}
		}
		if(!flag) printf("none");
		printf("\n\n");
	}


return 0;
}
