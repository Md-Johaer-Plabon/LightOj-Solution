#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
 ll t,cs=0;
 cin>>t;
 while(t--){
    ll n,sum=0;
    cin>>n;
    for(ll i=2;i*i<=n;i++){
       ll j=n/i;
       sum+=((i+j)*(j-i+1))/2;
       sum+=(j-i)*i;
    }
   cout<<"Case "<<++cs<<": "<<sum<<endl;
 }
return 0;
}
