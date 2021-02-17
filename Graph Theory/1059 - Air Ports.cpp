/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
*/ 



#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>

vector<pii>v[10005]; 
vector<bool>vis(10005); 
int dis[10005]; 

void solve(int n){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,n}); 
	dis[n]=0;
	while(!q.empty()){
		int x = q.top().second; 
		vis[x]=1;
		q.pop(); 
		for(int i=0;i<v[x].size();i++) 
		if(!vis[v[x][i].first]&&dis[v[x][i].first]>v[x][i].second) 
		q.push({v[x][i].second,v[x][i].first}), 
		dis[v[x][i].first]=v[x][i].second;
	}
}

void clr(){
   for(int i=1;i<=10000;i++) 
   v[i].clear(),vis[i]=0,dis[i]=INT_MAX;
}

int main() {
    int t,cs=0; 
    cin>>t;
    while(t--){ 
    	clr();
    	ll n,m,c,x,y,w; 
    	scanf("%lld%lld%lld",&n,&m,&c); 
    	for(int i=0;i<m;i++) 
    	scanf("%lld%lld%lld",&x,&y,&w),v[x].push_back({y,w}), 
    	v[y].push_back({x,w}); 
    	
    	ll coun=0;
    	
    	for(int i=1;i<=n;i++) 
    	if(!vis[i])coun++,solve(i); 
    	
    	ll ans = 0; 
    	for(int i=1;i<=n;i++) 
    	ans+=dis[i]; 
    	ans+=(coun*c); 
    	
    	ll minn = ans,sum=0,temp;  
    	sort(dis+1,dis+n+1,greater<int>());
    	for(int i=1;i<=n;i++) { 
    	  sum+=dis[i]; 
            temp = ans-sum+i*c;
    	   if(temp<=minn)minn=temp,coun++;
    	}
    	
    	printf("Case %lld: %lld %lld\n",++cs,minn,coun);
    }
	return 0;
}
