#include<cstdio>  
#include<cstring>  
using namespace std;  
const int N = 32010;  
int value[N];  
int level[N];  
int lower_bit(int i){  
    return i&(-i);  
}  
int sum(int x){  
    int ans = 0;  
 	while(x>0)
	{	
		ans+=value[x];
		x-=lower_bit(x);
	}
    return ans;  
}  
void add(int x,int d){  
	while(x<=N)
	{	
		value[x]+=d;
		x+=lower_bit(x);
	}
}  
int main(){  
	int n;
    while(scanf("%d",&n)!=EOF){  
        int a,b;  
        memset(value,0,sizeof(value));  
        memset(level,0,sizeof(level)); 
        for(int i=1;i<=n;i++){  
            scanf("%d%d",&a,&b);  
            ++a;   
            level[sum(a)]++;  
            add(a,1);
        }  
        for(int i=0;i<n;i++){  
            printf("%d\n",level[i]);  
        }  
    }  
    return 0;  
}  
