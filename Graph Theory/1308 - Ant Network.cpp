/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College. 
Topic : Articulation Point. 
*/ 


#include <bits/stdc++.h>
using namespace std; 
#define ll unsigned long long int 
vector<int>v[10005]; 
vector<int>vis(10005,0),low(10005,0),ap(10005,0),par(10005,0); 
int tme,chk,ind; 

int dfs(int x){
   vis[x] = 1; 
   tme++; 
     for(int i=0;i<v[x].size();i++){ 
     	if(!vis[v[x][i]]&&ap[v[x][i]]&&ind!=v[x][i])chk++,ind = v[x][i]; 
        if(!vis[v[x][i]]&&!ap[v[x][i]]) 
             dfs(v[x][i]);
     }
     if(chk>=2)return 0; 
     else return tme;
}

void tarjan(int x){
	vis[x] = low[x] = ++tme; 
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]) { 
			if(x==0)chk++;
			par[v[x][i]]=x; 
			tarjan(v[x][i]); 
			
			low[x] = min(low[x],low[v[x][i]]); 
			
			if(par[x]!=-1&&low[v[x][i]]>=vis[x]) 
			  ap[x] = 1;
		} 
		
		if(v[x][i]!=par[x]) 
		low[x] = min(low[x],vis[v[x][i]]);
	}
} 

void clr(){
	for(int i=0;i<=10000;i++) 
	v[i].clear(),vis[i]=0,low[i]=INT_MAX,ap[i]=0,par[i]=-1; 
	tme = chk = 0;
}

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		clr();
		ll n,m,x,y; 
		cin>>n>>m; 
		
		for(int i=0;i<m;i++) 
		cin>>x>>y,v[x].push_back(y),v[y].push_back(x); 
		
		tarjan(0); 
		if(chk>=2)ap[0]=1;
		
		for(int i=0;i<=n;i++)vis[i]=0; 
		
		ll ans = 1,coun = 0;
		for(int i=0;i<n;i++) {
		if(!vis[i]&&!ap[i]){ 
	    ll temp; 
	    tme = chk = 0; 
	    ind = -1;
		temp = dfs(i);  
		if(temp)coun++,ans*=temp; 
		}
	} 
	
	if(coun==1) ans = (n*(n-1))/2 , coun = 2; 
	
	printf("Case %d: %llu %llu\n",++cs,coun,ans);
	}
	return 0;
}
