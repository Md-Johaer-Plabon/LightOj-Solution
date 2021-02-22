/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College. 
Topic : Bellman-Ford,Negative Cycle. 
*/ 


#include <bits/stdc++.h>
using namespace std; 
#define pi pair<int,int> 
#define f first 
#define s second 
#define inf 1000000000

vector<pair<int,pair<int,int> > >ed; 
vector<int>vis(1005),dis(1005),v[1005]; 

void dfs(int x){
	vis[x]=1; 
	for(int i=0;i<v[x].size();i++) 
	  if(!vis[v[x][i]])dfs(v[x][i]);
}

void bellman(int n){ 
	for(int i=0;i<n-1;i++) 
	for(int j=0;j<ed.size();j++) 
	  if(dis[ed[j].s.s]>dis[ed[j].s.f]+ed[j].f) 
	  dis[ed[j].s.s]=dis[ed[j].s.f]+ed[j].f; 
} 

void clr(){
  for(int i=0;i<=1000;i++)vis[i]=0,dis[i]=inf,v[i].clear();	 
  ed.clear(); 
}

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		clr();
		int n,m,x,y,w;
		cin>>n>>m; 
		for(int i=0;i<m;i++)
		 cin>>x>>y>>w, 
		 ed.push_back({w,{y,x}}),v[y].push_back(x); 
		 
		 dis[0]=0;
		
		 	bellman(n); 
		 int flag = 0;
		 	for(int j=0;j<ed.size();j++) { 
		 	  if(dis[ed[j].s.s]>dis[ed[j].s.f]+ed[j].f) { 
		 	    if(!vis[ed[j].s.s]) 
		 	    dfs(ed[j].s.s),flag=1;
		 	  }  
	}     
			 	 printf("Case %d:",++cs); 
        if(flag) 
        for(int i=0;i<n;i++){ 
        if(vis[i])printf(" %d",i); 
        }
		 	 
		else printf(" impossible");  
		 	
		 	 cout<<endl; 
	}
	return 0;
}
