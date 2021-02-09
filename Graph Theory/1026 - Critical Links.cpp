/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
Topic : Articulation Bridge. 
*/ 


#include <bits/stdc++.h>
using namespace std; 

vector<int>v[10005]; 
vector<int>low(10005,0),vis(10005,0),parent(10005,0); 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >st; 
int tme=0;

void AP(int x){
   	vis[x] = low[x] = ++tme; 
   	for(int i=0;i<v[x].size();i++){
   		if(!vis[v[x][i]]){ 
   		parent[v[x][i]]=x;
   		AP(v[x][i]); 
   		low[x] = min(low[x],low[v[x][i]]);
   		
   		if(vis[x]<low[v[x][i]]) 
   		st.push({min(x,v[x][i]),max(x,v[x][i])}); 
   		}	
   		if(v[x][i]!=parent[x]) 
   		low[x] = min (low[x],vis[v[x][i]]);
   	}
}

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		for(int i=0;i<=10000;i++)
		v[i].clear(),low[i]=INT_MAX,vis[i]=0,parent[i]=-1; 
		int n,x,y,z; 
		string s; 
		cin>>n; 
		for(int i=0;i<n;i++){
			cin>>x>>s; 
			int temp = s[1]-'0';
			for(int j=2;j<s.size()-1;j++) 
			temp*=10,temp+=(s[j]-'0'); 
			for(int i=0;i<temp;i++) {
			cin>>y; 
			v[x].push_back(y),v[y].push_back(x);
			}
		}  
	  tme=0;
	  for(int i=0;i<n;i++) 
	    if(!vis[i])AP(i); 

	  printf("Case %d:\n%d critical links\n",++cs,st.size()); 
	  while(!st.empty())printf("%d - %d\n",st.top().first,st.top().second),
	  st.pop();
	}
	return 0;
}
