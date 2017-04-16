#include<cstdio>
#include<queue>
using namespace std;
#define inf 1000000
#define N 100
void init(int w[N][N],int d[N],int inq[N],int f[N]){
	for(int i=0;i<N;i++)
	{
		d[i]=inf;
		inq[i]=0;
		f[i]=-1;
		for(int j=0;j<N;j++) 
		w[i][j]=inf;
	}

}
int abs(int n){
	if(n<0) return -1*n;
	return n;
}
int main()
{
int time[6],wei[N][N],dis[N],inq[N],floor[N];
//init
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{	
		
		for(int i=0;i<n;i++) 
		 scanf("%d",&time[i])	;

		init(wei,dis,inq,floor);			
		for(int i=0;i<n;i++)
		{	
			int cnt=0;
			do{
			scanf("%d",&floor[cnt++]);
			}while(getchar()!='\n');
			//cnt代表電梯i會停靠的樓層數
			for(int j=0;j<cnt;j++)
			{
				for(int k=j;k<cnt;k++)
				{
					int tmp=abs(floor[j]-floor[k])*time[i];
					if(tmp<wei[floor[j]][floor[k]])
					{
						wei[floor[j]][floor[k]]=tmp;
						wei[floor[k]][floor[j]]=tmp;
					}
				}
			}
		}
		//do spfa
		queue<int> q;
			//0 is source
		dis[0]=0;
		q.push(0);
		while(!q.empty()){
		int now=q.front();q.pop();
		inq[now]=0;
			for(int i=0;i<N;i++) 
			{
				if( dis[i]>dis[now]+wei[now][i]+60) 
				{
					dis[i]=dis[now]+wei[now][i]+60;
					if(inq[i]==0)
					{
						inq[i]=1;
						q.push(i);
					}
				}
			}
	
		}//end of spfa
	if(k==0) printf("0\n");
	else if(dis[k]!=inf) printf("%d\n",dis[k]-60);
	else printf("IMPOSSIBLE\n");
	}//end of while

return 0;
}
