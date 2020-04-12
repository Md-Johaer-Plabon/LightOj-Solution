
/*
   Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
 */




#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
int t,cs=0;
cin>>t;
while(t--){
ll n,dp[1000][1000]={0},i,j;
cin>>n;

for( i=1;i<=n;i++)
    for( j=1;j<=n;j++)
       if(i>=j)cin>>dp[i][j];
int coun=1;
   for(i=n+1;i<=2*n-1;i++){
int temp=n-coun;
coun++;
j=1;
while(temp--)
cin>>dp[i][j++];
}
for(i=1;i<=n;i++)for(j=1;j<=n;j++)
dp[i][j]=max(dp[i][j]+dp[i-1][j-1],dp[i][j]+dp[i-1][j]);
for(i=n+1;i<=2*n-1;i++)for(int j=1;j<=n;j++)
dp[i][j]=max(dp[i][j]+dp[i-1][j],dp[i][j]+dp[i-1][j+1]);
cout<<"Case "<<++cs<<": "<<dp[2*n-1][1]<<endl;
}
}
