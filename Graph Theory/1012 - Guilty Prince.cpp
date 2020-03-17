#include<bits/stdc++.h>
using namespace std;
int rr, cc,coun;
int x1, x2;
bool color[100][100];
int check(int i, int j)
{
    if(color[i][j]==0){
            color[i][j] = 1;
            return 1;
    }
    return 0;
}
int valid(int r,int c){
if(r>=0&&r<rr&&c>=0&&c<cc)return 1;
else return 0;
}
void bfs(int s1,int s2)
{
    queue<pair<int, int> >q;
    q.push({s1, s2});
     color[s1][s2] = 1;
    while(!q.empty()){
        x1 = q.front().first;
        x2 = q.front().second;
        q.pop();
        if(valid(x1-1,x2)==1 && check(x1-1, x2)==1) q.push({x1-1, x2}),coun++;
        if(valid(x1+1,x2)==1 && check(x1+1, x2)==1) q.push({x1+1, x2}),coun++;
        if(valid(x1,x2-1)==1 && check(x1, x2-1)==1) q.push({x1, x2-1}),coun++;
        if(valid(x1,x2+1)==1 && check(x1, x2+1)==1) q.push({x1, x2+1}),coun++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t,s1,s2,cs=0;
    char ch;
    cin>>t;
    while(t--){
            coun=1;
    cin>>cc>>rr;
        memset(color, 0, sizeof color);
        for(int i=0; i<rr; i++){
            for(int j=0; j<cc; j++){
                cin>>ch;
                if(ch=='#')
                color[i][j] = 1;
                if(ch=='@')s1=i,s2=j;
            }
        }
     bfs(s1,s2);
     cout<<"Case "<<++cs<<": "<<coun<<endl;
 
    }
    return 0;
}
