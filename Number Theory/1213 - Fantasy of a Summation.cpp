#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll bigmod(ll n, ll k, ll m)
{
    if(k==0) return 1;
    ll x = bigmod(n, k/2, m);
    x = (x * x)%m;
    if(k%2) x = (x * n)%m;
    return x;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
   
    ll tc, n, k, res, m, temp;
    cin>>tc;
    for(ll cs=1; cs<=tc; cs++){
        cin>>n>>k>>m;
        ll sum = 0;
        for(ll x, i=0; i<n; i++)
            cin>>x, sum = (sum+x)%m;
        res = bigmod(n, k-1, m);
        res = (res * sum)%m;
        res = (res * k)%m;
        cout<<"Case "<<cs<<": "<<res<<endl;
    }
}
