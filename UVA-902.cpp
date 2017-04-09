#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
int size;
string password;
map<string,int>::iterator iter;
	 while(scanf("%d",&size)!=EOF && size!=0)
	{	
		cin>>password;
		map<string,int> Map;
		
		int len=password.length();
		string ans;	
		for(int i=0;i<=len-size;i++)
	  	 {      
			ans.assign(password,i,size); 
			//cout<<ans<<endl;
			Map[ans]++;
		}	
		int max=0;
		
		for(iter=Map.begin();iter!=Map.end();iter++)
		if(iter->second > max ) 
		   	{
		   		max=iter->second;
				 ans=iter->first;
			}
		cout<<ans<<endl;
							
			    
	}
	return 0;
}
