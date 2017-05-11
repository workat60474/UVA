#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 501
struct Point{
	int v1,v2;
};
	Point point[N];
struct Edge{
int v1,v2;
double wei;
};
Edge e[N*N];
bool operator<(const Edge& a,const Edge &b ){
	return a.wei<b.wei;
}
int p[N];
void init(int v){
	for(int i=0;i<v;i++) p[i]=i;
}
int find(int a){
	if(a!=p[a]) p[a]=find(p[a]);
	return p[a];
}
void Union(int x,int y){
	p[find(x)]=find(y);

}
double ans[N];
void kruskal(int v,int e_n){
	init(v);
	sort(e,e+e_n);
	int i,j;
	
	for(i=0,j=0;i<v-1 && j<e_n;++j)
	{
		if(find(e[j].v1)==find(e[j].v2))
		continue;
		Union(e[j].v1,e[j].v2);	
		//printf("%d %d %.2f\n",e[j].v1,e[j].v2,e[j].wei);
		//printf("i=%d\n",i);
		ans[i]=e[j].wei;
			i++;
	}


}
int main()
{
	int testcase;
	int s,p;
	double dis;
	scanf("%d",&testcase);
	while(testcase--)
	{	//p difien the number of the city
		//s define the seattle number
		// find the s-1 lowest distance  among all of edge weight 
		scanf("%d %d",&s,&p);
		for(int i=0;i<p;i++)
		{
			scanf("%d %d",&point[i].v1,&point[i].v2);	
						
		}
		int nofe=0;
		for(int i=0;i<p;i++) {
			for(int j=0;j<p;j++)
			{
				if(i!=j) {
					dis=(double)sqrt(pow(point[i].v1-point[j].v1,2)+(pow(point[i].v2-point[j].v2,2)));
					e[nofe].v1=i;
					e[nofe].v2=j;
					e[nofe].wei=dis;
						nofe++;
					}
			}	
		}
		kruskal(p,nofe);
	//	sort(ans,ans+p);
		printf("%.2f\n",ans[p-s-1]);
		//for(int i=0;i<p;i++) 
		//printf("%.2f\n",ans[i]);
	}
return 0;
}	
