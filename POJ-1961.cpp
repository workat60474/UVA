#include<string>
#include<iostream>
#include<cstdio>
#define max 1000001
using namespace std;
int main()
{
	int len;
	int Case=1;
	string input;
	int  next[max];
	while(scanf("%d",&len) && len)
	{
		cin>>input;
		printf("Test case #%d\n",Case++);
	
		int i;
		int cur_pos=-1;
		for(i=0,next[0]=-1;i<input.length();)
		{	
		 if(cur_pos==-1 || input[cur_pos]==input[i]) 
			{
				cur_pos++;
				i++;
				next[i]=cur_pos;
			}
		else cur_pos=next[cur_pos];
		   
		}
		
		for(int k=2;k<=len;k++) 
		if(k%(k-next[k])==0 &&  k/(k-next[k])>=2 )
		cout<<k<<" "<<k/(k-next[k])<<endl;
		cout<<endl;
	}	
return 0;
}
