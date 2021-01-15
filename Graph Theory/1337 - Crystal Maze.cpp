#include <bits/stdc++.h>
using namespace std;
string s[503]; 
int n,m;
int crs[505][505];
bool vis[505][505];
vector<pair<int,int> >v; 
int bfs(int x,int y){
	vis[x][y]=1; 
	queue<pair<int,int> >q;
	q.push({x,y}); 
	int coun=0;
	while(!q.empty()){
		int xi=q.front().first; 
		int yi=q.front().second; 
		v.push_back({xi,yi});
		q.pop(); 
		if(s[xi][yi]=='C')coun++;
		if(yi+1<m&&!vis[xi][yi+1]) 
		q.push({xi,yi+1}),vis[xi][yi+1]=1;  
		
		if(yi-1>=0&&!vis[xi][yi-1]) 
		q.push({xi,yi-1}),vis[xi][yi-1]=1;  
		
		if(xi+1<n&&!vis[xi+1][yi]) 
		q.push({xi+1,yi}),vis[xi+1][yi]=1;  
		
		if(xi-1>=0&&!vis[xi-1][yi]) 
		q.push({xi-1,yi}),vis[xi-1][yi]=1;  
		
	} 
	return coun;
}
int main() {
	int t,cs=0;
	cin>>t; 
	while(t--){ 
		memset(vis,0,sizeof vis); 
		memset(crs,0,sizeof crs);
		printf("Case %d:\n",++cs);
		int q,x,y;
		cin>>n>>m>>q; 
		for(int i=0;i<n;i++) 
		cin>>s[i];  
		for(int i=0;i<n;i++)for(int j=0;j<m;j++) 
		if(s[i][j]=='#')vis[i][j]=1;
		for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++){ 
		if(!vis[i][j]) {
		v.clear(); 
		int temp=bfs(i,j); 
		for(int i=0;i<v.size();i++) 
		  crs[v[i].first][v[i].second]=temp;
		} 
	}
		
		while(q--) {
			scanf("%d%d",&x,&y); 
			printf("%d\n",crs[x-1][y-1]);
		}
		
	}
	return 0;
}
