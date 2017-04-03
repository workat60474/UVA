#include<iostream>
#include<cstdio>
int ans=0;//q_col 傳回row 位置, index代表col進行的位置
void queen(int row_index,int q_col[8],int dr[15],int dl[15],int sum,int b[8][8])
{
	if(row_index==8) {
		if(sum>ans) ans=sum;
		return;
	}
	for(int i=0;i<8;i++)
	{
		if(!q_col[i] && !dr[(i+row_index)%15] && !dl[(i-row_index+15)%15])
		{
			q_col[i]=true;
			dr[(i+row_index)%15]=1;
			dl[(i-row_index+15)%15]=1;
			queen(row_index+1,q_col,dr,dl,sum+b[row_index][i],b);
			q_col[i]=false;
			dr[(i+row_index)%15]=0;
			dl[(i-row_index+15)%15]=0;
			
		}
	}	
}
int main(){
	int dataset;
	int board[8][8];
	while(scanf("%d",&dataset)!=EOF){
		for(int l=0;l<dataset;l++)
		{	int sum=0;
			ans=0;
			for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
			scanf("%d",&board[i][j]);
			int q_col[8]={0};
			//int q_row[8]={0};
			int dr[15]={0};
			int dl[15]={0};
			
			queen(0,q_col,dr,dl,sum,board);
			printf("%5d\n",ans);	
		}
	}

return 0;
}
