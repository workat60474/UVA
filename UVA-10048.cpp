#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 100000
#define N 101
int dis[N][N];
int wei[N][N];
void floyd_warshall(int c){
	
	for(int i=1;i<=c;i++) 
		for(int j=1;j<=c;j++)
		dis[i][j]=wei[i][j];
	
	for(int k=1;k<=c;k++) 
		for(int i=1;i<=c;i++)
			for(int j=1;j<=c;j++)
			if(dis[i][j]>max(dis[i][k],dis[j][k])) 
			{
				dis[i][j]=max(dis[i][k],dis[j][k]);
			}

}
int main()
{	
	int c,s,q;//c indicate the number of nodes
		//s indicate the number of edges
		//q indicate the numbre of question given below
	int a,b,loud;
	int CASE=1;
	while(scanf("%d%d%d",&c,&s,&q)!=EOF && (c || s || q))
	{
		//init
		for(int i=1;i<=c;i++)
		{
			for(int j=1;j<=c;j++)
			{
			//	dis[j][i]=dis[i][j]=inf;
				wei[i][j]=wei[j][i]=inf;
			}
			wei[i][i]=0;
		}	
		//input
		for(int i=0;i<s;i++) {
			scanf("%d%d%d",&a,&b,&loud);
			wei[a][b]=wei[b][a]=loud;
		}
		floyd_warshall(c);
		if(CASE>1) printf("\n");
		printf("Case #%d\n",CASE++);
		for(int i=0;i<q;i++) 
		{
			scanf("%d%d",&a,&b);
			if(dis[a][b]==100000) printf("no path\n");
			else printf("%d\n",dis[a][b]);
		}
	}	

return 0;
}
