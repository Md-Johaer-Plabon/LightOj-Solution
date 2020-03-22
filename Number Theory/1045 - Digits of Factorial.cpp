/* Name : Johaer Plabon.
   Dept. Of CSE,SEC.
   11th Batch(2017-18).

   Problem Name : Digits Of Factorial.
   Solution Idea : We can get total digits of a number by dividing the number by 10.
   If we can divide a number by 10 for 2 times,  total digits are 3.Like 100,123 etc.
   We can perform this work without using any loop,in O(1) time using logarithm.
   We can divide a number,N by 10 for log10(N) times.Where total digits are log10(n)+1.
   So we can divide 'b' by 'a' for loga(b) times.But this is not possible to perform in our
   Programme.

   Again, loga(b) = log10(b)/log10(a).///In programme log10(n)=log(n).///
   So we have to use this formula.
   After generating all of total digits, our ans will be
   [ (total digit)/log(given base) ].
*/



#include<bits/stdc++.h>
#define ll long long
using namespace std;
double digit[1000001];
void func(){
for(int i=2;i<=1000000;i++){
    digit[i]=digit[i-1]+log(i);
}
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    func();
    int t,cs=0,n,b, temp;
    cin>>t;
    while(t--){
      cin>>n>>b;
      if(!n) temp = 1;
      else temp = (digit[n]/(double)log(b)) +1;
      cout<<"Case "<< ++cs<<": "<<temp<<endl;
    }
return 0;
}
