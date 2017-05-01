#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define inf 100000;
#define N 20001
struct Edge
{	
	int u;
	int wei;
};
int main()
{	
	int Case;
	scanf("%d",&Case);
	int n,m,tar_s,tar_t;
	int case_count=1;
	while(Case--)
	{	
		int _u,_v,_wei;
		int inq[N],dis[N];
		vector<Edge> chain[N];
		for(int i=0;i<N;i++)
		{
			inq[i]=0;dis[i]=inf;
		}
		//int case_count=1;
		Edge tmp1,tmp2;
		scanf("%d%d%d%d",&n,&m,&tar_s,&tar_t);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&_u,&_v,&_wei);
			tmp1.u=_u;tmp2.u=_v;
			tmp1.wei=tmp2.wei=_wei;
			chain[_u].push_back(tmp2);
			chain[_v].push_back(tmp1);
		}
		queue<int> q;
		dis[tar_s]=0;
		q.push(tar_s);
		//start spfa
		while(!q.empty()){
		int now=q.front();q.pop();
		inq[now]=0;
		for(vector<struct Edge>::iterator iter=chain[now].begin();
			iter!=chain[now].end();iter++) 
		{
			if(dis[iter->u]>dis[now]+iter->wei)
			{
				dis[iter->u]=dis[now]+iter->wei;
			 	if(inq[iter->u]==0) {
					inq[iter->u]=1;
					q.push(iter->u);
				}
			}
		}
		
	}	
		if(dis[tar_t]!=100000)	
		printf("Case #%d: %d\n",case_count++,dis[tar_t]);
		else printf("Case #%d: unreachable\n",case_count++);
	}
	return 0;
}
