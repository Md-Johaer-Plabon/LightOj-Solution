
/*
   Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name: Coin Change (II).
   Topic : Coin Changing (DP).
   
 */






#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define ll long long
int main ()
{
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
 
    ll n,t,cs=0;
    cin>>t;
    while(t--)
    {
        ll k,dp[10009]= {0},coin[160];
        cin>>n>>k;
        dp[0]=1;
        for(int i=0; i<n; i++)cin>>coin[i];
        for(int j=0; j<n; j++)
        {
            for(int i=1; i<=k; i++)
            {
                if(i>=coin[j])
                {
                    dp[i] = (dp[i] %mod + dp[i - coin[j]]%mod)%mod;
                }
            }
        }
        cout<<"Case "<<++cs<<": "<<dp[k]<<endl;
    }
    return 0;
}
