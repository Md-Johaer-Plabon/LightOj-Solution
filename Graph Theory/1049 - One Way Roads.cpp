#include<bits/stdc++.h>
using namespace std;
int main (){
int t,cs=0;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int a[200],b[200];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int x,y,w,coun=0,coun1=0;
    for(int i=0;i<n;i++){
            cin>>x>>y>>w;
        if(!a[x]&&!b[y])
        coun+=w,a[x]=1,b[y]=1;
        else
        coun1+=w,a[y]=1,b[x]=1;
    }
    cout<<"Case "<<++cs<<": "<<min(coun,coun1)<<endl;
}
return 0;
}
