#include<cstdio>
#include<vector>
using namespace std;
#define max 10000
int main()
{	
	int case_n=1;
//	int lis[max];	
	while(1)	{
	int height;
	vector<int> hei;

	scanf("%d",&height);
	if(height==-1) break;
	hei.push_back(height);

 	while(scanf("%d",&height) && height!=-1)
	hei.push_back(height);
	int l=hei.size()-1;
	int lis[l];
	int length=0;
	for(int i=l;i>=0;i--)
	{
		lis[i]=1;
	} 		

	for(int i=l;i>=0;i--) 
	{
		for(int j=l;j>i;j--) 
		{
//			printf("j=%d i=%d\n",hei[j],hei[i]);
			if(hei[j]<hei[i] && lis[i]<lis[j]+1) lis[i]=lis[j]+1;
//			printf("i:lis[%d]=%d\n",i,lis[i]);
//			printf("j:lis[%d]=%d\n",j,lis[j]);
		}
		if(lis[i]>length)	length=lis[i];	
	}
	
	
	if(case_n!=1) printf("\n");
	printf("Test #%d:\n",case_n++); 
	printf("  maximum possible interceptions: %d\n",length);

	
	 	
}
return 0;
}
