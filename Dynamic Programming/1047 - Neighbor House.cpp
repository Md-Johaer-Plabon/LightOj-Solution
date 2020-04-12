

/*
   Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
   Problem Name: Neighbour's House.
   Topic : Rock Climbing (DP).
   
 */


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main ()
{

    int t,cs=0;
    cin>>t;
    while(t--)
    {
        ll n,a[109],b[109],c[109];

        cin>>n;
        for(int i=0; i<n; i++)cin>>a[i]>>b[i]>>c[i];
        
        ///Starting Climbing:
        for(int i=1; i<n; i++)
            a[i]=min(b[i-1]+a[i],c[i-1]+a[i]),
                 b[i]=min(c[i-1]+b[i],a[i-1]+b[i]),
                      c[i]=min(b[i-1]+c[i],a[i-1]+c[i]);
                      
        ll temp=min(min(a[n-1],b[n-1]),c[n-1]);

        cout<<"Case "<<++cs<<": "<<temp<<endl;
    }

}
