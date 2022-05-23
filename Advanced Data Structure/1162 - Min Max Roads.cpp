/*
Author: Johaer Plabon 
Dept: CSE,Sylhet Engineering College.
Topic: LCA + RMQ
*/



#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ff first
#define ss second

vector<pair<ll,ll> >v[100005]; 
bool col[100005]; 
ll st[100005][20],st1[100005][20][2],lev[100005]; 

void clr(int x){
 	for(int i=0;i<=x;i++){
 		v[i].clear(),col[i]=0,lev[i]=0; 
 		for(int j=0;j<=17;j++) 
 		st[i][j]=0,st[i][j]=0;
 	}
}

void dfs(int x,int y){
	col[x]=1; 
	st[x][0]=y; 
	lev[x] = lev[y]+1;
	for(int i=0;i<v[x].size();i++){
		if(!col[v[x][i].ff]){ 
		st1[v[x][i].ff][0][0] = v[x][i].ss;
		st1[v[x][i].ff][0][1] = v[x][i].ss;
		dfs(v[x][i].ff,x);
		}
	}
}

void sparsetable(int x){
	for(int i=1;(1<<i)<x;i++) {
		for(int j=1;j<=x;j++) {
			st[j][i] = st[st[j][i-1]][i-1]; 
			st1[j][i][0] = max(st1[j][i-1][0],st1[st[j][i-1]][i-1][0]);
			st1[j][i][1] = min(st1[j][i-1][1],st1[st[j][i-1]][i-1][1]);
		}
	}
}

int lca(int x,int y){ 
	if(lev[x]<lev[y])swap(x,y);
	for(int i=18;i>=0;i--)if(lev[x]-lev[y]>=(1<<i))x=st[x][i]; 
	
	if(x==y)return x;
	
	for(int i=18;i>=0;i--){
		if(st[x][i]!=0 && st[x][i]!=st[y][i]) 
		x=st[x][i],y=st[y][i];
	} 
	
	return st[x][0];
}

ll RMQ(int x,int y){ 
	ll res = 0; 
	
	for(int i=18;i>=0;i--)if(lev[x]-lev[y]>=(1<<i))res=max(res,st1[x][i][0]),x=st[x][i]; 
	return res;
}

ll RMQ1(int x,int y){ 
	ll res = INT_MAX; 
	
	for(int i=18;i>=0;i--)if(lev[x]-lev[y]>=(1<<i))res=min(res,st1[x][i][1]),x=st[x][i]; 
	return res;
}

int main (){
	int t,cs=0;
	cin>>t; 
	while(t--){
		printf("Case %d:\n",++cs);
		ll x,y,z,n,m; 
		cin>>n; 
		clr(n);
		for(int i=0;i<n-1;i++)cin>>x>>y>>z, 
		v[x].push_back({y,z}),v[y].push_back({x,z}); 
		
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
		
		ll res1 = RMQ1(x,node);
	//	cout<<node<<" "<<res1<<endl;
		res1 = min(res1,RMQ1(y,node)); 
		printf("%lld %lld\n",res1,res);
	
	}
}
	return 0;
}
