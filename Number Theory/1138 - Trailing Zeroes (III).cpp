#include<bits/stdc++.h>
#define ll long long
using namespace std;
int func(int n){
    ll left=1,right=n*5+4,res=0;
    while(left<right){
        ll mid=(left+right)/2,m=5,sum=0;
while(m<=mid){
   sum+=(mid/m);
   m*=5;
}
   if(sum==n)res=mid;
   if(sum<n)left=mid+1;
   else right=mid;
    }
   return res;
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
int t,cs=0;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int res=func(n);
    if(!res)cout<<"Case "<<++cs<<": "<<"impossible"<<endl;
    else cout<<"Case "<<++cs<<": "<<res<<endl;
}
return 0;
}
