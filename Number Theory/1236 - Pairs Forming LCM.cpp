#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool a[10000009];
vector<ll>v;
void sieve(){
    v.push_back(2);
 for(ll i=4;i<=10000000;i+=2)
    a[i]=1;
 for(ll i=3;i<=10000000;i+=2){
    if(!a[i]){
        v.push_back(i);
        if(i*i<=10000000)
            for(ll j=i*i;j<=10000000;j+=i+i)
            a[j]=1;
    }
 }
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    sieve();
ll tc,n,cs=0;
cin>>tc;
while(tc--){
    cin>>n;
    ll coun=0,sum=1;
    for(ll i=0;v[i]*v[i]<=n&&i<v.size();i++){
            ll coun=0;
        while(n%v[i]==0)
            coun++,n/=v[i];
        if(coun)sum*=(2*coun+1);
    }
    if(n>1)sum*=3;
    cout<<"Case "<<++cs<<": "<<(sum+1)/2<<endl;
}
return 0;
}
