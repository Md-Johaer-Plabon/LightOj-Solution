/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
Topic : Bi-Connected Component. 
*/ 


#include <bits/stdc++.h>
using namespace std; 

vector<int>v[10005];
vector<int>vis(10005,0),low(10005,0),par(10005,0); 
vector<int>odd(10005,0),color(10005,0);  
stack<int>st;
int tme=0,chk,flag;

int bicolor(int x,int val){
      queue<int>q; 
      q.push(x); 
      odd[x]=0; 
      color[x]=0;
      while(!q.empty()){
      	int temp = q.front(); 
      	q.pop(); 
      	tme++;
      	 for(int i=0;i<v[temp].size();i++){
      	 	if(color[v[temp][i]]==val) 
      	 	color[v[temp][i]]=0,odd[v[temp][i]]=odd[temp]+1,
      	 	q.push(v[temp][i]); 
      	 	
      	 	if(color[v[temp][i]]!=val&&vis[temp]==vis[v[temp][i]]) 
      	 	  if(odd[temp]%2==odd[v[temp][i]]%2)chk=1;
      	 } 
      } 
      if(chk)return tme; 
      else return 0;
}

void tarjan(int x){
   	vis[x] = low[x] = ++tme; 
   	st.push(x);
   	   for(int i=0;i<v[x].size();i++){
   	   	if(!vis[v[x][i]]){
   	   	   	par[v[x][i]]=x; 
   	   	   	tarjan(v[x][i]); 
   	   	   	
   	   	   	low[x] = min(low[x],low[v[x][i]]);
   	   	}
   	   	
   	   	if(v[x][i]!=par[x]) 
   	   	low[x] = min(low[x],vis[v[x][i]]);
   	   } 
   	  if(low[x]==vis[x]){
   	  	int ind; 
   	  	flag++;
   	  	while(!st.empty()){
   	  	ind = st.top(); 
   	  	color[ind]=flag; 
   	  	st.pop(); 
   	  	if(ind==x)break;
   	  	} 
   	  } 
}

void clr(){
	for(int i=0;i<=10000;i++) 
	v[i].clear(),vis[i]=0,low[i]=0,par[i]=-1,color[i]=0,odd[i]=0; 
	while(!st.empty())st.pop(); 
	tme=0;
}

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){
		clr(); 
		int n,m,x,y; 
		cin>>n>>m; 
		for(int i=0;i<m;i++) 
		cin>>x>>y,v[x].push_back(y),v[y].push_back(x); 
		
		flag=0;
		for(int i=0;i<n;i++) 
		  if(!vis[i]) 
		    tarjan(i); 
		
		int ans =0;
		for(int i=0;i<n;i++)vis[i]=color[i];
		
		for(int i=0;i<n;i++) {
		  if(color[i]) { 
		    tme=0,chk=0; 
		       ans += bicolor(i,color[i]); 
		}
	} 
	printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}
