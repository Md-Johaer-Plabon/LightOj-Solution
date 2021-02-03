/* Name : Johaer Plabon.
   Dept. Of CSE,SEC.
   11th batch(2017-18).

   Problem Name : Trailing Zeros (I).
   Solution Idea : The possible bases when the number will contain at least a zero in 
   Trail is total number of divisiors of that number.Here if you approach bruteforce
   to count total divisior, you will get TLE.
   You can find this in O(log(n)) time. For that you have to find out the prime factors.
   
   Example : 20 = 2^2 * 5^1.So total divs are (2+1)*(1+1) = 6.
   So the eqn stands, if N = P1^k1 * P2^k2 * P3^k3.......Pn^kn.
    Then, NOD(N) = (k1+1)*(k2+1)*(k3+1)......(kn+1). 
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool arr[10000009];
vector<ll>v;
void factor(){
for(int i=0;i<=10000000;i++)arr[i]=true;
for(ll i=2;i<=10000000;i++){
    if(arr[i]){
        v.push_back(i);
        for(ll j=i*i;j<=10000000;j+=i)
            arr[j]=false;
    }
}
}
int main (){
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  // freopen("input.txt","rt",stdin);
   // freopen("ohno.txt","wt",stdout);
    factor();
     //cout<<v[v.size()-1]<<endl;
ll t,cs=0;
cin>>t;
while(t--){
   ll n,res=1;
   cin>>n;
   for(ll i=0;i<v.size()&&v[i]*v[i]<=n;i++){
        ll coun=1;
    while(n%v[i]==0)
    coun++,n/=v[i];
    res*=coun;
   }
   if(n>1)res*=2;
    res--;
   cout<<"Case "<<++cs<<": "<<res<<endl;
}
return 0;
}
