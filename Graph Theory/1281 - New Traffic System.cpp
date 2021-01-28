/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
*/ 

#include <bits/stdc++.h>
using namespace std; 
#define pii pair<int,int>  
#define FOR(i,a) for(int i=0;i<a;i++) 
#define fi first 
#define se second
vector<pii>v[10005],v1[10005]; 
int dis[10005][15];
void dijkstra(int n,int d){
	FOR(i,10000)FOR(j,12)dis[i][j]=INT_MAX; 
	dis[0][0]=0; 
	priority_queue<pair<int,pii >,vector<pair<int,pii> >,greater<pair<int,pii> > >q;  
	
	q.push({0,{0,0}}); 
	while(!q.empty()){
		int x = q.top().se.se; 
		int y = q.top().se.fi;
		q.pop(); 
		for(int i=0;i<v[x].size();i++) 
		if(dis[v[x][i].fi][y]>dis[x][y]+v[x][i].se) 
		dis[v[x][i].fi][y]=dis[x][y]+v[x][i].se, 
		q.push({dis[v[x][i].fi][y],{y,v[x][i].fi}});
		 
		for(int i=0;i<v1[x].size();i++) {
			if(dis[v1[x][i].fi][y+1]>dis[x][y]+v1[x][i].se&&y+1<=d) 
			dis[v1[x][i].fi][y+1]=dis[x][y]+v1[x][i].se,
			q.push({dis[v1[x][i].fi][y+1],{y+1,v1[x][i].fi}});
		}
	}
	
}
int main() {
    int t,cs=0; 
    cin>>t; 
    while(t--){ 
    	for(int i=0;i<=10000;i++)v[i].clear(),v1[i].clear();
    	int n,m,k,d,x,y,w;
    	cin>>n>>m>>k>>d; 
    	FOR(i,m) 
    	cin>>x>>y>>w,v[x].push_back({y,w}); 
    	
    FOR(i,k) 
    	cin>>x>>y>>w,v1[x].push_back({y,w}); 
    	
    	dijkstra(0,d);  
      
    	int ans = INT_MAX;
    	for(int i=0;i<=d;i++) 
    	ans = min (ans,dis[n-1][i]); 
    	if(ans==INT_MAX)printf("Case %d: Impossible\n",++cs); 
    	else printf("Case %d: %d\n",++cs,ans);
    }
	return 0;
}
