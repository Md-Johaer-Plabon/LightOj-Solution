/* 
Name : Johaer Plabon
Dept : CSE,Sylhet Engineering College.
Topic : MST 
*/ 


#include <bits/stdc++.h>
using namespace std; 
#define pii pair<int,int>

vector<pii>v[1005]; 
vector<int>dis(1005,0); 
vector<bool>chk(1005); 

int solve2(int n){
	for(int i=0;i<=1000;i++)dis[i]=0,chk[i]=0;
   	dis[0]=0; 
   	priority_queue<pii>q; 
   	q.push({0,0}); 
   	while(!q.empty()){
   		int x = q.top().second; 
   		q.pop();
   		chk[x]=1; 
   		for(int i=0;i<v[x].size();i++) 
   		if(!chk[v[x][i].first]&&dis[v[x][i].first]<v[x][i].second) 
   		q.push({v[x][i].second,v[x][i].first}),dis[v[x][i].first]=v[x][i].second; 
   	} 
   	int ans =0;
   	for(int i=0;i<=n;i++) 
   	ans+=dis[i]; 
   	return ans;
} 

int solve(int n){
   	dis[0]=0; 
   	priority_queue<pii,vector<pii>,greater<pii> >q; 
   	q.push({0,0}); 
   	while(!q.empty()){
   		int x = q.top().second; 
   		q.pop();
   		chk[x]=1; 
   		for(int i=0;i<v[x].size();i++) 
   		if(!chk[v[x][i].first]&&dis[v[x][i].first]>v[x][i].second) 
   		q.push({v[x][i].second,v[x][i].first}),dis[v[x][i].first]=v[x][i].second; 
   	} 
   	int ans =0;
   	for(int i=0;i<=n;i++) 
   	ans+=dis[i]; 
   	return ans;
} 

void clr(){
   for(int i=0;i<=1000;i++) 
   v[i].clear(),dis[i]=INT_MAX,chk[i]=0;	
}

int main() {
	int t,cs=0;
	cin>>t; 
	while(t--){ 
		clr();
		int n,x,y,w; 
		cin>>n; 
		while(cin>>x>>y>>w){
			if(!x&&!y&&!w)break; 
			v[x].push_back({y,w}); 
			v[y].push_back({x,w});
		} 
		
		int temp = solve(n)+solve2(n);
		if(temp%2==0)printf("Case %d: %d\n",++cs,temp/2); 
		else printf("Case %d: %d/2\n",++cs,temp);
	}
	return 0;
}
