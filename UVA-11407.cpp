#include<cstdio>
int min(int a,int b){
 if(a>=b) return b;
 return a;
}
int main(){
	int set;
	int num;
	int method[10001];
	for(int i=0;i<10001;i++) method[i]=100000;
	method[0]=0;

	for(int i=1;i<=100;i++)
	for(int j=i*i;j<=10000;j++)
	method[j]=min(method[j],method[j-i*i]+1);


	scanf("%d",&set);
	while(set--){
	scanf("%d",&num);
	printf("%d\n",method[num]);	
	}
	
return 0;
}
