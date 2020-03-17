#include<bits/stdc++.h>
#define ll long long
using namespace std;
int phi[1000010];
int mp[1000010];
void sive_OF_Phi()
{
    phi[1]=0;
    for(int i=2; i<=1000003; i++)
        phi[i]=i;
    for(int i=2; i<=1000003; i++)
    {
        if(phi[i]==i)
            for(int j=i; j<=1000003; j+=i)
                phi[j]=phi[j]/i*(i-1);
    }
    mp[0]=1;
    for(int i=2; i<=1000003; i++)
    {
        if(!mp[phi[i]])
            mp[phi[i]]=i;
        mp[phi[i]]=min(mp[phi[i]],i);
    }
}
 
int main ()
{
    sive_OF_Phi();
    for(int x = INT_MAX, i=1000002; i>0; i--)
    {
       if(mp[i] && mp[i]<x) x = mp[i];
       else mp[i] = x;
         
    }
    long long tc, n, res;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>n;
        res = 0;
        for(int i=0, x; i<n; i++){
            cin>>x;
            res += mp[x];
        }
        cout<<"Case "<<cs<<": "<<res<<" Xukha"<<endl;
    }
    return 0;
}
