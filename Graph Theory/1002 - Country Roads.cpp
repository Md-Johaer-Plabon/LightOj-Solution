#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
map<ll, vector<pair<ll, ll> > >mp;
map<ll, ll>dist;
 
void dijkstra(ll n)
{
    dist[n] = 0;
    priority_queue<ll>pq;
    pq.push(n);
    while(!pq.empty()){
        ll t = pq.top(); pq.pop();
        for(ll i=0; i<mp[t].size(); i++){
            ll x = max(dist[t], mp[t][i].second);
            if(x<dist[mp[t][i].first]){
                dist[mp[t][i].first] = x;
                pq.push(mp[t][i].first);
            }
        }
 
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    ll tc, n, e, src;
    cin>>tc;
    for(ll cs=1; cs<=tc; cs++){
        cin>>n>>e;
        mp.clear();
        dist.clear();
        for(ll i=0; i<n; i++) dist[i] = inf;
        for(ll i=1, x, y, w; i<=e; i++){
            cin>>x>>y>>w;
            mp[x].push_back({y, w});
            mp[y].push_back({x, w});
        }
        cin>>src;
        dijkstra(src);
        cout<<"Case "<<cs<<":"<<endl;
        for(ll i=0; i<n; i++){
            if(dist[i]==inf) cout<<"Impossible"<<endl;
            else cout<<dist[i]<<endl;
        }
    }
}
