#include<bits/stdc++.h>
using namespace std;
int rr, cc;
int x1, x2;
int color[100][100];
int dist[100][100];
vector<pair<int,int> >v;
void gener(){
  for(int i=0;i<v.size();i++)
    color[v[i].first][v[i].second]=0,dist[v[i].first][v[i].second]=0;
}
int check(int i, int j)
{
    if(color[i][j]==0){
            color[i][j] = 1;
            v.push_back({i,j});
            dist[i][j] = dist[x1][x2] + 1;
            return 1;
    }
    if(color[i][j]==5){
         dist[i][j] = dist[x1][x2] + 1;
            return 5;
    }
    return 0;
}
int valid(int r,int c){
if(r>=0&&r<rr&&c>=0&&c<cc)return 1;
else return 0;
}
int bfs(int s1, int s2)
{
    queue<pair<int, int> >q;
    q.push({s1, s2});
    v.push_back({s1,s2});
    while(!q.empty()){
        x1 = q.front().first;
        x2 = q.front().second;
        color[x1][x2] = 1;
        q.pop();
        if(valid(x1-1,x2)==1 && check(x1-1, x2)==1) q.push({x1-1, x2});
        if(check(x1-1, x2)==5)return dist[x1-1][x2];
        if(valid(x1+1,x2)==1 && check(x1+1, x2)==1) q.push({x1+1, x2});
        if(check(x1+1, x2)==5)return dist[x1+1][x2];
        if(valid(x1,x2-1)==1 && check(x1, x2-1)==1) q.push({x1, x2-1});
        if(check(x1, x2-1)==5)return dist[x1][x2-1];
        if(valid(x1,x2+1)==1 && check(x1, x2+1)==1) q.push({x1, x2+1});
        if(check(x1, x2+1)==5)return dist[x1][x2+1];
    }
}
 
int main()
{
    int t,cs=0;
    cin>>t;
    while(t--){
       v.clear();
        char ch;
        cin>>rr>>cc;
        memset(color, 0, sizeof color);
        memset(dist, 0, sizeof dist);
        for(int i=0; i<rr; i++){
            for(int j=0; j<cc; j++){
                cin>>ch;
    if(ch=='#'||ch=='m')color[i][j] = 1;
    else if(ch=='h')color[i][j]=5;
    else if(ch=='a'||ch=='b'||ch=='c')v.push_back({i,j});
            }
        }
        int maxx=0,res;
    for(int i=0;i<3;i++){
            gener();
        res=bfs(v[i].first,v[i].second);
       maxx=max(maxx,res);
    }
    cout<<"Case "<<++cs<<": "<<maxx<<endl;
    }
    return 0;
}
