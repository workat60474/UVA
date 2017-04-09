#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int main()
{
 int test_num;
 map<string,int>::iterator iter;
	while(scanf("%d",&test_num)!=EOF)
	{	//printf("test=%d\n",test_num);	
		getchar();
		string tree_name;
		getline(cin,tree_name);
		//cout<<"tree_name="<<tree_name<<endl;
		int sum=0;
		for(int i=0;i<test_num;i++)
	{	
		sum=0;
		if(i>0) printf("\n");
		map<string,int>treeset;
		while(getline(cin,tree_name) && tree_name!="")	
		{
		 treeset[tree_name]++;
		 sum++;	
		}
		for(iter=treeset.begin();iter!=treeset.end();iter++)
		{ 
		 cout<<iter->first;
		 printf(" %.4f\n",(double)iter->second/sum*100);
				
		}
	 	treeset.clear();
	}	
	}

return 0;
}
