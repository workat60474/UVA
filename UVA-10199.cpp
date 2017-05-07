#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
using namespace std;
#define n 105
vector<int> e[n];
map<string,int> city;
int t;
string tmp[n];
set<string> ap_ans;
int low[n],visit[n];
void init(int cityn)
{
	for(int i=0;i<=cityn;i++)
	{
		e[i].clear();
		visit[i]=low[i]=0;
	}
	t=0;
	city.clear();
	ap_ans.clear();
}
void dfs(int p,int i)
{
	int child=0;
	low[i]=visit[i]=++t;
	vector<int>::iterator iter;
	for(iter=e[i].begin();iter!=e[i].end();iter++) 
{	if(!visit[*iter])
	{	//printf("haha\n");
		child++;
		dfs(i,*iter);
		low[i]=min(low[i],low[*iter]);
		if((p==-1 && child>=2)||(p!=-1 && low[*iter]>=visit[i]))	
		ap_ans.insert(tmp[i]);
	}
	else if(*iter!=p) low[i]=min(low[i],visit[*iter]);
}
}	
int main()
{

	int cityn,R;
	int Case=1;
	while(1)
	{
		cin>>cityn;
		if(cityn==0) break;
		init(cityn);
		string cname1,cname2;
		for(int i=1;i<=cityn;i++) 
		{
			cin>>cname1;
			city[cname1]=i;
			tmp[i]=cname1;
		}
		cin>>R;
		for(int i=1;i<=R;i++)
		{
			cin>>cname1>>cname2;
			e[city[cname1]].push_back(city[cname2]);
			e[city[cname2]].push_back(city[cname1]);
		}
		//dfs
		for(int i=1;i<=cityn;i++) 
		if(!visit[i]) dfs(-1,i);
		if (Case>1) cout<<endl;
		printf("City map #%d: %d camera(s) found\n",Case++,ap_ans.size());
		//cout<<"City map #"<<Case++<<": "<<ap_ans.size()<<" camera(s) found"<<endl;
		for(set<string>::iterator it=ap_ans.begin();it!=ap_ans.end();it++) 
		cout<<*it<<endl;
	}
	return 0;
}
