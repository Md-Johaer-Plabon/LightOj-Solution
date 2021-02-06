/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
Topic : DFS,Topological Sort.
*/ 


#include <bits/stdc++.h>
using namespace std;
vector<int>v[10005]; 
int color[10005],en[10005],tme; 
void dfs(int x){
	color[x]=2;
	tme++;
	for(int i=0;i<v[x].size();i++) 
	if(color[v[x][i]]==1) 
	dfs(v[x][i]);

tme++,en[x]=tme; 
}

void tsort(int x){
	color[x]=3;
	for(int i=0;i<v[x].size();i++)
	if(color[v[x][i]]==2)
	tsort(v[x][i]);
}
int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){
		int n,m,x,y; 
		cin>>n>>m;  
		for(int i=1;i<=n;i++)v[i].clear(),color[i]=0;
		while(m--)cin>>x>>y,v[x].push_back(y),
		color[x]=1,color[y]=1;
		
		int coun=0;
		tme=0;
		for(int i=1;i<=n;i++)
		if(!color[i])coun++;
		
		for(int i=1;i<=n;i++) 
		if(color[i]==1)
		dfs(i); 
		
		vector<pair<int,int> >topsort;

		for(int i=1;i<=n;i++)
		if(color[i]==2)
		topsort.push_back({en[i],i}); 

		sort(topsort.begin(),topsort.end(),greater<pair<int,int> >() ); 

		for(int i=0;i<topsort.size();i++)
		if(color[topsort[i].second]==2)
		coun++,tsort(topsort[i].second);
		
		printf("Case %d: %d\n",++cs,coun);
	}
	return 0;
}
