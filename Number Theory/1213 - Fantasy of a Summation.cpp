 
/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name : Fantasy summation.
   Solution Idea : The problem is,
   
                    
         for( i1 = 0; i1 < n; i1++ ) {
            for( i2 = 0; i2 < n; i2++ ) {
                for( i3 = 0; i3 < n; i3++ ) {
                    ...
                    for( iK = 0; iK < n; iK++ ) {
                        res = ( res + A[i1] + A[i2] + ... + A[iK] ) % MOD;
                    }
                    ...
                }
            }
      To calculate the result.We can perform this work in two steps.

    Step 1 : To calculate sum if we only add the value of last loop.
             If n = no. Of element & k = no. Of loops then the sum will be for the nested
    loop = n^(k-1) * sum.
 
    Step 2 : Now we have to count the extra value who have added to the sum.
    Ans is the sum of step1 will be added for extra k time.
    So the result will be (sum * k)%mod.

*/


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
