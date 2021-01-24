/* 
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College  

Idea : For second best shortest path -> 
        1.First do dijkastra from 1 -> N and save the minimum distance to dis[], 
        2.Then again do dijkastra from N -> 1 and save the minimum distance to dis1[]. 
        3.Mark the nodes of shortest path,if there are multiple shortest path then mark all of nodes of possible shortest path. 
        4.Iterate the marked nodes and do minimum if ans>dis[N],
                       ans = min (ans,dis[node]+dis1[node->adj.node]+cost/weight between node and adj.node) 
        5.Now, ans is second best shortest cost from 1 -> N. 

     .... For marking the nodes of shortest path I've stored the parent nodes of all nodes....
*/


#include <bits/stdc++.h>
using namespace std; 
#define pp pair<int,int>
vector<pair<int,int> >v[5005]; 
vector<int>minn(5000,0); 
vector<int>dis(5000,0),dis1(5000,0),par(5000,0);
void second(int n){ 
	dis1[n]=0; 
	priority_queue<pp,vector<pp >,greater<pp > >q; 
	q.push({0,n}); 
	while(!q.empty()){
		int x = q.top().second; 
		q.pop();
		for(int i=0;i<v[x].size();i++) 
		if(dis1[v[x][i].first]>dis1[x]+v[x][i].second) 
		dis1[v[x][i].first]=dis1[x]+v[x][i].second,
		q.push({dis1[v[x][i].first],v[x][i].first});
	}
}
void first(int n){
	for(int i=1;i<=5000;i++)dis[i]=INT_MAX,minn[i]=INT_MAX,dis1[i]=INT_MAX; 
	dis[n]=0; 
	for(int i=0;i<v[1].size();i++)minn[1]=min(minn[1],v[1][i].second); 
	
	priority_queue<pp,vector<pp>,greater<pp> >q; 
	q.push({0,n}); 
	while(!q.empty()){
		int x=q.top().second; 
		q.pop(); 
		for(int i=0;i<v[x].size();i++) {
			if(dis[v[x][i].first]>dis[x]+v[x][i].second) { 
			dis[v[x][i].first]=dis[x]+v[x][i].second; 
			par[v[x][i].first]=x;
			q.push({dis[v[x][i].first],v[x][i].first}); 
			minn[v[x][i].first]=min(minn[v[x][i].first],min(minn[x],v[x][i].second));
			}  
		
			if(dis[v[x][i].first]==dis[x]+v[x][i].second)
			minn[v[x][i].first]=min(minn[v[x][i].first],min(minn[x],v[x][i].second));
		} 
		
	}
}
int main() {
	int t,cs=0; 
	cin>>t;
	while(t--){ 
		int n,m,x,y,w; 
		for(int i=1;i<=5000;i++)v[i].clear();
		cin>>n>>m;
		for(int i=0;i<m;i++) 
		cin>>x>>y>>w,v[x].push_back({y,w}),v[y].push_back({x,w}); 
		if(n==1){ 
			int mini=INT_MAX; 
			for(int i=0;i<v[1].size();i++)mini=min(mini,v[1][i].second);
			printf("Case %d: %d\n",++cs,mini); 
			continue; 
		}
		first(1); 
		for(int i=0;i<v[n].size();i++)minn[n]=min(minn[n],v[n][i].second);
		 long long int temp = dis[n]+2*minn[n]; 
	    second(n); 
           vector<int>vis(5000,0);  
           for(int i=0;i<v[n].size();i++){
           	if(dis[v[n][i].first]+v[n][i].second==dis[n]){ 
           	int child = v[n][i].first; 
           	vis[child]=1;
           	while(1){
           		 child = par[child]; 
           		 if(child==0)break;
           		 vis[child]=1; 
           	} 
           }
           } 
           int ans = INT_MAX;
           for(int i=1;i<=n-1;i++){
           	if(vis[i]){
           		for(int j=0;j<v[i].size();j++)
           		if(dis[i]+v[i][j].second+dis1[v[i][j].first]>dis[n]) 
           		ans = min (ans,dis[i]+v[i][j].second+dis1[v[i][j].first]);
           	}
           } 
		printf("Case %d: %d\n",++cs,min((long long int)ans,temp));
	}
	return 0;
}
