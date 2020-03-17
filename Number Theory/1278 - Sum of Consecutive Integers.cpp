#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>v;
bool a[10000009];
void sieve (){
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
ll t,cs=0;
cin>>t;
while(t--){
    ll n,res=1;
    cin>>n;
    if(n<3)cout<<"Case "<<++cs<<": "<<0<<endl;
    else{
        while(n%2==0)n/=2;
        for(ll i=0;v[i]*v[i]<=n&&i<v.size();i++){
            ll coun=0;
            while(n%v[i]==0)
            n/=v[i],coun++;
            if(coun)res*=(coun+1);
        }
        if(n>1)res*=2;
        cout<<"Case "<<++cs<<": "<<res-1<<endl;
    }
}
return 0;
}
