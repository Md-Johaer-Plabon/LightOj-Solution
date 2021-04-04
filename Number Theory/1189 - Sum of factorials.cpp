/* 
Name : Johaer Plabon 
Dept of CSE,Sylhet Engineering College. 
*/ 


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000000000000000000
int main() { 

	int t,cs=0;
	vector<pair<ll,ll> >v;
	ll temp=1;
	v.push_back({0,1});
	v.push_back({1,1});
	for(ll i=2;temp*i<=mx;i++)
	v.push_back({i,v[i-1].second*i}),
	temp*=i;
 
	cin>>t;
	while(t--){
	ll n;
	cin>>n;
	stack<int>st;
    for(int i=v.size()-1;i>=0;i--){
    if(n>=v[i].second){
    n-=v[i].second;
    st.push(v[i].first);
    }
    }
    
  printf("Case %d: ",++cs); 
   if(n>0)puts("impossible");
   else {
   	int x=st.top();st.pop();
   	printf("%d!",x);
   while(!st.empty()){
   x=st.top();st.pop();
   printf("+%d!",x);
   }
   printf("\n");
   }
}
	return 0;
}
