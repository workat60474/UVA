#include<cstdio>
#include<cstring>
#define N 70000
#define inf 1000000
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
struct Cow{
 int left,right;
 int max,min;
};
Cow cow[N<<1];
int value[N];
int max_n,min_n;
int lc(int i) { return 2*i;	}
int rc(int i){	return 1+2*i;	}
void build(int l,int r,int i)
{	
	cow[i].left=l;
	cow[i].right=r;
	
	if(cow[i].left==cow[i].right)
	{
		cow[i].max=cow[i].min=value[l];
		return ;
	}
	int mid=(cow[i].left+cow[i].right)/2;
	build(l,mid,lc(i));
	build(mid+1,r,rc(i));
	cow[i].max=max(cow[lc(i)].max,cow[rc(i)].max);	
	cow[i].min=min(cow[lc(i)].min,cow[rc(i)].min);
}
void query(int x1,int x2,int i)
{
	if(cow[i].left==x1 && cow[i].right==x2)
	{
		if(max_n<cow[i].max) max_n=cow[i].max;
		if(min_n>cow[i].min) min_n=cow[i].min;
		return ;
	}
	int mid=(cow[i].left+cow[i].right)/2;
	if(x1>mid) query(x1,x2,rc(i));
	else if(x2<=mid) query(x1,x2,lc(i));
	else {
		query(x1,mid,lc(i));
		query(mid+1,x2,rc(i));
	}
}
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	memset(cow,0,sizeof(cow));
	
	for(int i=1;i<=n;i++)
	scanf("%d",&value[i]);
	build(1,n,1);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		max_n=0;
		min_n=inf;
		query(a,b,1);
		
		printf("%d\n",max_n-min_n);
	}
return 0;
}
