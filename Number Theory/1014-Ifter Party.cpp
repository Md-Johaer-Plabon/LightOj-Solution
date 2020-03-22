/*Name : Johaer Plabon.
  Dept. Of CSE,SEC.
  11th batch(2017-18).

  Problem Name : Ifter Party.
  Solution Idea : The problem is too much interesting.You are given two integers, total
  Piaju's and total piaju's which are left.Your task is to find the amount of piajus
  which are eaten by the contestants equally in ascending order.
  
  There maybe impossible case when the no. Of piajus which are left are greater than
  The piajus which are ate.Beacuse the contestants will continue their party(eating 
  piaju) until they can eat everyone equally. So the result will be the total divisiors
  (of number of piajus which are ate) who are greater than the amount of piajus which are
  left.
  
  Example:If there was 10 piajus during party and left no piaju after finishing 
  their party,then how they can make every partition equal so that there are no piaju?
  Ans may be 1(If 10 people eat 1 piaju), 2(If 5 people eat 2 piaju), 5(If 2 people 
  eat 5 piaju), 10(If anyone eats 10 piajus).

  But if there are 10 piajus and 6 piajus are left this case is impossible because 
  There are so many people in the party,So as it is possible to make a partition of 4
  People will also make a partition of 4 piaju as there has much piajus and then 2 piajus
  will left because there is no more possibilities to make another equal partition of piaju. 
*/

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
