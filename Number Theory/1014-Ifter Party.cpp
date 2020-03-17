#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
ll t,cs=0;
cin>>t;
while(t--){
   ll n,m;
   cin>>n>>m;
   vector<ll>v;
   ll temp=n-m;
   if(m==0&&n>1)v.push_back(1);
   if(temp<=m){cout<<"Case "<<++cs<<": "<<"impossible"<<endl;continue;}
   for(ll i=2;i*i<=temp;i++)
   if(temp%i==0){v.push_back(i);
   if(temp/i!=i)v.push_back(temp/i);}
   v.push_back(temp);
   sort(v.begin(),v.end());
   cout<<"Case "<<++cs<<":";
   for(int i=0;i<v.size();i++)if(v[i]>m)cout<<" "<<v[i];
   cout<<endl;
}
 
return 0;
}
