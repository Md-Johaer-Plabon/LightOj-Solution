#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define ll long long
int main (){
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
ll n,t,cs=0;
cin>>t;
while(t--){
 ll k,dp[10009]={0},coin[160],cm[60];
  cin>>n>>k;
  dp[0]=1;
 for(int i=0;i<n;i++)cin>>coin[i];
// for(int i=0;i<n;i++)cin>>cm[i];
 for(int j=0;j<n;j++){
 for(int i=1;i<=k;i++){
   if(i>=coin[j]){
   //ll temp=0;
 //  for(int s=0 ;s<cm[j];s++){
 //   temp+=coin[j];
  // if(temp<=i)
   dp[i] = (dp[i] %mod + dp[i - coin[j]]%mod)%mod;
}
}
 
}
 
//}
cout<<"Case "<<++cs<<": "<<dp[k]<<endl;
}
return 0;
}