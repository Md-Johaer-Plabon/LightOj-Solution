/* 
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College
*/ 


#include<bits/stdc++.h>
using namespace std;
#define ll long long 

long long har(int n){
    ll result=0;
    for(ll i=1;i*i<=n;i++){
        result+=(n/i);
        if((n/i)>n/(i+1))
            result+=((n/i)-(n/(i+1)))*i;
    }
    
    ll temp = sqrt(n);
    if(temp==(n/temp))
        result-=temp;
        
    return result;
}

int main(){
    ll t,n,cs=0;
    cin>>t;
    while(t--){
        cin>>n;
        printf("Case %lld: %lld\n",++cs,har(n));
    }
    return 0;
}
