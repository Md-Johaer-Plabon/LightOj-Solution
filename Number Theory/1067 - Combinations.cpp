#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000003
ll X,X1,Y,Y1,res1=1;
ll a[1000009],b[1000009];
void egcd(ll a, ll b){
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
void modIN(){
    ll t=1;
    a[0]=a[1]=b[0]=b[1]=1;
for(ll i=2;i<=1000000;i++){
            t=((t%mod)*(i%mod))%mod;
            b[i]=t;
            egcd(i,mod);
            res1=((res1%mod)*(X%mod+mod)%mod)%mod;
            res1=(res1+mod)%mod;
            a[i]=res1;
        }
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    modIN();
ll t,cs=0,res=1;
cin>>t;
while(t--){
    ll n,k;
    cin>>n>>k;
        res=(b[n]*a[k]*a[n-k])%mod;
        cout<<"Case "<<++cs<<": "<<res<<endl;
}
return 0;
}
