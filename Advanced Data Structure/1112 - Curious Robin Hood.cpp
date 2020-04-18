

/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100009
ll seg[4*sz+5],a[sz];
 
void give(ll at,ll l,ll r,ll pos,ll nv){
 
 if(pos<l || pos>r)return ;
   if(pos<=l && pos>=r){
        seg[at]=nv;
        return ;
    }
    give(2*at,l,(l+r)/2,pos,nv);
     give(2*at+1,(l+r)/2+1,r,pos,nv);
    seg[at]=seg[2*at]+seg[2*at+1];
}
 
ll query(ll at,ll l,ll r,ll s,ll e){
    if(l>e||s>r)
        return 0;
    if(l>=s&&r<=e)
        return seg[at];
    ll x = query(2*at,l,(l+r)/2,s,e);
    ll y = query(2*at+1,(l+r)/2+1,r,s,e);
    return x+y;
 
}
 
 
 
ll build(ll at,ll l,ll r){
    if(l==r){
        seg[at]=a[l];
        return a[l];
    }
    ll x = build(2*at,l,(l+r)/2);
    ll y = build(2*at+1,(l+r)/2+1,r);
    seg[at]=x+y;
    return seg[at];
}
 
int main (){
    int t,cs=0;
    scanf("%d",&t);
    while(t--){
    printf("Case %d:\n",++cs);
        ll n,m;
        scanf("%lld%lld",&n,&m);
       
        for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
build(1,1,n);
        for(int i=0;i<m;i++){
            ll x,y,z;
            scanf("%lld",&x);
            if(x==1){
            scanf("%lld",&y);
   printf("%lld\n",a[y+1]);
     
            give(1,1,n,y+1,0);
a[y+1]=0;
           
            }
           
            else if(x==2){
                scanf("%lld%lld",&y,&z);
            give(1,1,n,y+1,a[y+1]+z);
a[y+1]+=z;
            }
            else{
                scanf("%lld%lld",&y,&z);
            ll res = query(1,1,n,y+1,z+1);
            printf("%lld\n",res);
            }
}
}
}
