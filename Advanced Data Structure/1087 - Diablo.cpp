

/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
  
  */


#include <bits/stdc++.h>
using namespace std;
#define ll int
 
int main() {
vector<ll>seg;
 
    ll t,cs=0;
   scanf("%d",&t);
    while(t--){
       
     seg.clear();
    ll n,m,x;
    scanf("%d%d",&n,&m);
     for(int i=0;i<n;i++){
        scanf("%d",&x);
    seg.push_back(x);
    }
 
    printf("Case %d:\n",++cs);
    for(int i=0;i<m;i++)    {
         getchar();
        char s;
        scanf("%c%d",&s,&x);
        if(s=='a')
        seg.push_back(x);
        else if(seg.size()>=x){
            printf("%d\n",seg[x-1]);
            seg.erase(seg.begin()+x-1);
}
        else printf("none\n");
    }
    }
    return 0;
}
