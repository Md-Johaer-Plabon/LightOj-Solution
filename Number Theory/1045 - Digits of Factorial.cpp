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
