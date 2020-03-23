 
/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name : False Ordering.
*/



#include<bits/stdc++.h>
using namespace std;
map<int,set<int,greater<int> > >s;
map<int,set<int,greater<int> > >::iterator it;
set<int>::iterator it1;
vector<int>v;
void func(){
for(int i=1;i<=1000;i++){
        int t=sqrt(i),coun=0;
    for(int j=1;j<=t;j++){
        if(i%j==0)coun+=2;
    }
    if(t*t==i)coun--;
    s[coun].insert(i);
}
for(it=s.begin();it!=s.end();it++){
    for(it1=s[it->first].begin();it1!=s[it->first].end();it1++){
       v.push_back(*it1);
    }
}
}
 
int main (){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
func();
int t,cs=0;
cin>>t;
while(t--){
   int n;
   cin>>n;
   cout<<"Case "<<++cs<<": "<<v[n-1]<<endl;
}
return 0;
}
