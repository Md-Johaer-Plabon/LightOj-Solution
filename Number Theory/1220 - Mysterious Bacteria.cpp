#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool a[1000009];
vector<ll>v;
void sieve(){
    v.push_back(2);
 for(ll i=4;i<=1000000;i+=2)
    a[i]=1;
 for(ll i=3;i<=1000000;i+=2){
    if(!a[i]){
        v.push_back(i);
        if(i<=1000)
            for(ll j=i*i;j<=1000000;j+=i+i)
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
    ll chk=0;
    if(n<0)chk=1,n=abs(n);
    ll coun,flag=1,gcd;
    for(ll i=0;v[i]*v[i]<=n&&i<v.size();i++){
            coun=0;
        while(n%v[i]==0)
            coun++,n/=v[i];
            if(flag && coun) gcd=coun,flag=0;
            if(coun)gcd=__gcd(gcd,coun);
    }
    if(n>1) cout<<"Case "<<++cs<<": "<<1<<endl;
    else if(chk&&gcd%2==0){
        while(gcd%2==0)gcd/=2;
        cout<<"Case "<<++cs<<": "<<gcd<<endl;
    }
    else cout<<"Case "<<++cs<<": "<<gcd<<endl;
}
return 0;
}
