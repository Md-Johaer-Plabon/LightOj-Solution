/* 
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College 
*/ 


#include<bits/stdc++.h>
#define sz 1000000
using namespace std;
int main(){
    
    double arr[sz+5];
    int t,n,i,cs=0;
    arr[1]=1;
    for(i=2;i<sz;i++){
        arr[i]=arr[i-1]+(1.0/i);
    }
    cin>>t;
    while(t--){
        cin>>n;
        if(n<sz)
            printf("Case %d: %.10f\n",++cs,arr[n]);
        else
            printf("Case %d: %0.10f\n",++cs,log(n+.5)+0.5772156649);
    }
    return 0;
}
