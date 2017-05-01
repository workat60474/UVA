#include<cstdio>
using namespace std;
#define inf 100000
int dis[101];
struct Edge{
	int p;
	int q;
};
Edge edge[10001];
int main()
{
int nofcase,start,_p,_q;
int cnt=0;
int CASE=1;
 	while(scanf("%d",&nofcase)!=EOF && nofcase)
	{	
		cnt=0;
		scanf("%d",&start);
		for(int i=1;i<=nofcase;i++) 	
		dis[i]=inf;
		dis[start]=0;
		
		while(scanf("%d%d",&edge[cnt].p,&edge[cnt].q))	
		{
			if(edge[cnt].p==0 && edge[cnt].q==0) break;
			cnt++;
			//cnt specify the number of edge
		}
		//bellman ford		
		for(int i=0;i<nofcase;i++) 
		{
			for(int j=0;j<cnt;j++)
			if(dis[edge[j].p]<dis[edge[j].q]+1)
			dis[edge[j].q]=dis[edge[j].p]-1;
		}
		int min_len=0;
		int final_node;
		for(int i=1;i<=nofcase;i++)
		if(dis[i]<min_len) 
		{	min_len=dis[i];
			final_node=i;
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",CASE++,start,-1*min_len,final_node);
	}		
return 0;
}
