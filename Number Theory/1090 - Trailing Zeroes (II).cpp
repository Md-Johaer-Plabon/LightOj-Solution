/* Name : Johaer Plabon
   Dept. of CSE,SEC.
   11th batch(2017-18).
   
   Problem Name : Trailing Zeroes (II).
   
   Solution Idea : If we calculate 5! how many trailing zeroes will be there?
   We know 5!=120, So the ans is 1 trailing zero.Because there are only one 5
   and for that because of multiplying it with even number(2 or 2^2=4) we have get 1 zero.
   So in this problem our task will be to count 5 and 2.
   How many 5 are in range of [1,100]. Ans is 100/5 + 100/5^2 = 24. As 5^3>100 we won't
   continue.
   Now we can count total 5 & 2 of 'ncr' = n!/r!*(n-r)! and also of p^q.












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
