#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define ll long long
 
ll fcall(ll n,ll k){
 ll coin[160],cm[160],maxx=0;
  bool dp[100009]={0};
  dp[0]=1;
 for(int i=0;i<n;i++)cin>>coin[i];
 for(int i=0;i<n;i++)cin>>cm[i];
 for(int j=0;j<n;j++){
  ll coun=0,cnt[100009]={0};
 for(int i=1;i<=k;i++){
   if(i>=coin[j]){
   ll temp=cnt[i-coin[j]];
   if(dp[i-coin[j]] && !dp[i]&&temp<cm[j])
    dp[i]=1,cnt[i]=temp+1;
}
if(dp[i])coun++;
}
maxx=max(maxx,coun);
}
return maxx;
}
int main (){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
ll n,k,t,cs=0;
cin>>t;
while(t--){
cin>>n>>k;
ll res = fcall(n,k);
cout<<"Case "<<++cs<<": "<<res<<endl;
}
return 0;
}
