#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t,cs=0,n;
    cin>>t;
    while(t--){
    cin>>n;
    int temp=sqrt(n);
    temp+=sqrt(n/2);
    cout<<"Case "<<++cs<<": "<<n-temp<<endl;
    }
 
    return 0;
}
