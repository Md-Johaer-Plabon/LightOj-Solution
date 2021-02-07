/* 
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College 
Topic : Strongly Connected Component(SCC),Topological Sort. 
Hint : Steps -> 
         1. Using scc make the graph , Directed Acyclic.(Must start the traversing from node 0,as its the snakes initial position).
         2. Then consider every component as a node. 
         3. Sort the DAG topologically and choose the node which takes highest finishing time. 
         4. Traversing From choosen node if its found an one way tree ,then its possible(print YES) otherwise NO. 
         
         Or, 
         *** skip step no.3 and 4. And after step 2,in the created DAG if there are any node have more than 1 outdegree 
             then its not possible(print NO) otherwise YES. 
	     
         N.B: The single path is obviously not possible ,if there are more than one graph.
*/ 


#include <bits/stdc++.h>
using namespace std; 
vector<int>color(10005,0); 
vector<int>v[10005],rev[10005],dag[10005]; 
int tme,en[10005];
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
		int n,x,y;  
		for(int i=0;i<=10000;i++)v[i].clear(),rev[i].clear(),color[i]=0,en[i]=0, 
		dag[i].clear();
		cin>>n; 
		tme=0;
		while(n--){
			int k; 
			cin>>k; 
			while(k--)cin>>x>>y,v[x].push_back(y),rev[y].push_back(x),color[x]=1, 
			color[y]=1;
		} 
	   topsort(0);
	    
	   int chk=0; 
	   for(int i=0;i<=10000;i++) 
	   if(color[i]==1){chk=1;break;}  
	   if(chk){printf("Case %d: NO\n",++cs);continue;}
	   
	   vector<pair<int,int> >temp; 
	   for(int i=0;i<=10000;i++) 
	   if(en[i])temp.push_back({en[i],i}),en[i]=0; 
	   
	   sort(temp.begin(),temp.end(),greater<pair<int,int> >() ); 
	   
	   tme=0;
	   for(int i=0;i<temp.size();i++) 
	   if(color[temp[i].second]==2)tme++,scc(temp[i].second); 
	    
	   int coun = 0;
	   for(int i=0;i<=10000;i++) { 
	   	color[i]=0;
	     for(int j=0;j<v[i].size();j++) 
	        if(en[i]!=en[v[i][j]])
	         dag[en[i]].push_back(en[v[i][j]]),coun++; 
	   }
	   int flag = tme; 
	   tme = 0; 
	   memset(en,0,sizeof en); 
	   
	   for(int i=1;i<=flag;i++) 
	   if(color[i]==0)dagsort(i);
	     
	   int maxx=0,ind;
	   
	   for(int i=1;i<=flag;i++) 
	   if(maxx<en[i])maxx=en[i],ind=i; 

	   while(!dag[ind].empty()){
	   	 ind = dag[ind][0]; 
	   	 coun--;
	   }
	  if(coun==0)printf("Case %d: YES\n",++cs); 
	  else printf("Case %d: NO\n",++cs);
	}
	return 0;
}
