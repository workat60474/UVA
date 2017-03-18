#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define max 1001
using namespace std;
int gcd(int a,int b){
	int c;
	while(a){
		c=a;
		a=b%a;
		b=c;
	}
	return b;
}
int main(){
	int  input[max];
	int cnt=0;
	while(scanf("%d",&input[cnt]) && input[cnt]){
	//if first input equal to zero stop here and skip last zero
	cnt++;
	while((scanf("%d",&input[cnt])) && input[cnt])
	cnt++;
	sort(input,input+cnt);
	
//	for(int i=0;i<cnt;i++) printf("%d  ",input[i]);	printf("\n");

	int min_gcd=999999987;
	int c_gcd;
	for(int i=1;i<cnt;i++) input[i]-=input[0];
	input[0]=0;
//	for(int i=0;i<cnt;i++) printf("%d  ",input[i]); printf("\n");
	
	int break_flag=0;
	if(cnt==2) {
	min_gcd=input[1]-input[0];
	}

	else 	
	for(int i=1;i<cnt && !break_flag;i++)
	{
		for(int j=i+1;j<cnt;j++)
		{
			c_gcd=gcd(input[i],input[j]);
	//		printf("c_gcd=%d min_gcd=%d input[%d]=%d input[%d]=%d\n",c_gcd,min_gcd,i,input[i],j,input[j]);
			if(c_gcd==1) {
				min_gcd=1;
				break_flag=1;
				break;
			}	
			if(c_gcd<min_gcd)
			min_gcd=c_gcd;
		}
	}
	printf("%d\n",min_gcd);
		
	cnt=0;
}				
	
	return 0;
}
