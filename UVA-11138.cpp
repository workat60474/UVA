#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
#define N 505
int llink[N];
int rlink[N];
bool used[N];
int edge[N][N];
struct stu{
	int h;
	string gender,music,sport;
};
stu s[N];
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
	memset(llink,-1,(nl)*sizeof(int));
	memset(rlink,-1,(nr)*sizeof(int));
//	memset(llink,-1,sizeof(llink));
//	memset(rlink,-1,sizeof(rlink));
	for(int i=0;i<nl;i++)
	{
	memset(used,false,(nr)*sizeof(bool));
//	memset(used,false,sizeof(used));
	if(dfs(i,nr)) ans++;
	}
	return ans;
}
int main()
{

int t;
int c=1;
int n,m;
	scanf("%d",&t);
	while(t--)
	{
		memset(edge,0,sizeof(edge));
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int val;
				scanf("%d",&val);
				if(val) edge[i][j]=1;
			}
		}
		printf("Case %d: ",c++);
		printf("a maximum of %d nuts and bolts can be fitted together\n",bipartite(n,m));
	}

return 0;
}
