#include<bits/stdc++.h>
using namespace std;
map<int, set<int> >vc;
set<int>::iterator it;
map<int, int>mp;
bool check[1001];
void sieve()
{
    check[1] = true;
    for(int i=2; i<=1000; i++){
        if(check[i]==false && (long long)i*i<=1000){
            for(int j=i*i; j<=1000; j+=i){
                check[j]=true;
            }
        }
    }
 
    for(int x=4; x<=1000; x++){
        int temp = ceil(sqrt(x));
        for(int i=2; i<=temp; i++){
            if(x%i==0 && check[i]==0) vc[x].insert(i);
            if(x%(x/i)==0 && check[x/i]==0) vc[x].insert(x/i);
        }
    }
}
 
int bfs(int n, int m)
{
    int minn = 1000;
    mp[n] = 1;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int t = q.front();//sum
        //if(t>m+10000000) break;
        //cout<<t<<endl;
        q.pop();
        for(it=vc[t].begin(); it!=vc[t].end(); it++){
            if(t+*it==m) return mp[t];
            if(mp[t+*it]==0 && t+*it<=1000) mp[t+*it]=mp[t]+1, q.push(t+*it);
        }
    }
    return -1;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sieve();
    int x, y, tc;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        mp.clear();
        cin>>x>>y;
        if(x==y) cout<<"Case "<<cs<<": "<<0<<endl;
        else cout<<"Case "<<cs<<": "<<bfs(x, y)<<endl;
    }
}
