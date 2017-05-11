#include<cstdio>
#include<algorithm>
using namespace std;
#define N 750
#define inf -100000000
int p[N];
struct Edge{
	int a,b;
	int wei;
};
Edge e[N*N];
bool operator<(const Edge &a,const Edge &b){
	return a.wei<b.wei;
}
int find(int a){
	if(a!=p[a]) p[a]=find(p[a]);
	return p[a];
}
void Union(int x,int y){
	p[find(x)]=find(y);
}
void init(int v){
	for(int i=0;i<v;i++)
	{
		p[i]=i;
	}
}
int kruskal(int v,int en){
//	init(v);
	sort(e,e+en);
	int min;
	reverse(e,e+en);
	int i,j;
	for(i=0,j=0;i<v-1 && j<en;j++)
	{
		if(find(e[j].a)==find(e[j].b)) continue;
		Union(e[j].a,e[j].b);
		i++;
		if(i==v-1) min=e[j].wei;
	}
	return min;
}
int main(){
	int c;
	int Case=1;
	scanf("%d",&c);
	while(c--)
	{	
		int n,m;
		int a,b,w;
		scanf("%d %d",&n,&m);
		init(n);
		int en=0;
		for(int i=0;i<m;i++)
		{	
			scanf("%d %d %d",&a,&b,&w);
			if(a!=b) {
			e[en].a=a;e[en].b=b;e[en].wei=w;
			en++;	
			}
		}
		printf("Case #%d: %d\n",Case++,kruskal(n,en));	
	}	
}
