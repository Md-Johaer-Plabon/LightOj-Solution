#include<bits/stdc++.h>
#define ll long long int
#define f first
#define s second
using namespace std;
bool a[1000009];
vector<ll>v;
map<ll, ll>mp, p;
map<ll, ll>::iterator it;
void sieve(){
    v.push_back(2);
 for(ll i=4;i<=1000000;i+=2)
    a[i]=1;
 for(ll i=3;i<=1000000;i+=2){
    if(!a[i]){
        v.push_back(i);
        if(i<=1000)
            for(ll j=i*i;j<=1000000;j+=i+i)
            a[j]=1;
    }
 }
}
 
void gen(ll n)
{
    ll cnt = 0;
    for(int i=0;i<v.size() && v[i]*v[i]<=n; i++){
        cnt = 0;
        while(n%v[i]==0) n/=v[i], cnt++;
        if(cnt) mp[v[i]] = cnt;
    }
    if(n>1) mp[n] = 1;
}
 
int pgen(ll n)
{
    ll cnt = 0;
    for(int i=0; v[i]*v[i]<=n && i<v.size(); i++){
        cnt = 0;
        while(n%v[i]==0) n/=v[i], cnt++;
        if(cnt && mp[v[i]]) p[v[i]] = max(p[v[i]], cnt);
        else if(cnt) return 0;
    }
    if(n>1 && mp[n]) p[n] = max(p[n], (ll)1);
    else if(n>1) return 0;
    return 1;
}
 
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    sieve();
ll tc,n,cs=0;
ll x, y, l, res;
cin>>tc;
while(tc--){
    mp.clear(), p.clear();
    cin>>x>>y>>l;
    if(l%x || l%y){
        cout<<"Case "<<++cs<<": impossible"<<endl;
        continue;
    }
    gen(l);
    res = pgen(x);
    if(res) res = pgen(y);
    if(res){
        for(it=mp.begin(); it!=mp.end(); it++)
            if(it->s != p[it->f]) res *= pow(it->f, max(it->s, p[it->f]));
           
        cout<<"Case "<<++cs<<": "<<res<<endl;
    }
    else cout<<"Case "<<++cs<<": impossible"<<endl;
 
}
return 0;
}
