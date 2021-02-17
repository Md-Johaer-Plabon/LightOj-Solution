/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College. 
*/ 


#include <bits/stdc++.h>
using namespace std; 
#define pii pair<int,int>
vector<pii>v[1005]; 
vector<int>vis(1005),dis(1005);

int solve(int n){
	dis[1]=0; 
	priority_queue<pii,vector<pii>,greater<pii> >q; 
	q.push({0,1}); 
	while(!q.empty()){
		int x = q.top().second; 
		q.pop(); 
		vis[x]=1; 
		for(int i=0;i<v[x].size();i++){
			if(!vis[v[x][i].first]&&dis[v[x][i].first]>v[x][i].second) 
			dis[v[x][i].first]=v[x][i].second, 
			q.push({v[x][i].second,v[x][i].first});
		}
	} 
	int coun = 0; 
	for(int i=1;i<=n;i++) 
	if(vis[i])coun++; 
	return coun;
}

void clr(){
	for(int i=0;i<=1000;i++) 
	v[i].clear(),vis[i]=0,dis[i]=INT_MAX;
}

int main() {
	int t,cs=0;
	 cin>>t; 
	 while(t--){ 
	 	clr();
	 	int w,n,ind=1; 
	 	string s,s1; 
	 	map<string,int>mp;
	 	 cin>>n; 
	 	 for(int i=0;i<n;i++){
	 	 	cin>>s>>s1>>w; 
	 	 	if(mp[s]==0)mp[s]=ind,ind++; 
	 	 	if(mp[s1]==0)mp[s1]=ind,ind++; 
	 	 	v[mp[s]].push_back({mp[s1],w}); 
	 	 	v[mp[s1]].push_back({mp[s],w});
	 	 }  
	 	 int temp = solve(mp.size()); 
	 	 int ans = 0;
	 	 if(temp!=mp.size())printf("Case %d: Impossible\n",++cs); 
	 	 else{
	 	 	for(int i=1;i<=mp.size();i++) 
	 	 	ans += dis[i]; 
	 	 	printf("Case %d: %d\n",++cs,ans);
	 	 }
	 }
	return 0;
}
