#include<cstdio>
int main()
{
int sum[1005]={1,1};
int num[3000]={1};
int d=1;
int n;
for(int i=2;i<=1000;i++)
{
	for(int j=0;j<d;j++)
	{	num[j]*=i;

	}
	for(int j=0;j<d;j++)
	{	
		if(num[j]>=10) {num[j+1]+=num[j]/10;}
		if(j+1>=d && num[j+1]>0) d++;
		num[j]%=10;
		sum[i]+=num[j];

	}

}
while(scanf("%d",&n)==1)
{
	printf("%d\n",sum[n]);
}
return 0;
}
