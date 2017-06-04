#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 105
struct point{
	double x;
	double y;
};
int rlink[N];
int llink[N];
bool used[N];
//vector<int> edge[N];
bool edge[N][N];
bool dfs(int now,int m)
{	vector<int>::iterator iter;
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
{	int ans=0;
	memset(llink,-1,nl*sizeof(int));
	memset(rlink,-1,nr*sizeof(int));
	for(int i=0;i<nl;i++)
	{
		memset(used,false,nr*sizeof(bool));
		if(dfs(i,nr)) ans++;
	}
	return ans;
}
int main()
{
int n,m,s,v;
point gopher[N],hole[N];
	while(scanf("%d %d %d %d",&n,&m,&s,&v)!=EOF)
	{
		for(int i=0;i<n;i++)	scanf("%lf %lf",&gopher[i].x,&gopher[i].y);	
		for(int i=0;i<m;i++)	scanf("%lf %lf",&hole[i].x,&hole[i].y);
		//distance between gopher and hole
		double dis;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				dis=sqrt(pow(gopher[i].x-hole[j].x,2)+pow(gopher[i].y-hole[j].y,2));
				if(dis/v<=s) edge[i][j]=1; //survive
				else edge[i][j]=0;
				
			}
		}
		printf("%d\n",n-bipartite(m,n));
//		for(int i=0;i<=n;i++) edge[i].clear();
	}
//printf("\n");
return 0;
}
