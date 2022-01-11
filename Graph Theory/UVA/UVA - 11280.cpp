/* 
Author : Johaer Plabon 
Dept. Of CSE,SEC 

Topic : Graph,Bellaman,Dijkastra For source to destination for Maximum K edges. 
Complexity : O(V*E*log(E)) 

*/ 


	l#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
#define ff first 
#define ss second 
#define pii pair<ll,ll> 
#define pi pair<ll,pair<ll,ll> >
#define inf 1000000000000000000
map<string,ll>mp; 
vector<pii>v[2005];  
ll dis[2005][2005]; 
void dijkastra(ll xx){
	priority_queue<pi,vector<pi>,greater<pi> >q; 
	q.push({0,{0,xx}}); 
	dis[xx][0]=0;
	while(!q.empty()){
		ll x = q.top().ss.ss; 
		ll lev = q.top().ss.ff;
		q.pop(); 
		for(ll i=0;i<v[x].size();i++) 
		if(dis[v[x][i].ff][lev+1]>dis[x][lev]+v[x][i].ss) 
		dis[v[x][i].ff][lev+1]=dis[x][lev]+v[x][i].ss, 
		q.push({dis[v[x][i].ff][lev+1],{lev+1,v[x][i].ff}});
		   
	}
}
int main() {
	ll t,cs=0;
	cin>>t; 
	while(t--){
		ll n,m,z,xx,yy; 
		string s,s1;
		cin>>n; 
		mp.clear();
		for(ll i=0;i<=n;i++)v[i].clear();
		for(ll i=0;i<n;i++){
			cin>>s,mp[s]=i+1; 
			if(s=="Calgary")xx=i+1; 
			else if(s=="Fredericton")yy=i+1;
		}
		cin>>m; 
		for(ll i=0;i<m;i++){
			cin>>s>>s1>>z; 
			v[mp[s]].push_back({mp[s1],z}); 

		} 
		for(ll i=0;i<=n;i++) 
		  for(ll j=0;j<=m+5;j++) 
		      dis[i][j]=inf;
		dijkastra(xx); 
		
		ll cc; 
		printf("Scenario #%lld\n",++cs); 
		for(ll i=2;i<=m+2;i++)dis[yy][i] = min (dis[yy][i],dis[yy][i-1]);
		 ll pp; 
		 cin>>pp;
		 while(pp--){ 
		 	scanf("%lld",&cc);
		 	cc++; 
		 	if(cc>m+1)cc=m;
			if(dis[yy][cc]==inf)puts("No satisfactory flights"); 
			else
		  printf("Total cost of flight(s) is $%lld\n",dis[yy][cc]);
		}
		if(t)printf("\n");
	}
	return 0;
}
