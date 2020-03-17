#include<bits/stdc++.h>
using namespace std;
int rr, cc;
int x1, x2;
int xx, bx, sum, minsum = INT_MAX;
map<pair<int, int>, int>mp, color, dist;
 
int check(int i, int j)
{
    if(color[{i,j}]==0){
            color[{i,j}] = 1;
            dist[{i,j}] = dist[{x1,x2}] + 1;
            return 1;
    }
    return 0;
}
 
 
int valid(int r,int c){
    if(r>=0&&r<rr&&c>=0&&c<cc)return 1;
    else return 0;
}
 
 
int bfs(int s1, int s2)
{
    sum = 0, bx=0;
    color.clear(), dist.clear();
    queue<pair<int, int> >q;
    q.push({s1, s2});
    while(!q.empty()){
        x1 = q.front().first;
        x2 = q.front().second;
        color[{x1,x2}] = 1;
        if(mp[{x1,x2}]>0) sum+= ceil((float)dist[{x1,x2}]/(float)mp[{x1,x2}]), bx++;
        q.pop();
        if(valid(x1-2,x2+1)==1 && check(x1-2,x2+1)==1) q.push({x1-2,x2+1});
        if(valid(x1-2,x2-1)==1 && check(x1-2,x2-1)==1) q.push({x1-2,x2-1});
        if(valid(x1+2,x2-1)==1 && check(x1+2,x2-1)==1) q.push({x1+2,x2-1});
        if(valid(x1+2,x2+1)==1 && check(x1+2,x2+1)==1) q.push({x1+2,x2+1});
        if(valid(x1-1,x2+2)==1 && check(x1-1,x2+2)==1) q.push({x1-1,x2+2});
        if(valid(x1-1,x2-2)==1 && check(x1-1,x2-2)==1) q.push({x1-1,x2-2});
        if(valid(x1+1,x2+2)==1 && check(x1+1,x2+2)==1) q.push({x1+1,x2+2});
        if(valid(x1+1,x2-2)==1 && check(x1+1,x2-2)==1) q.push({x1+1,x2-2});
    }
}
 
int main()
{
    int tc;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        minsum = INT_MAX;
        mp.clear();
        cin>>rr>>cc;
        char ch;
        for(int i=0; i<rr; i++){
            for(int j=0; j<cc; j++){
                cin>>ch;
                if(ch!='.') mp[{i,j}]=ch-'0';
            }
        }
        xx = mp.size();
        if(xx==1){
            cout<<"Case "<<cs<<": 0"<<endl;
            continue;
        }
        for(int i=0; i<rr; i++){
            for(int j=0; j<cc; j++){
                bfs(i, j);
                if(bx==xx) minsum = min(minsum, sum);
            }
        }
        if(minsum==INT_MAX) cout<<"Case "<<cs<<": -1"<<endl;
        else cout<<"Case "<<cs<<": "<<minsum<<endl;
    }
}
