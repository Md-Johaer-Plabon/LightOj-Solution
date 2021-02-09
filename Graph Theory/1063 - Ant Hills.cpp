/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
Topic : Articulation point. 
*/ 


#include <bits/stdc++.h>
using namespace std;
vector<int>v[10005]; 
vector<int>vis(10005,0),low(10005,0),parent(10005,0); 
vector<bool>ap(10005,0); 
int tme=0,coun,chk;

void AP(int x){
	vis[x] = low[x] = ++tme; 
	
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]){
			parent[v[x][i]]=x; 
			if(parent[x]==-1)chk++;
			AP(v[x][i]); 
			
			low[x] = min(low[x],low[v[x][i]]); 
			
			if(parent[x]!=-1&&vis[x]<=low[v[x][i]]) 
			ap[x]=1;
		} 
		
		if(v[x][i]!=parent[x]) 
		low[x] = min(low[x],vis[v[x][i]]);
	}
}

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		
		for(int i=1;i<=10000;i++) 
		v[i].clear(),vis[i]=0,low[i]=INT_MAX,parent[i]=-1,ap[i]=0;
		int n,m,x,y; 
		cin>>n>>m; 
		
		for(int i=0;i<m;i++) 
		cin>>x>>y,v[x].push_back(y), 
		v[y].push_back(x); 
		
		
		for(int i=1;i<=n;i++) {
		if(!vis[i]) {
		chk=0;
		AP(i); 
		if(chk>=2)ap[i]=1;
		}
	}
		coun=0; 
		for(int i=1;i<=n;i++)if(ap[i])coun++;
		printf("Case %d: %d\n",++cs,coun);
		
	}
	return 0;
}
