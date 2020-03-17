#include<bits/stdc++.h>
using namespace std;
map<int, vector<int> >mp;
map<int, int>color;
int arr[1005];
int coun, sum, avg;
set<int>s;
int bfs(int n)
{
    queue<int>q;
    q.push(n);
    coun=1, sum = arr[n];
    while(!q.empty()){
        int x = q.front();
        q.pop();
        color[x] = 1;
        for(int i=0; i<mp[x].size(); i++){
            if(color[mp[x][i]]==0){
                coun++;
                color[mp[x][i]] = 1;
                sum += arr[mp[x][i]];
                q.push(mp[x][i]);
            }
        }
    }
    if(sum%coun==0) s.insert(sum/coun);
    else return -1;
 
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m, tc;
    scanf("%d", &tc);
    for(int cs = 1; cs<=tc; cs++){
        coun=0, avg=0, sum=0;
        mp.clear(), s.clear(), color.clear();
        memset(arr, 0, sizeof arr);
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);
        for(int i=0, x, y; i<m; i++){
            scanf("%d%d", &x, &y);
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        int flag=0;
        for(int i=1; i<=n; i++){
            if(color[i]==0) flag = bfs(i);
            if(flag==-1) break;
        }
        if(flag==-1 || s.size()>1) printf("Case %d: No\n", cs);
        else printf("Case %d: Yes\n", cs);
    }
}
