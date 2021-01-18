/*
Name: Johaer Plabon 
Dept: CSE, Sylhet Engineering College
*/ 

#include <bits/stdc++.h>
using namespace std;
int n,m; 
int dis[205][205],lvl[205][205]; 
int vis[205][205];
string s[205]; 
queue<pair<int,int> >fii; 
int fire(int x,int y){
	queue<pair<int,int> >q;
	q.push({x,y}); 
	vis[x][y]=1;
	int ind=0;
	int chk=1; 
	while(1){ 
		int xi,yi;
	while(!q.empty()){
		 xi=q.front().first; 
		 yi=q.front().second; 
		if(dis[xi][yi]==chk){chk++,ind++;break;}
		q.pop(); 
	    if(vis[xi][yi]==2)continue;
	    if(yi+1==m||yi-1==-1||xi+1==n||xi-1==-1)return dis[xi][yi]+1;
		if(yi+1<m&&!vis[xi][yi+1]) 
		q.push({xi,yi+1}),dis[xi][yi+1]=dis[xi][yi]+1,vis[xi][yi+1]=1;  
		
		if(yi-1>=0&&!vis[xi][yi-1]) 
		q.push({xi,yi-1}),vis[xi][yi-1]=1,dis[xi][yi-1]=dis[xi][yi]+1;  
		
		if(xi+1<n&&!vis[xi+1][yi]) 
		q.push({xi+1,yi}),vis[xi+1][yi]=1,dis[xi+1][yi]=dis[xi][yi]+1;  
		
		if(xi-1>=0&&!vis[xi-1][yi]) 
		q.push({xi-1,yi}),vis[xi-1][yi]=1,dis[xi-1][yi]=dis[xi][yi]+1; 
	} 
	if(q.empty())return 0;
		while(1){
			 xi=fii.front().first; 
			 yi=fii.front().second;  
			if(lvl[xi][yi]==ind+1)break;
			fii.pop(); 
			if(yi+1<m&&vis[xi][yi+1]<2) 
			vis[xi][yi+1]=2,fii.push({xi,yi+1}),lvl[xi][yi+1]=lvl[xi][yi]+1;
			if(yi-1>=0&&vis[xi][yi-1]<2)  
			vis[xi][yi-1]=2,fii.push({xi,yi-1}),lvl[xi][yi-1]=lvl[xi][yi]+1;
			if(xi+1<n&&vis[xi+1][yi]<2)
			vis[xi+1][yi]=2,fii.push({xi+1,yi}),lvl[xi+1][yi]=lvl[xi][yi]+1;
			if(xi-1>=0&&vis[xi-1][yi]<2) 
			vis[xi-1][yi]=2,fii.push({xi-1,yi}),lvl[xi-1][yi]=lvl[xi][yi]+1;
		} 
	} 
	return 0;
}
int main() {
	int t,cs=0;
	cin>>t; 
	while(t--){ 
		cout<<"Case "<<++cs<<": ";
		memset(vis,0,sizeof vis); 
		memset(lvl,0,sizeof lvl);
		for(int i=0;i<=200;i++)s[i]=""; 
		while(!fii.empty())fii.pop();
		cin>>n>>m; 
		char ch ; 
		int x,y; 
		for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) {
		cin>>ch; 
		s[i]+=ch; 
		if(ch=='F')fii.push({i,j}),lvl[i][j]=1,vis[i][j]=2; 
		if(ch=='J')x=i,y=j; 
		dis[i][j]=0; 
		if(ch=='#')vis[i][j]=3;
		}  
	int res = fire(x,y); 
	if(res)cout<<res<<endl; 
	else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
