/* 
Name : Johaer Plabon 
Dept : CSE, Sylhet Engineering College 
Topic : Strongly Connected Component , Longest path in directed tree.
Hint : Steps -> 
        1. Using SCC make the graph DAG which is also a graph with no cycle. 
        2. Findout the longest path from the DAG. 
        3. Steps for finding longest path -> 
               1. Count indegree of all node.(Consider each component as a node). 
               2. Assign the total number of nodes of each component as value of new node.(If 10 nodes make cycle and if this components name is 1,then 
                  initially dis[1]=10) 
               3. Push all zero indegree nodes in queue. 
               4. Run the queue for nodes to zero outdegree.And also store the zero indegree node as parent which can make maximum 
                  value (The node of minimum value as parent). 
               5. Maximum value for zero outdegree is the desired answer. 
               
        ---> The task is not actually the longest path or farthest node,we have to find such a path where sum of all nodes are maximum(includes components node). 
             Always maximum distanced path is not answer because of the variation in number of nodes in each component.Each component may be different numbers of 
             nodes.
  */ 
  
  
  
  
#include <bits/stdc++.h>
using namespace std;
vector<int>color(50005,0);
vector<int>v[50005],rev[50005],dag[50005];
int tme,en[50005],minn[50005],parent[50005];
map<int,int>mp;
queue<int>q;
void topsort(int x){
    color[x]=2;
    tme++;
    for(int i=0; i<v[x].size(); i++)
        if(color[v[x][i]]==1)
            topsort(v[x][i]);

    tme++;
    en[x]=tme;
}

void scc(int x){
    color[x]=3;
    en[x]=tme;

    for(int i=0; i<rev[x].size(); i++)
        if(color[rev[x][i]]==2)scc(rev[x][i]);


}

void dagsort(int x){
    color[x]=1;
    tme++;

    for(int i=0; i<dag[x].size(); i++)
        if(color[dag[x][i]]==0)dagsort(dag[x][i]);

    tme++;
    en[x]=tme;

}

void longest_path(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<dag[x].size(); i++){
            if(en[dag[x][i]]<en[x]+mp[dag[x][i]])
                en[dag[x][i]]=en[x]+mp[dag[x][i]],
                              q.push(dag[x][i]),parent[dag[x][i]]=parent[x];
            if(en[dag[x][i]]=en[x]+mp[dag[x][i]])
                parent[dag[x][i]]=min(parent[dag[x][i]],parent[x]);
        }
    }
}

int main(){
    int t,cs=0;
    cin>>t;
    while(t--){
        int n,x,y;
        mp.clear();
        while(!q.empty())q.pop();

        int indegree[50005];
        for(int i=0; i<=50000; i++)v[i].clear(),rev[i].clear(),color[i]=0,en[i]=0,
                    dag[i].clear(),minn[i]=INT_MAX,indegree[i]=0;

        cin>>n;
        tme=0;
        for(int i=0; i<n; i++)
            cin>>x>>y,v[x].push_back(y),rev[y].push_back(x),color[x]=1,
                    color[y]=1;

        for(int i=1; i<=n; i++)
            if(color[i]==1)
                topsort(i);

        vector<pair<int,int> >temp;
        for(int i=0; i<=n; i++)
            if(en[i]){
                temp.push_back({en[i],i});
                en[i]=0;
            }
        sort(temp.begin(),temp.end(),greater<pair<int,int> >() );

        tme=0;

        for(int i=0; i<temp.size(); i++)
            if(color[temp[i].second]==2)tme++,scc(temp[i].second);

        for(int i=1; i<=n; i++)
            mp[en[i]]++,minn[en[i]]=min(minn[en[i]],i);

        int coun = 0;

        for(int i=0; i<=n; i++){
            color[i]=0;
            for(int j=0; j<v[i].size(); j++)
                if(en[i]!=en[v[i][j]])
                    dag[en[i]].push_back(en[v[i][j]]),indegree[en[v[i][j]]]++;
        }

        memset(en,0,sizeof en);

        for(int i=1; i<=tme; i++){
            if(!indegree[i])q.push(i),parent[i]=minn[i];
            en[i]=mp[i];
        }
        longest_path();

        int maxx=0,ind;

        for(int i=1; i<=tme; i++)
            if(maxx<en[i])maxx=en[i],ind=parent[i];

        printf("Case %d: %d\n",++cs,ind);
    }
    return 0;
}

             
  
