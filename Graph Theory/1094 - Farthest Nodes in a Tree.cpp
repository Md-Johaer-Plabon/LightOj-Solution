#include<bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int> > >mp;
map<int,int>seen,dist;
int maxx,temp,n;
int bfs(int node){
   queue<int>u;
   u.push(node);
   seen[node]=2;
   while(!u.empty()){
    int x=u.front();
    if(maxx<=dist[x])
    maxx=dist[x],temp=x;
    u.pop();
    for(int i=0;i<mp[x].size();i++){
        if(seen[mp[x][i].first]==0){
            u.push(mp[x][i].first);
            dist[mp[x][i].first]=dist[x]+mp[x][i].second;
            seen[mp[x][i].first]=2;
        }
    }
   }
   return temp;
}
int main (){
int t,m,x,y,w,cs=0;
cin>>t;
while(t--){
        mp.clear();
        dist.clear();
        seen.clear();
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d%d",&x,&y,&w);
        mp[x].push_back({y,w});
        mp[y].push_back({x,w});
    }
 
    maxx=0;
    int nd=bfs(0);
    int ans=maxx;
    maxx=0;
    dist.clear();
    seen.clear();
    bfs(nd);
    ans=max(ans,maxx);
    printf("Case %d: %d\n",++cs,ans);
    }
return 0;
}
