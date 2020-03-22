/* Name : Johaer Plabon
   Dept. of CSE,SEC.
   11th batch(2017-18).

   Problem Name : A New Function.
   Solution Idea : The problem is,You will be given a number N,You have to print
   total SOD from 1 to N. If we approach bruteforce for this problem, The programme
   will be crashed away.Now see in below:
   
   1 = (The number is not divisior of itself according to statement.)
   2 = "
   3 = "
   4 = 2
   5 =
   6 = 2 + 3
   7 =
   8 = 2 + 4
   9 = 3
  10 = 2 + 5
 Our task is to sum all of these divisiors.If we see top right side divisiors they are:
 2,3,4,5.We can use the formula of series sum 2-> n/2 or 10/2=5.
 
 There are few steps : A loop from 2 to √(10).
 Step 1: Calculate sum 2 to 10/2 using series law. /// [m/2 * (2*a + (m-1)*d)].
         Then calculate sum of extra 2 = (10/2 - 2)*2.

 Step 2: Again Calculate sum of series from 3 to 10/3.
         Then calculate sum of extra 3 = (10/3 - 3)*3.

   Now the sum is CSOD of 10.Continue the process to √(n) of any to calculate CSOD(n).
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
    ll n,sum=0;
    cin>>n;
    for(ll i=2;i*i<=n;i++){
       ll j=n/i;
       sum+=((i+j)*(j-i+1))/2;
       sum+=(j-i)*i;
    }
   cout<<"Case "<<++cs<<": "<<sum<<endl;
 }
return 0;
}
