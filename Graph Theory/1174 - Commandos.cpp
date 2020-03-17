#include<bits/stdc++.h>
using namespace std;
map<int ,vector<int> >mp;
int dist[2][105],color[105];
void bfs(int n,int in){
memset(color,0,sizeof color);
     queue<int>q;
     q.push(n);
     dist[in][n]=0;
     color[n]=1;
     while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<mp[x].size();i++){
            if(color[mp[x][i]]==0){
                q.push(mp[x][i]);
                color[mp[x][i]]=1;
                dist[in][mp[x][i]]=dist[in][x]+1;
            }
        }
     }
}
int main (){
int t,cs=0;
cin>>t;
while(t--){
   int n,m,x,y;
   cin>>n>>m;
   mp.clear();
   memset(dist,0,sizeof dist);
   memset(color,0,sizeof color);
   while(m--){
        cin>>x>>y;
    mp[x].push_back(y);
    mp[y].push_back(x);
   }
   cin>>x>>y;
   bfs(x,0);
   bfs(y,1);
   int maxx=0;
   for(int i=0;i<n;i++)
    maxx=max(maxx,dist[0][i]+dist[1][i]);
   cout<<"Case "<<++cs<<": "<<maxx<<endl;
}
return 0;
}
