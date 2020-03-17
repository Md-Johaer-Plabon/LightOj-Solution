#include<bits/stdc++.h>
#define ll long long int
using namespace std;
map<int,int>mp[200];
map<int,int>::iterator it;
ll n=2,num=2;
void func(){
for(int j=0;j<=100;j++){
  while(n%2==0){
    mp[num][2]++;
    n/=2;
  }
for(int i=3;n>2;i+=2){
    while(n%i==0){
        mp[num][i]++;
        n/=i;
    }
}
//cout<<"Check"<<endl;
num++;
n=num;
}
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
ll n,m,t,cs=0;
func();
 map<int,int>pr;
 map<int,int>::iterator it1;
cin>>t;
while(t--){
   cin>>n;
   for(int i=2;i<=n;i++){
    for(it=mp[i].begin();it!=mp[i].end();it++)
        pr[it->first]+=it->second;
   }
    it1=pr.begin();
        cout<<"Case "<<++cs<<": "<<n<<" = "<<it1->first<<" ("<<it1->second<<")";
    it1++;
    for(;it1!=pr.end();it1++){
        cout<<" * "<<it1->first<<" ("<<it1->second<<")";
    }
    cout<<endl;
    pr.clear();
   }
return 0;
}
