#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 111111
struct Cow{
int start;
int end;
int id;
};
Cow cow[N];
int value[N];
int level[N];
int lower_bit(int i){ return i&(-i); }
int sum(int n)
{
	int ans=0;
	while(n>0)
	{
	ans+=value[n];			
	n-=(n&(-n));
	}
	return ans;	
}
void add(int n,int d)
{
	while(n<=N)
	{	
		value[n]+=d;
		n+=(n&(-n));
	}
}
bool cmp(Cow a,Cow b)
{
	if(a.end==b.end)	
	return a.start<b.start;
	return a.end>b.end;
}
bool equal(Cow a,Cow b)
{
	if(a.start==b.start && a.end==b.end)
	return true;
	return false;		
}
int main()
{
int n;
	while(scanf("%d",&n) && n)
	{
	 memset(value,0,sizeof(value));
	 for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&cow[i].start,&cow[i].end);
		cow[i].start++;
	//	cow[i].end++;
		cow[i].id=i;
	}
	sort(cow+1,cow+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i>1 && equal(cow[i],cow[i-1]))
	 	level[cow[i].id]=level[cow[i-1].id];
		else 
		level[cow[i].id]=sum(cow[i].start);
		add(cow[i].start,1);
	}	
	for(int i=1;i<n;i++)
	{
		printf("%d ",level[i]);
	}	
	printf("%d\n",level[n]);
	}
return 0;
}
