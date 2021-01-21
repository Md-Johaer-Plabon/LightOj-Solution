/* 
Name : Joaher Plabon 
Dept : CSE, Sylhet Engineering College 
*/


#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005],empt; 
int vis[100005],maxx,ind,node;
map<int,int>dis;  
vector<pair<int,int> >tr; 
int coun=0;
void dfs(int x,int cost,int chk){
	vis[x]=1; 
	if(maxx<dis[x])maxx=dis[x],ind=x; 
	coun++; 
	empt.push_back(x);
	for(int i=0;i<v[x].size();i++) 
    	if(!vis[v[x][i]]) {
       dis[v[x][i]]=cost+1; 
       dfs(v[x][i],cost+1,chk); 
    	} 
}
int main() {
	int t,cs=0;
	cin>>t;
	while(t--){
		int n,m,x,y; 
		node=0;
		printf("Case %d:\n",++cs);
		for(int i=0;i<=100000;i++)v[i].clear(),vis[i]=-1; 
		tr.clear();
		cin>>n>>m;
		
		for(int i=0;i<m;i++)
		cin>>x>>y,v[x].push_back(y),v[y].push_back(x),vis[x]=0,vis[y]=0; 
		
		for(int i=1;i<=n;i++)
		     if(!vis[i]){  
		     	dis.clear();
		     	dis[i]=0,maxx=0,coun=0;
		          dfs(i,0,0); 
	   for(int i=0;i<empt.size();i++)vis[empt[i]]=0; 
	   empt.clear();
		     dis.clear(); 
		       dis[ind]=0; 

		       maxx=0,coun=0;
		          dfs(ind,0,1); 
        tr.push_back({maxx,coun}),node=max(node,coun); 
	    //for(int i=0;i<empt.size();i++)vis[empt[i]]=0; 
	    empt.clear();
		     } 
		int q; 
		sort(tr.begin(),tr.end(),greater<pair<int,int> >() ); 

		cin>>q; 

		while(q--){
		   scanf("%d",&x); 
		   if(x>node)printf("impossible\n");
		   else if(x<=tr[0].first+1)printf("%d\n",x-1); 
		   else {
		   	  for(int i=0;i<tr.size();i++) 
		   	  if(x<=tr[i].second){ 
		   	  printf("%d\n",tr[i].first+2*(x-(tr[i].first+1))); 
		   	  break;}
		   	  
		   }
		}
	}
	return 0;
}
