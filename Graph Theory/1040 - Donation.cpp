/* 
Name : Johaer Plabon
Dept : CSE,Sylhet Engineering College 
*/ 



#include <bits/stdc++.h> 
#define pii pair<int,int>
using namespace std;
vector<pii>v[105]; 
vector<int>vis(105),dis(105); 
int solve(){
   priority_queue<pii,vector<pii>,greater<pii> >q; 
   dis[0] = 0; 
   q.push({0,0}); 
   while(!q.empty()){
   	int x = q.top().second; 
   	q.pop(); 
   	vis[x]=1; 
   	for(int i=0;i<v[x].size();i++) 
   	if(!vis[v[x][i].first]&&dis[v[x][i].first]>v[x][i].second&&x!=v[x][i].first) 
   	dis[v[x][i].first]=v[x][i].second,q.push({v[x][i].second,v[x][i].first}); 
   } 
   int coun=0; 
   for(int i=0;i<=50;i++) 
   if(vis[i])coun++;
   return coun;
}

void clr(){
  for(int i=0;i<=70;i++) 
  v[i].clear(),vis[i]=0,dis[i]=INT_MAX;
}

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		clr();
		int n,a[55][55],sum=0; 
		cin>>n; 
		for(int i=0;i<n;i++) 
		  for(int j=0;j<n;j++) {
		     cin>>a[i][j]; 
		     if(a[i][j]) 
		     v[i].push_back({j,a[i][j]}),v[j].push_back({i,a[i][j]}),
		     sum+=a[i][j];  
		  }
	int temp = solve(); 
	if(temp!=n)printf("Case %d: -1\n",++cs); 
	else{
	  for(int i=0;i<n;i++)sum-=dis[i]; 
	  printf("Case %d: %d\n",++cs,sum);
	} 
	
	}
	return 0;
}
