
 
/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name : Help Hanzo.
   Topic : Segmented Sieve.
           It calculates total prime numbers in [a,b]<=10^6.

*/



#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool prime[1000009];
vector<ll>v;
void sieve()
{
    prime[1]=1;
    for(ll i=2; i<=1000009; i++)
    {
        if(!prime[i])
        {
            v.push_back(i);
            for(ll j=i*i; j<=1000009; j+=i)
                prime[j]=1;
        }
    }
}
int main ()
{
    ll n,m;
    sieve();
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        cin>>n>>m;
        bool seg[1000005]= {0};
        if(n==1)
            n=2;
        ll lim=sqrt(m);
        for(ll i=0; v[i]<=lim; i++)
        {
            ll temp=n/v[i];
            if(temp==0)
                temp++;
            temp*=v[i];
            if(temp<n||temp==v[i])
                temp+=v[i];
            for(ll j=temp; j<=m; j+=v[i])
            {
                seg[j-n]=1;
            }
        }
        ll cnt = 0;
        for(ll i=0; i<=m-n; i++)
            if(!seg[i])
                cnt++;
        cout<<"Case "<<cs<<": "<<cnt<<endl;
    }
    return 0;
}
