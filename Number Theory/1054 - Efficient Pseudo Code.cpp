/* Name : Johaer Plabon
   Dept. Of CSE,SEC.
   11th batch(2017-18).

   Problem name : Efficient Pseudo Code.
   Solution Idea : The problem is combination of some algorithm such as Bigmod,ModInverse,
   Prime factor.We know,
   If N = p1^k1 * p2^k2.....pn^kn,then

   SOD(N) =  [p1^(k1+1) + 1/(k1-1)] * [p2^(k2+1) + 1/(k2-1)]......[pn^(kn+1)+1/(kn-1)].

   So, SOD(N^X) =  [p1^(k1+1) + 1/(k1-1)]^X * [p2^(k2+1) + 1/(k2-1)]^X.....
                   ...[pn^(kn+1)+1/(kn-1)]^X.
   By using ModInverse the denominators of equation we can solve the problem.
*/ 
   
   









#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define m 1000000007
using namespace std;
map<ll, bool>color;
vector<ll>prime;
ll X, Y, X1, Y1;
ll bigmod(ll n, ll p)
{
    if(p==0) return 1;
    ll x = bigmod(n, p/2)%m;
    x = (x*x)%m;
    if(p%2) x = (x*(n%m))%m;
    return x;
}
 
void egcd(ll a, ll b)
{
    if(!a){
        X = X1 = 0, Y = Y1 = 1;
        return;
    }
    egcd(b%a, a);
    X = Y1 - (b/a)*X1;
    Y = X1;
    X1 = X;
    Y1 = Y;
}
 
void sieve()
{
    prime.push_back(2);
    color[0]=color[1]=1;
    for(ll i=3; i<=100000; i+=2){
        if(!color[i]){
            prime.push_back(i);
            if(i<=1000){
                for(ll j=i*i; j<=100000; j+=i+i)
                    color[j] = 1;
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    ll tc, n, mod, res, fres, chk;
    sieve();
    color.clear();
    cin>>tc;
    for(ll cs=1; cs<=tc; cs++){
        cin>>n>>mod;
        res = fres = chk = 1;
        ll cnt, temp;
        for(ll i=0; i<prime.size() && prime[i]*prime[i]<=n; i++){
            cnt = 0;
            while(n%prime[i]==0)
                cnt++, n/=prime[i];
            if(cnt){
                res = bigmod(prime[i], mod*cnt+1) - 1;
                res = (res + m)%m;
                if(prime[i]!=2) egcd(prime[i]-1, m), temp = (X%m + m)%m;
                else temp = 1;
                res = (res * temp)%m;
                fres = (fres * res)%m;
            }
        }
        if(n>1){
            res = bigmod(n, mod+1) - 1;
            res = (res + m)%m;
            if(n-1!=1) egcd(n-1, m), temp = (m + (X%m))%m;
            else temp = 1;
            res = (res * temp)%m;
            fres = (fres*res)%m;
        }
        cout<<"Case "<<cs<<": "<<fres<<endl;
    }
}
 
