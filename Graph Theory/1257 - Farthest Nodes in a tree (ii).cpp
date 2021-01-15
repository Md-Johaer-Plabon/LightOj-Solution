/* 
Name : Johaer Plabon 
Dept : CSE , Sylhet Engineering College 
*/ 
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int ind; 
vector<pair<int,int> >v[30005];
ll dis[3][30005]; 
bool vis[30005];
void bfs(int n,int m){  
	queue<int>q;
	q.push(n);  
	vis[n]=1;
	ll maxx=0;
	while(!q.empty()){
		int x=q.front(); 
		if(dis[m][x]>maxx)ind=x,maxx=dis[m][x];
		q.pop();
		for(int i=0;i<v[x].size();i++) 
		if(!vis[v[x][i].first])
		dis[m][v[x][i].first]=dis[m][x]+v[x][i].second,vis[v[x][i].first]=1,
		q.push(v[x][i].first);  
		}
} 
int main() {
	ll t,cs=0;
	cin>>t;
	while(t--){ 
		ll n,x,y,w; 
		scanf("%lld",&n);  
        memset(dis,0,sizeof dis);
        memset(vis,0,sizeof vis);
		for(int i=0;i<n-1;i++) 
		scanf("%lld%lld%lld",&x,&y,&w),v[x].push_back({y,w}),v[y].push_back({x,w}); 
    
		bfs(0,0); 
		memset(vis,0,sizeof vis); 
    bfs(ind,1);  
    memset(vis,0,sizeof vis);
		bfs(ind,2);
		
		printf("Case %lld:\n",++cs); 
		for(int i=0;i<n;i++) 
		printf("%lld\n",max(dis[1][i],dis[2][i])),v[i].clear();
	}
	return 0;
}
