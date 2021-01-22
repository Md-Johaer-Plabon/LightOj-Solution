/* 
Name : Joaher Plabon 
Dept : CSE,Sylhet Engineering College 
*/

 #include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[505]; 
vector<int>dist(505,0); 
void dijkastra(int n){
	for(int i=0;i<=500;i++)dist[i]=INT_MAX; 
	dist[n]=0; 
	priority_queue<pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > >q; 
	q.push({0,n});
	while(!q.empty()){
		int x=q.top().second;
		q.pop(); 
		for(int i=0;i<v[x].size();i++) 
		   if(dist[v[x][i].first]>dist[x]+v[x][i].second)
		   dist[v[x][i].first]=dist[x]+v[x][i].second, 
		   q.push({dist[v[x][i].first],v[x][i].first});
	}
}
int main() {
	int t,cs=0; 
	cin>>t;
	while(t--){
		int x,y,n,m,w; 
		for(int i=0;i<=500;i++)v[i].clear();
		cin>>n>>m;
		for(int i=0;i<m;i++) 
		cin>>x>>y>>w,v[x].push_back({y,w}),v[y].push_back({x,w}); 
		int des;
		dijkastra(1); 
		printf("Case %d: ",++cs); 
		
		if(dist[n]==INT_MAX)printf("Impossible\n"); 
		else printf("%d\n",dist[n]);
	}
	return 0;
}
