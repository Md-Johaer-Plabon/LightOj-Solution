#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    ll tc, n, x1, y1, x2, y2;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>x1>>y1>>x2>>y2;
        n = __gcd(abs(x1-x2), abs(y1-y2)) + 1;
        cout<<"Case "<<cs<<": "<<n<<endl;
    }
 
}
