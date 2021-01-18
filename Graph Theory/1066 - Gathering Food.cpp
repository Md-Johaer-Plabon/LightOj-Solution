/*
Name : Johaer Plabon 
Dept: CSE, Sylhet Engineering College 
*/

#include <bits/stdc++.h>
using namespace std;
string s[15]; 
int n,alp=0; 
bool vis[15][15]; 
int dis[15][15];  
int par[15][15];
vector<pair<int,int> >v[30];
int bfs(int x,int y,int ind){  
	memset(vis,0,sizeof vis); 
    for(int i=0;i<n;i++) 
    for(int j=0;j<n;j++) 
    if(s[i][j]!='.'&&s[i][j]>ind+66||s[i][j]=='#') 
    vis[i][j]=1;	 
	int flag=0;
	queue<pair<int,int> >q;
	q.push({x,y});  
    vis[x][y]=1;
	while(!q.empty()){ 
		int xi=q.front().first; 
		int yi=q.front().second; 
        if(s[xi][yi]==ind+66)return 1;
        
		q.pop(); 
		
		if(yi+1<n&&!vis[xi][yi+1]) 
		q.push({xi,yi+1}),dis[xi][yi+1]=dis[xi][yi]+1,vis[xi][yi+1]=1;  
		
		if(yi-1>=0&&!vis[xi][yi-1]) 
		q.push({xi,yi-1}),vis[xi][yi-1]=1,dis[xi][yi-1]=dis[xi][yi]+1;  
		
		if(xi+1<n&&!vis[xi+1][yi]) 
		q.push({xi+1,yi}),vis[xi+1][yi]=1,dis[xi+1][yi]=dis[xi][yi]+1;  
		
		if(xi-1>=0&&!vis[xi-1][yi]) 
		q.push({xi-1,yi}),vis[xi-1][yi]=1,dis[xi-1][yi]=dis[xi][yi]+1;
	} 
	return 0;
}
int main() { 
	int t,cs=0;
	cin>>t;
	while(t--){ 
		memset(vis,0,sizeof vis); 
		memset(dis,0,sizeof dis); 
		for(int i=0;i<=alp;i++) 
		v[i].clear();
		int x,y,x1,y1;
		alp=0; 
		cin>>n; 
		for(int i=0;i<n;i++)s[i]="";
		cout<<"Case "<<++cs<<": ";
		char ch,ind=0; 
		for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++) {
			cin>>ch,s[i]+=ch; 
			if(ch>=65&&ch<=90) 
			v[ch%65].push_back({i,j}),alp++; 
		}  
		int temp=1;
		if(alp==1){cout<<0<<endl;continue;} 
		for(int i=0;i<alp-1;i++) { 
			if(temp)
		   temp = bfs(v[i][0].first,v[i][0].second,i); 
		} 
		if(temp)cout<<dis[v[alp-1][0].first][v[alp-1][0].second]<<endl; 
		else cout<<"Impossible"<<endl;
	}
	return 0;
}
