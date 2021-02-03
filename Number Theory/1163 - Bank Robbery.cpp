/* 
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College 
*/ 

#include <bits/stdc++.h>
using namespace std;
#define ul unsigned long long
int main() {
	int t,cs=0; 
	cin>>t;
	while(t--){
		ul n,temp,m; 
		cin>>n; 
		temp =n;
		n*=10; 
		n/=9; 
		printf("Case %d:",++cs);
		n--; 
		m=n; 
		m/=10;
		if(n-m==temp)cout<<" "<<n; 
		n++;
		m=n; 
		m/=10; 
		if(n-m==temp)cout<<" "<<n; 
		printf("\n");
	}
	return 0;
}
