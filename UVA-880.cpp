#include<cstdio>
#include<cmath>
int main()
{
long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long i =sqrt(2*n)-1;
		long long sum=i*(i+1)/2;
		i++;
		while(sum+i<n) {sum+=i++;	}
		printf("%lld/%lld\n",i-n+sum+1,n-sum);
		
				
	}
return 0;
}
