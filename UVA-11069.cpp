#include<cstdio>
int main()
{
	int dp[80];
	dp[1]=1;dp[2]=2;dp[3]=2;
	for(int i=4;i<80;i++)
	dp[i]=dp[i-2]+dp[i-3];

	int num;
	while(scanf("%d",&num)==1 )
	printf("%d\n",dp[num]);
	
return 0;


}
