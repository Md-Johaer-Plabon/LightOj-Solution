/* 
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College 
*/



#include <bits/stdc++.h>
using namespace std;
vector<int>v[505]; 
int n;
  int ans = INT_MAX; 
void bfs(){
  for(int i=0;i<=n-1;i++){ 
  	vector<int>dis(505,INT_MAX); 
  	vector<int>root(505,-1);
  dis[i]=0; 

  queue<int>q; 
  q.push(i); 
  while(!q.empty()){
  	int tm=q.front();
  	q.pop(); 
  	for(int i=0;i<v[tm].size();i++){
  		if(dis[v[tm][i]]==INT_MAX){
  			dis[v[tm][i]]=dis[tm]+1; 
  			root[v[tm][i]]=tm; 
  			q.push(v[tm][i]);
  		} 
  		else if(root[tm]!=v[tm][i]&&root[v[tm][i]]!=tm) 
  		ans = min (ans,dis[tm]+dis[v[tm][i]]+1);
  	}
  } 
  }
}
int main() {
	int t,cs=0;
	cin>>t;
	while(t--){ 
		for(int i=0;i<=500;i++)
		v[i].clear(); 
		ans = INT_MAX;
		int m,x,y; 
		cin>>n>>m; 
		for(int i=0;i<m;i++)
		cin>>x>>y,v[x].push_back(y),v[y].push_back(x);  
		
		int res = INT_MAX;
	     bfs(); 
		
		printf("Case %d: ",++cs); 
		if(ans==INT_MAX)printf("impossible\n"); 
		else printf("%d\n",ans);
	}
	return 0;
}
