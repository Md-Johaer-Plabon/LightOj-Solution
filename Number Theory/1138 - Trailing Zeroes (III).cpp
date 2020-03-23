
 
/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name : Trailing zeroes (III).
   Solution Idea : The problem is to find out the number where the factorial of number 
   contain given zeroes in trail.Here we have to find out the minimal number which
   contain essential amount of 5.Because of a large amount of even number or 2 than 5,
   there is no need to check how many 2 are there.We can perform this work using
   binary search in log2(n) time.
*/


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
