/* 
Author : Johaer Plabon 
         Dept. of CSE,SEC. 
         
Topic : MST (2nd Best MST) 
Complexity : O(v*E).

*/


#include <bits/stdc++.h>
using namespace std;
#define ff first 
#define ss second 
#define pii pair<int,int> 

vector<pair<pii,pii> >v;
vector<int>res,par(5005); 

int find(int x){
   if(x==par[x])return x; 
   return par[x] = find(par[x]);
}

void mst(){
	for(int i=0;i<v.size();i++){
		int x = find(v[i].ss.ff); 
		int y = find(v[i].ss.ss); 
		if(x!=y)res.push_back(v[i].ff.ss),par[x]=y;
	}
}


int mst2(int x,int y){ 
	int sum = 0,coun=0; 
	for(int i=0;i<=200;i++)par[i]=i;
	for(int i=0;i<v.size();i++){ 
		if(v[i].ff.ss==x)continue;
		int x = find(v[i].ss.ff); 
		int y = find(v[i].ss.ss); 
		if(x!=y)
		par[x] = y,sum+=v[i].ff.ff,coun++;
 	}
 	if(coun==y-1)
 	return sum; 
 	else return INT_MAX;
}

int main() {
	int t,cs=0;
	cin>>t; 
	while(t--){
		int n,m; 
		cin>>n>>m; 
		for(int i=0;i<=n;i++)par[i]=i; 
		v.clear(),res.clear();
		int x,y,z; 
		int minn = INT_MAX;
		for(int i=0;i<m;i++) 
		cin>>x>>y>>z,v.push_back({{z,i},{x,y}}); 
		sort(v.begin(),v.end()); 
		mst();
		printf("Case #%d : ",++cs);
		if(res.size()!=n-1){puts("No way");continue;} 
		for(int i=0;i<res.size();i++){
			int sum = mst2(res[i],n); 
			minn = min(sum,minn); 
		} 
		if(minn==INT_MAX)puts("No second way"); 
		
		printf("%d\n",minn);
	}
	return 0;
}
