#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int smallest_period(string s){
	int p=s.length();
	int flag=0;
	string tp2;
	int s_len=s.length();
	for(int i=s_len;i>=1;i--)
	{
		//i一定要是因數
		if(s_len%i==0) 
		{	//i 代表 片段字串的長度
			//j 代表 一共有多少段
			flag=0;
			
			for(int j=1;j<s_len/i;j++)
			{	
			for(int k=0;k<i;k++)
			{
			  if(s[(j-1)*i+k]!=s[j*i+k]) 
				{
				 flag=1;
				 break;
				}
			}
			}		 	
			if(flag==0) p=s_len/i;
		}
		
	}
return p;
}
int main()
{	

	string input;

	while(1)
	{
		cin>>input;
		if(input==".") break;
		int ans=smallest_period(input);
		printf("%d\n",ans);		
		
	}
return 0;
}
