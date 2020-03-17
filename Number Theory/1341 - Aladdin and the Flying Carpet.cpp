#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v;
bool arr[1000010];
void sieve(){
    v.push_back(2);
for(ll i=4;i<=100008;i+=2)
    arr[i]=1;
for(ll i=3;i<=1000008;i+=2){
    if(!arr[i]){
        v.push_back(i);
     if(i*i<=1000008)
        for(ll j=i*i;j<=1000008;j+=i+i)
        arr[j]=1;
    }
}
}
 
ll NOD(ll x){
    ll sum=1;
  for(int i=0;i<v.size()&&v[i]*v[i]<=x;i++){
    ll coun=0;
    while(x%v[i]==0){
    x/=v[i],coun++;
    }
  sum*=(coun+1);
  }
  if(x>1)sum*=2;
  if(sum%2)sum--;
  return sum/2;
}
int main (){
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
sieve();
ll t,cs=0;
cin>>t;
while(t--){
    ll n,m;
    cin>>n>>m;
    ll res=NOD(n);
    if(m*m>n)cout<<"Case "<<++cs<<": "<<0<<endl;
    else{
        for(ll i=1;i<m;i++)
        if(n%i==0)res--;
    cout<<"Case "<<++cs<<": "<<res<<endl;
    }
}
return 0;
}
