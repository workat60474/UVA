#include<cstdio>
int main(){
	int method[7490]={0};
	int coin[5]={1,5,10,25,50};
	method[0]=1;
	for(int i=0;i<5;i++)
	for(int j=1;j<7490;j++)
	if(j>=coin[i])method[j]+=method[j-coin[i]] ;
 int input;
	while(scanf("%d",&input)!=EOF )
	printf("%d\n",method[input]);
	
return 0;
}
