#include<cstdio>
int gcd(int m,int n){
	while(n){
	int tmp=m%n;
	m=n;
	n=tmp;
	}
	return m;
}
int main(){
 int step,mod;
 char bad[]="Good Choice";
 char good[]="Bad Choice"; 
	while(scanf("%d%d",&step,&mod)!=EOF){
	if(gcd(step,mod)==1) printf("%10d%10d    %s\n\n",step,mod,bad);
		else printf("%10d%10d    %s\n\n",step,mod,good);
	}
return 0;

}
