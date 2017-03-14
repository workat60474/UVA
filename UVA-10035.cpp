#include<string>
#include<cstdio>
#include<iostream>
#define max 11
using namespace std;
int main()
{
        //	int num1[max]={0};
       //	int num2[max]={0};
	int len1,len2;
	string input1,input2;
	int carry_cnt=0;
	while(getline(cin,input1,' '))
	{	//	if(input=="0") break;
			len1=input1.length();
			int num1[max]={0};
			int num2[max]={0};
			for(int i=0;i<len1;i++) num1[len1-i-1]=input1[i]-'0'; 
			getline(cin,input2);//seperate by a new line char
			len2=input2.length();
			for(int i=0;i<len2;i++) num2[len2-i-1]=input2[i]-'0';
			if(input1=="0" && input2=="0") break;
		//	for(int i=max-1;i>=0;i--) printf("%d",num1[i]);
		//	printf("\n");
		//	for(int i=max-1;i>=0;i--) printf("%d",num2[i]);
		//	printf("\n");
			for(int i=0;i<max;i++){
			num1[i]+=num2[i];
				if(num1[i]>=10) 
				{
					carry_cnt++;
					num1[i+1]++;
					num1[i]-=10;
				} 
			}	
	//print out
	if(!carry_cnt) printf("No carry operation.\n");
	else if(carry_cnt==1) printf("%d carry operation.\n",carry_cnt);
	else printf("%d carry operations.\n",carry_cnt);
	carry_cnt=0;	
	}
return 0;
}

