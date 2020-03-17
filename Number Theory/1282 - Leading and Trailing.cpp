#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int bigmod(ll n,ll p){
if(p==0)return 1;
if(p%2==0)return ((bigmod(n,p/2)%1000)*(bigmod(n,p/2)%1000))%1000;
else return ((n%1000)*(bigmod(n,p-1)%1000))%1000;
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
ll t,cs=0;
cin>>t;
while(t--){
    ll n,m;
    cin>>n>>m;
    ll res=bigmod(n,m);
    double x=m*log10(n);
    ll res1=int(pow(10,x-(int)x)*100);
   // cout<<"Case "<<++cs<<": "<<res1<<" "<<res<<endl;
    printf("Case %lld: %03lld %03lld\n", ++cs, res1, res);
}
return 0;
}
