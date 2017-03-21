#include<cstdio>
#define MAX 17
int ans[MAX];
int visited[MAX];
int prime[32];
int length;
int prime_table[]={2,3,5,7,11,13,17,19,23,29,31};
void back_track(int pos){
   //	printf("len=%d pos=%d ans[%d]=%d\n",len,pos,pos,ans[pos]);
	if(pos==length) {
		
		//confirm the head and the end of the circle
		//are added up remained prime number
	if(prime[1+ans[length]])
		{	//ans start from index 1 ans[1]=1;
			for(int i=1;i<=length-1;i++)
			 printf("%d ",ans[i]);
			printf("%d",ans[length]);
			printf("\n");
		}	
		return;
	}
	for(int i=2;i<=length;i++){
		if(!visited[i] && prime[i+ans[pos]])
		{
			visited[i]=1;
			ans[pos+1]=i;
			back_track(pos+1);
			visited[i]=0;	
		}
		
	}

	
}
int main()
{	for(int i=0;i<32;i++) prime[i]=0;
	for(int i=0;i<11;i++) prime[prime_table[i]]=1;
	for(int i=0;i<MAX;i++) visited[i]=0;
	int Case=0;
	ans[1]=1;
	while(scanf("%d",&length)!=EOF && length){
	if(Case++) printf("\n");
	printf("Case %d:\n",Case);
	
	back_track(1);	

	}
return 0;
}
