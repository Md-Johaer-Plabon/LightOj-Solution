/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College. 
Topic : Bellman Ford,Negative Cycle. 

*/


#include <bits/stdc++.h>
using namespace std; 
#define pii pair<ll,pair<int,int> > 
#define s second 
#define f first 
#define ll long long 
#define inf 1000000000000000000

vector<ll>cost(205),dis(205); 
vector<pii>q; 

void bellman(int n){
	dis[1]=0; 
	for(int i=1;i<n-1;i++)
		for(int j=0;j<q.size();j++) 
		  if(dis[q[j].s.s]>dis[q[j].s.f]+q[j].f&&dis[q[j].s.f]!=inf) 
		      dis[q[j].s.s]=dis[q[j].s.f]+q[j].f;
} 

void clr(){
	for(int i=1;i<=200;i++) 
	dis[i]=inf; 
	q.clear();
}
int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		clr();
	  int n,m,x,y,w; 
	  cin>>n; 
	  for(int i=1;i<=n;i++)cin>>cost[i]; 
	  cin>>m; 
	  for(int i=0;i<m;i++) {
	  cin>>x>>y; 
	  ll temp = cost[y]-cost[x]; 
	  temp*=(temp*temp); 
	  q.push_back({temp,{x,y}});
	  } 
	  bellman(n); 
	  
	  cin>>w; 
    printf("Case %d:\n",++cs); 
	  while(w--){
	  	cin>>x; 
	  	if(dis[x]<3||dis[x]==inf)printf("?\n"); 
	  	else printf("%lld\n",dis[x]);
	  }
	}
	return 0;
}
