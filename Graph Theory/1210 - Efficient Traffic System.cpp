/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
Topic : Strongly Connected Component,Cycles. 
Hint : Steps-> 
           1. Using SCC make the graph DAG(Directed Acyclic) 
           2. Consider each component as a node. 
           3. Count total zero indegree node and also total zero outdegree node. 
           4. To make the graph strongly connected , the result is , 
                      result = max(Total_zero_indegree , Total_zero_outdegree).
*/ 


#include <bits/stdc++.h>
using namespace std; 
vector<int>color(20005,0); 
vector<int>v[20005],rev[20005],dag[20005]; 
int tme,en[20005];
void topsort(int x){
   color[x]=2; 
   tme++; 
   for(int i=0;i<v[x].size();i++) 
      if(color[v[x][i]]==1) 
      topsort(v[x][i]); 
      
    tme++; 
    en[x]=tme;
} 

void scc(int x){
	color[x]=3; 
	en[x]=tme;
	for(int i=0;i<rev[x].size();i++) 
	if(color[rev[x][i]]==2)scc(rev[x][i]); 
} 

void dagsort(int x){
	color[x]=1; 
	tme++; 
	
	for(int i=0;i<dag[x].size();i++) 
	if(color[dag[x][i]]==0)dagsort(dag[x][i]); 
	
	tme++; 
	en[x]=tme;
	
}
int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){
		int n,x,y,m;  
		for(int i=0;i<=20000;i++)v[i].clear(),rev[i].clear(),color[i]=1,en[i]=0, 
		dag[i].clear();
		cin>>n>>m;
		tme=0;
			
		while(m--){
cin>>x>>y,v[x].push_back(y),rev[y].push_back(x),color[x]=1, 
			color[y]=1;
		} 
	   for(int i=1;i<=n;i++)
	   if(color[i]==1)topsort(i);
	    
	   int chk=0; 
	   
	   vector<pair<int,int> >temp; 
	   for(int i=0;i<=n;i++) 
	   if(en[i])temp.push_back({en[i],i}),en[i]=0; 
	   
	   sort(temp.begin(),temp.end(),greater<pair<int,int> >() ); 
	   
	   tme=0;
	   for(int i=0;i<temp.size();i++) 
	   if(color[temp[i].second]==2)tme++,scc(temp[i].second); 
	    
	   int couni,couno;
	   bool inde[20005]={0},outd[20005]={0};
	   
	   for(int i=0;i<=20000;i++) { 
	   	color[i]=0;
	     for(int j=0;j<v[i].size();j++) 
	        if(en[i]!=en[v[i][j]])
	         dag[en[i]].push_back(en[v[i][j]]),
	         inde[en[v[i][j]]]=1,
	         outd[en[i]]=1; 
	   }
	  couni = couno = 0;
	  for(int i=1;i<=tme;i++){
	  if(!inde[i])couni++;
	  if(!outd[i])couno++;
	}
	couni = max(couni,couno); 
    if(tme==1)couni=0;
	  printf("Case %d: %d\n",++cs,couni); 
	}
	return 0; 
}
