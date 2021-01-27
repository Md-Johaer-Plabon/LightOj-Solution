/* 
Name : Johaer Plabon 
Dept: CSE, Sylhet Engineering College 
*/ 

#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
vector<pair<int,int> >dk[3][10004]; 
ll dis[3][10005];
void dijk(int n,int chk){
  for(int i=1;i<=10000;i++)dis[chk][i]=INT_MAX; 
  dis[chk][n]=0; 
  priority_queue<pair<int,int> >q; 
  q.push({0,n}); 
  while(!q.empty()){
  	int x = q.top().second; 
  	q.pop(); 
  	for(int i=0;i<dk[chk][x].size();i++) 
  	    if(dis[chk][dk[chk][x][i].first]>dis[chk][x]+dk[chk][x][i].second)
  	    dis[chk][dk[chk][x][i].first]=dis[chk][x]+dk[chk][x][i].second, 
  	    q.push({dis[chk][dk[chk][x][i].first],dk[chk][x][i].first});
  }
}
int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		for(int i=1;i<=10000;i++)dk[0][i].clear(),dk[1][i].clear();
		int n,m,s,e,p,x,y,w; 
		cin>>n>>m>>s>>e>>p; 
		for(int i=0;i<m;i++) 
		cin>>x>>y>>w,dk[0][x].push_back({y,w}), 
		dk[1][y].push_back({x,w}); 
		
		dijk(s,0);
		dijk(e,1); 
	
	ll maxx =INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=0;j<dk[0][i].size();j++) 
		  if(dis[0][i]+dis[1][dk[0][i][j].first]+dk[0][i][j].second<=p) 
		      maxx = max (maxx,(ll)dk[0][i][j].second);
	} 
	if(maxx==INT_MIN)printf("Case %d: -1\n",++cs); 
	else 
	printf("Case %d: %d\n",++cs,maxx);
	}
	return 0;
}
