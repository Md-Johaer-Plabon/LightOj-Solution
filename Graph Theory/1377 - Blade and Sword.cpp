/*
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College

*/

#include <bits/stdc++.h>
using namespace std;
string  s[205]; 
bool vis[205][205];
long long int dis[3][205][205];
int n,m; 
vector<pair<int,pair<int,int> > >service[3];
void bfs(int x,int y,int chk){
	for(int i=0;i<n;i++) 
	for(int j=0;j<m;j++){if(s[i][j]=='#')vis[i][j]=1;else vis[i][j]=0;}
	vis[x][y]=1;
	queue<pair<int,int> >q;
	q.push({x,y}); 
	dis[chk][x][y]=0; 
	while(!q.empty()){
		int xi=q.front().first; 
		int yi=q.front().second; 
		q.pop(); 
        if(s[xi][yi]=='*'){service[chk].push_back({dis[chk][xi][yi],{xi,yi}});
        continue;}
        
		if(yi+1<m&&!vis[xi][yi+1]) 
		q.push({xi,yi+1}),vis[xi][yi+1]=1,dis[chk][xi][yi+1]=dis[chk][xi][yi]+1;  
		
		if(yi-1>=0&&!vis[xi][yi-1]) 
		q.push({xi,yi-1}),vis[xi][yi-1]=1,dis[chk][xi][yi-1]=dis[chk][xi][yi]+1;  
		
		if(xi+1<n&&!vis[xi+1][yi]) 
		q.push({xi+1,yi}),vis[xi+1][yi]=1,dis[chk][xi+1][yi]=dis[chk][xi][yi]+1;  
		
		if(xi-1>=0&&!vis[xi-1][yi]) 
		q.push({xi-1,yi}),vis[xi-1][yi]=1,dis[chk][xi-1][yi]=dis[chk][xi][yi]+1;  
	}
}
int main() {
	int t,cs=0;
	cin>>t;
	while(t--){ 
		int coun=0;
		for(int i=0;i<=200;i++)s[i]=""; 
		service[0].clear(),service[1].clear();
	cin>>n>>m; 
	char ch; 
	pair<int,int>p,d;
	for(int i=0;i<n;i++) 
	for(int j=0;j<m;j++){ 
	cin>>ch,s[i]+=ch; 
	if(ch=='P')p={i,j}; 
	if(ch=='D')d={i,j};  
	if(ch=='*')coun++;
	vis[i][j]=0,dis[0][i][j]=INT_MAX,dis[1][i][j]=INT_MAX;
	}
	bfs(p.first,p.second,0); 
	bfs(d.first,d.second,1); 
	long long int temp=INT_MAX; 
	if(service[0].size())
	sort(service[0].begin(),service[0].end()); 
	if(service[1].size())
	sort(service[1].begin(),service[1].end());
	
	if(service[0].size()&&service[1].size()){ 
		
	if(service[0][0].second.first!=service[1][0].second.first||
	service[0][0].second.second!=service[1][0].second.second) 
	
	temp = service[0][0].first+service[1][0].first; 
	else{ 
		int temp1=0,temp2=0;
		if(service[1].size()>1)
		 temp1 = service[0][0].first+service[1][1].first; 
		if(service[0].size()>1)
	     temp2 =  service[0][1].first+service[1][0].first; 
	     if(temp1==0&&temp2)temp=temp2; 
	     else if(temp2==0&&temp1)temp=temp1; 
	     else if(temp1&&temp2)temp=min(temp1,temp2); 
	     if(temp==INT_MAX&&coun>1)temp=service[0][0].first+service[1][0].first+1;
	}
	} 
//	cout<<temp<<endl;
	int ans = min (temp+1,dis[0][d.first][d.second]); 
	printf("Case %d: ",++cs); 
	if(ans==INT_MAX)printf("impossible\n"); 
	else printf("%d\n",ans);
	}
	return 0;
}
