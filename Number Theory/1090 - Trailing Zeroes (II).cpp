#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll searc(ll n, ll x)
{
    ll cnt = 0, v = x;
    while(n/v) cnt += n/v, v*=x;
    return cnt;
}
 
ll fpow(ll n, ll v)
{
    ll cnt = 0;
    while(n%v==0) cnt ++, n/=v;
    return cnt;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    ll tc, n, r, p, q, res, two, five;
    cin>>tc;
    for(ll cs=1; cs<=tc; cs++){
        cin>>n>>r>>p>>q;
        two = five = 0;
        five += searc(n, 5);
        two += searc(n, 2);
        five -= searc(r, 5);
        two -= searc(r, 2);
        five -= searc(n-r, 5);
        two -= searc(n-r, 2);
       
        five += q * fpow(p, 5);
        two += q * fpow(p, 2);
       
        res = min(five, two);
       
        cout<<"Case "<<cs<<": "<<res<<endl;
    }
}
