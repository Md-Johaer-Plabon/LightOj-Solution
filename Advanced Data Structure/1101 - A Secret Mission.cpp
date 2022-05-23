/*
Author : Johaer Plabon
 11th batch(2017-18),
   Dept of CSE,SEC.
Topic : MST+LCA+RMQ
  
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define ss second

vector<pair<ll,ll> >v[50005]; 
bool col[50005]; 
ll st[50005][25],st1[50005][25],dist[50005],par[50005],lev[50005]; 

void clr(int x){
 	for(int i=0;i<=x;i++){
 		v[i].clear(),dist[i]=10000000000,par[i]=0,col[i]=0,lev[i]=0; 
 		for(int j=0;j<=22;j++) 
 		st[i][j]=0,st[i][j]=0;
 	}
}

void prims(int n){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >q;
	q.push({0,n}); 
	dist[n]=0;
	while(!q.empty()){
		int x = q.top().second; 
		col[x]=1;
		q.pop(); 
		for(int i=0;i<v[x].size();i++) 
		if(!col[v[x][i].first]&&dist[v[x][i].first]>v[x][i].second) 
		q.push({v[x][i].second,v[x][i].first}), 
		dist[v[x][i].first]=v[x][i].second,par[v[x][i].ff]=x;
	}
}

void dfs(int x,int y){
	col[x]=1; 
	st[x][0]=y; 
	lev[x] = lev[y]+1;
	for(int i=0;i<v[x].size();i++){
		if(!col[v[x][i].ff]){ 
		st1[v[x][i].ff][0] = v[x][i].ss;
		dfs(v[x][i].ff,x);
		}
	}
}

void sparsetable(int x){
	for(int i=1;(1<<i)<x;i++) {
		for(int j=1;j<=x;j++) {
			st[j][i] = st[st[j][i-1]][i-1]; 
			st1[j][i] = max(st1[j][i-1],st1[st[j][i-1]][i-1]);
		}
	}
}

void construct(int n){
	for(int i=0;i<=n;i++)v[i].clear(); 
	for(int i=2;i<=n;i++){
		v[i].push_back({par[i],dist[i]}); 
		v[par[i]].push_back({i,dist[i]}); 
	}
 } 

int lca(int x,int y){ 
	if(lev[x]<lev[y])swap(x,y);
	for(int i=20;i>=0;i--)if(lev[x]-lev[y]>=(1<<i))x=st[x][i]; 
	
	if(x==y)return x;
	
	for(int i=20;i>=0;i--){
		if(st[x][i]!=0 && st[x][i]!=st[y][i]) 
		x=st[x][i],y=st[y][i];
	} 
	
	return st[x][0];
}

ll RMQ(int x,int y){ 
	ll res = 0; 
	
	for(int i=20;i>=0;i--)
    if(lev[x]-lev[y]>=(1<<i))res=max(res,st1[x][i]),x=st[x][i]; 
	return res;
}

int main (){
	int t,cs=0;
	cin>>t; 
	while(t--){
    
		printf("Case %d:\n",++cs);
		ll x,y,z,n,m; 
		cin>>n>>m; 
		clr(n);
    
		for(int i=0;i<m;i++)cin>>x>>y>>z, 
		v[x].push_back({y,z}),v[y].push_back({x,z}); 
		
		prims(1); 
		construct(n); 
		
		for(int i=0;i<=n;i++)col[i]=0;
    
		dfs(1,0);
		sparsetable(n);

	int q; 
	cin>>q; 
	//cout<<q<<endl;
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y); 
		int node = lca(x,y); 
		ll res  = RMQ(x,node); 
		res = max(res,RMQ(y,node)); 		
		printf("%lld\n",res);
	
	}
}
	return 0;
}
