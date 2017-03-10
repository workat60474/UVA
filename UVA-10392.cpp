#include<iostream>
#include<cmath>
#include<cstdio>
#define MAX 10000
int prime[MAX];
int prime_num=2; //紀錄存放在table中prime的數目

void make_prime(){
	bool flag=false;//判定是否為prime
	prime[0]=2;
	prime[1]=3;
	//初始化設定	
	for(int i=5,g=2;i<100000;i=i+g,g=6-g)
	{	
		flag=true;
	for(int j=1;prime[j]<sqrt(i);j++)
        	{
		if(i%prime[j]==0){
		flag=false ;//not a prime number
		break;		
				}
	        }
	if(flag) prime[prime_num++]=i;	
	}
}
int main(void){
  make_prime();
  long long input;
	while(scanf("%lld",&input)){
	if(input<0) break;
		for(int i=0;i<prime_num && input!=1;i++)
		{
			for(;input%prime[i]==0;input/=prime[i])
				printf("    %d\n",prime[i]);
				
		}
	if(input!=1) printf("    %lld\n",input);printf("\n");
	}		
	return 0;

}
