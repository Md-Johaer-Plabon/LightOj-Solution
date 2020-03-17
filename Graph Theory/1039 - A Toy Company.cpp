#include<bits/stdc++.h>
using namespace std;
string start, dest;
map<string, int>color, dist;
string all = "zabcdefghijklmnopqrstuvwxyza";
int bfs(string n)
{
    if(color[dest] || color[start]) return -1;
    queue<string>q;
    q.push(n);
    while(!q.empty()){
        string temp, k = q.front();
        if(k==dest) return dist[dest];
        q.pop();
        temp = k;temp[0]=all[temp[0]-'a'];
        if(color[temp]==0) color[temp]=1, dist[temp]=dist[k]+1, q.push(temp);
        temp = k;temp[0]=all[temp[0]-'a'+2];
        if(color[temp]==0) color[temp]=1, dist[temp]=dist[k]+1, q.push(temp);
        temp = k;temp[1]=all[temp[1]-'a'];
        if(color[temp]==0) color[temp]=1, dist[temp]=dist[k]+1, q.push(temp);
        temp = k;temp[1]=all[temp[1]-'a'+2];
        if(color[temp]==0) color[temp]=1, dist[temp]=dist[k]+1, q.push(temp);
        temp = k;temp[2]=all[temp[2]-'a'];
        if(color[temp]==0) color[temp]=1, dist[temp]=dist[k]+1, q.push(temp);
        temp = k;temp[2]=all[temp[2]-'a'+2];
        if(color[temp]==0) color[temp]=1, dist[temp]=dist[k]+1, q.push(temp);
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, tc;
    string st, tu, uv, temp;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        color.clear(), dist.clear();
        cin>>start>>dest;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>st>>tu>>uv;
 
            int s=st.length(), t=tu.length(), u=uv.length();
            for(int j=0; j<s; j++){
                for(int k=0; k<t; k++){
                    for(int l=0; l<u; l++){
                        temp +=st[j];
                        temp +=tu[k];
                        temp +=uv[l];
                        color[temp] = 1;
                        temp = "";
                    }
                }
            }
        }
        cout<<"Case "<<cs<<": "<<bfs(start)<<endl;
    }
}
