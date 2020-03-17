#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >mp;
map<int,int>seen,coun;
vector<int>v;
int ans,res;
void dfs(int node){
    seen[node]=1;
    coun[node]++;
if(coun[node]==res)ans++;
for(int i=0;i<mp[node].size();i++)
    if(seen[mp[node][i]]==0)
    dfs(mp[node][i]);
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
int t,n,m,x,y,k,cs=0;
cin>>t;
while(t--){
        ans=0;
        mp.clear();
        v.clear();
        seen.clear();
        coun.clear();
   cin>>k>>n>>m;
   res=k;
   while(k--)
    cin>>x,v.push_back(x);
   while(m--)
    cin>>x>>y,mp[x].push_back(y);
    for(int i=0;i<v.size();i++)
        seen.clear(),dfs(v[i]);
    cout<<"Case "<<++cs<<": "<<ans<<endl;
}
return 0;
}
