
#include<iostream>
#include<cstdio>
#define M 510
#define m 255
using namespace std;
int main()
{	
	int a[m],b[m];
	int a_len,b_len,c_len;	
	 string  input;

	//while loop begin
	while(getline(cin,input)){
	int c[M]={0};		
	 a_len=input.length();

	for(int i=0;i<a_len;i++) a[i]=input[a_len-i-1]-'0';
	getline(cin,input);
	 b_len=input.length();
	//printf("%d %d\n",a_len,b_len);
	for(int i=0;i<b_len;i++) b[i]=input[b_len-i-1]-'0';
	
	for(int i=0;i<a_len;i++)
	for(int j=0;j<b_len;j++)
	{
	 if(i+j<M)	c[i+j]=c[i+j]+(a[i]*b[j]);
	 if(c[i+j]>=10)
	{	
		c[i+j+1]=c[i+j+1]+c[i+j]/10;
		c[i+j]=c[i+j]%10;
	}
	}
	c_len=a_len+b_len;
	while(c[c_len-1]==0 && c_len>=2) c_len--;

	for(int i=c_len-1;i>=0;i--)
	 printf("%d",c[i]);
	printf("\n");
	}	
return 0;
}
