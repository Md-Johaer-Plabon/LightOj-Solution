#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int >color,level;
int rr, cc;
pair<int, int> n;
map<int, queue<pair<int, int> > > mp;
 
int valid(int x, int y, int t)
{
    if(x==0||y==0) return 1;
    if(x==rr+1||y==cc+1) return 1;
    if(t && (color[{x,y}]==0||color[{x,y}]==2)){
        color[{x,y}]=-1, mp[t].push({x, y});
        return 0;
    }
    if(color[{x,y}]==0 &&!t){
        mp[t].push({x, y}), color[{x,y}]=2;
        return 0;
    }
    return -1;
}
 
int call_bfs()
{
    mp[0].push(n);
    mp[0].push({-1,-1});
    while(mp[0].front().first!=-1){
        while(mp[1].front().first!=-1){
            int x = mp[1].front().first;
            int y = mp[1].front().second;
            mp[1].pop();
            valid(x-1, y, 1);
            valid(x+1, y, 1);
            valid(x, y-1, 1);
            valid(x, y+1, 1);
        }
        mp[1].pop();
        mp[1].push({-1,-1});
        while(!mp[0].empty() && mp[0].front().first!=-1){
            int x = mp[0].front().first;
            int y = mp[0].front().second;
            mp[0].pop();
            int t = valid(x+1, y, 0);
            if(t == 1) return level[{x,y}]+1;
            else if(t==0)level[{x+1,y}]=level[{x,y}]+1;
            t = valid(x-1, y, 0);
            if(t == 1) return level[{x,y}]+1;
            else if(t==0)level[{x-1,y}]=level[{x,y}]+1;
            t = valid(x, y+1, 0);
            if(t == 1) return level[{x,y}]+1;
            else if(t==0)level[{x,y+1}]=level[{x,y}]+1;
            t = valid(x, y-1, 0);
            if(t == 1) return level[{x,y}]+1;
            else if(t==0)level[{x,y-1}]=level[{x,y}]+1;
        }
        mp[0].pop();
        mp[0].push({-1,-1});
    }
    return -1;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tc;
    char ch;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>rr>>cc;
        color.clear();
        level.clear();
        for(int i=1; i<=rr; i++){
            for(int j=1; j<=cc; j++){
                cin>>ch;
                if(ch=='F')color[{i,j}]=-1, mp[1].push({i, j});
                else if(ch=='#')color[{i,j}]=1;
                else if(ch=='J') color[{i,j}]=2, n = {i, j};
            }
        }
 
        mp[1].push({-1,-1});
        int res = call_bfs();
        if(res==-1) cout<<"Case "<<cs<<": IMPOSSIBLE"<<endl;
        else cout<<"Case "<<cs<<": "<<res<<endl;
        mp.clear();
    }
}
