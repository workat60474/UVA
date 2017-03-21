#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int ary[20];
int used[20];
int ans[20];
int number_cnt;
void back_track(int len,int pos){
	if(len==6){
		for(int i=0;i<len-1;i++)
		printf("%d ",ans[i]);
		printf("%d\n",ans[len-1]);
		return ;
	}
	for(int i=pos;i<number_cnt;i++){
	if(!used[i]) 
	{	used[i]=1;
		ans[len]=ary[i];
		back_track(len+1,i+1); //next time backtracking
		used[i]=0;
	} 	
	}
	
}
int main()
{	

	int change_line=0;
	while(scanf("%d",&number_cnt) && number_cnt)
	{    	
		for(int i=0;i<number_cnt;i++)
		{
			scanf("%d",&ary[i]);
			used[i]=0;		
		}
	//change line expect first input
	if(change_line>0) printf("\n");
	change_line++;
	sort(ary,ary+number_cnt);				
	back_track(0,0);			
	
	}
	return 0;
}

