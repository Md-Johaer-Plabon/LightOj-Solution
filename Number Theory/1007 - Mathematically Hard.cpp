/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name : Mathemathematically  Hard.
   Solution Idea: It's a very easy problem of "Sieve Of Phi".
   Firstly we have to generate phi value in the array.Then as we have to calculate total 
   score between a range of[a,b],to save our time we have to store the cumulative sum in array.
   To save our memory we can store the cumulative sum in same array.Otherwise we have to face TLE
   to execute the programme.
   */





#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
ll phi[5000009];
vector<ll>v;
void sieve(){
for(ll i=1;i<=5000001;i++)phi[i]=i;
for(ll i=2;i<=5000001;i++){
        if(phi[i]==i)
    for(ll j=i;j<=5000001;j+=i)
        phi[j]-=phi[j]/i;
}
   ///Storing Cumulative sum of score in array
for(ll i=2;i<=5000000;i++){
    ll temp=phi[i];
    phi[i]*=temp;
    phi[i]+=phi[i-1];
}
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
    cout<<"Case "<<++cs<<": "<<phi[m]-phi[n-1]<<endl;
}
return 0;
}
 
