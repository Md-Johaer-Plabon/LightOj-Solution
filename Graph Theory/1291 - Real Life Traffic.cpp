/* 
Name : Joaher Plabon 
Dept : CSE,Sylhet Engineering College. 
Topic : Bi-Connected Component. 
Hints : Steps --> 
            1. Apply Tarjan's algorithm in a modified way to make each cycles a component. 
            2. Consider each component a node which will make the graph a tree. 
            3. Result = ceil (A + B)/2. 
                 Where,
                    A =  Number of node which has no child . 
                    B =  If root node has one child,then B=1 else B=0. 
                    
 */ 
 
 
 #include <bits/stdc++.h>
using namespace std; 
vector<int>v[30005],nv[30005]; 
vector<int>vis(30005,0),start(30005,0),en(30005,0); 
vector<int>par(30005,0),sys(30005,0),low(30005,0); 
stack<int>st; 
int ind , tme =0 , chk=0,coun; 
void dfs(int x){
	vis[x]=1; 
	start[x] = ++tme; 
	   for(int i=0;i<nv[x].size();i++) 
	   if(!vis[nv[x][i]]) { 
	   if(par[x]==-1)chk++;
	   dfs(nv[x][i]); 
	   }
	   
	en[x] = ++tme; 
	
	if(en[x]-1==start[x])coun++;
}
void mody_dfs(int x){ 
	vis[x] = low[x] = ++tme; 
	st.push(x);
	for(int i=0;i<v[x].size();i++) {
		if(!vis[v[x][i]]) {
		  par[v[x][i]]=x,
		  mody_dfs(v[x][i]); 
		  
		  low[x] = min (low[x],low[v[x][i]]); 
		  
		}
       if(v[x][i]!=par[x]) 
       low[x]  = min(low[x],vis[v[x][i]]);
	} 
	
	if(low[x]==vis[x]){
		chk++; 
		while(!st.empty()){ 
	    ind = st.top(); 
	    st.pop();
		sys[ind]=chk; 
		if(ind==x)break;
		}
	}
}
int main() { 
	int t,cs=0; 
	cin>>t; 
	while(t--){ 
		for(int i=0;i<=30000;i++) 
		v[i].clear(),nv[i].clear(),vis[i]=0,start[i]=0,en[i]=0,par[i]=-1, 
		sys[i]=i,low[i]=INT_MAX; 
		while(!st.empty())st.pop(); 
		
		int n,m,x,y; 
		cin>>n>>m; 
		for(int i=0;i<m;i++) 
		cin>>x>>y,v[x].push_back(y),v[y].push_back(x); 
		tme=0,chk=n-1; 
		
		for(int i=0;i<n;i++) 
		if(!vis[i]) 
		 mody_dfs(i); 
		for(int i=0;i<n;i++) 
		  for(int j=0;j<v[i].size();j++) 
		      if(sys[i]!=sys[v[i][j]]) 
		         nv[sys[i]].push_back(sys[v[i][j]]),
		         nv[sys[v[i][j]]].push_back(sys[i]); 
	tme = chk = coun = 0;
	for(int i=0;i<=30000;i++)vis[i]=0,par[i]=0; 
	for(int i=0;i<=30000;i++)
		if(nv[i].size()){ 
			par[i]=-1;
		  dfs(i);break;} 
		  
    if(coun==0)printf("Case %d: %d\n",++cs,coun); 
    else {
    	if(chk==1)coun++; 
    	if(coun%2)coun = coun/2+1; 
    	else coun/=2; 
    	printf("Case %d: %d\n",++cs,coun);
    }
	}
	return 0;
}
