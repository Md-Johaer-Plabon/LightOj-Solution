#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
int t,cs=0;
cin>>t;
while(t--){
    ll temp=0,b,coun=0;
    string a;
    cin>>a>>b;
    b=abs(b);
    int siz=log10(b)+1;
    for(int i=0;i<a.size();i++){
        if(a[i]=='-')continue;
       temp=temp*10+a[i]-'0';
       coun++;
       if(coun>=siz)
        temp%=b;
    }
    if(temp>0)cout<<"Case "<<++cs<<": "<<"not divisible"<<endl;
    else cout<<"Case "<<++cs<<": "<<"divisible"<<endl;
}
return 0;
}
