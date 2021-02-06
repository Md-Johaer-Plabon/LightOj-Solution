/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
Topic : Strongly Connected Component,Direscted Acyclic Graph(DAG).
*/ 


#include <bits/stdc++.h>
using namespace std;
vector<int>v[30005],rev[30005]; 
vector<int>vis(30005,0); 
int en[30005]; 
int tme,coun;
void dfs(int x){
	vis[x]=2; 
	tme++;
	
	for(int i=0;i<v[x].size();i++) 
	if(vis[v[x][i]]==1)dfs(v[x][i]); 
	
	en[x]=++tme;
} 
void trans(int x){
  vis[x]=1; 
  coun++;
  for(int i=0;i<rev[x].size();i++) 
  if(!vis[rev[x][i]])trans(rev[x][i]); 
  
}
int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		for(int i=1;i<=2*n;i++)v[i].clear(),rev[i].clear(),vis[i]=0;
		map<string,int>mp; 
		string s,s1; 
		int chk=0,flag=0;
	    for(int i=0;i<n;i++) { 
	    	cin>>s>>s1; 
	    	if(!mp[s])mp[s]=++chk; 
	    	if(!mp[s1])mp[s1]=++chk;  
	    	v[mp[s]].push_back(mp[s1]); 
	    	rev[mp[s1]].push_back(mp[s]); 
	    	vis[mp[s]]=1; 
	    	vis[mp[s1]]=1; 
	    	if(s==s1)flag = 1;
	    }  
	    if(flag){printf("Case %d: No\n",++cs);continue;}
	    tme = 0;
	    for(int i=1;i<=2*n;i++) 
	    if(vis[i]==1)dfs(i); 
	    
        vector<pair<int,int> >scc; 
        
	    for(int i=1;i<=2*n;i++) 
	    if(vis[i]==2)
	    scc.push_back({en[i],i}),vis[i]=0;
	     
	    sort(scc.begin(),scc.end(),greater<pair<int,int> >() ); 
	    int maxx =0; 
	    
	    for(int i=0;i<scc.size();i++) 
	    if(!vis[scc[i].second]) 
	    coun=0,trans(scc[i].second),
	    maxx = max (maxx,coun); 
	    
	    if(maxx>1)printf("Case %d: No\n",++cs); 
	    else printf("Case %d: Yes\n",++cs);
	}
	return 0;
}
