
/*
   Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name: Coin Change (I).
   Topic : Coin Changing (DP).
   
 */


#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define ll long long
int main ()
{
    ll n,t,cs=0;
    cin>>t;
    while(t--)
    {
        ll k,dp[1009]= {0},coin[60],cm[60];
        cin>>n>>k;
        dp[0]=1;
        for(int i=0; i<n; i++)cin>>coin[i];
        for(int i=0; i<n; i++)cin>>cm[i];
        for(int j=0; j<n; j++)
        {
            for(int i=k; i>=1; i--)
            {
                if(i>=coin[j])
                {
                    ll temp=0;
                    for(int s=0 ; s<cm[j]; s++) // Loop for limitations of coins.
                    {
                        temp+=coin[j];
                        if(temp<=i)
                            dp[i] = (dp[i] %mod + dp[i - temp]%mod)%mod;
                    }
                }

            }

        }
        cout<<"Case "<<++cs<<": "<<dp[k]<<endl;
    }
    return 0;
}
