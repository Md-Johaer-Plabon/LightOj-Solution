
/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.

*/


#include<bits/stdc++.h>
#define sz 100000
#define ll long long
using namespace std;
ll tr[4*sz+5],a[sz+5],pr[4*sz+5];
 
ll query(ll it,ll l,ll r,ll s,ll e){
if(s>r||e<l)return 0;
 
if(pr[it]){
    tr[it]+=(r-l+1)*pr[it];
    if(l!=r){
        pr[it*2]+=pr[it];
        pr[2*it+1]+=pr[it];
    }
    pr[it]=0;
}
 
 
if(l>=s&&e>=r)
    return tr[it];
 
ll x= query(2*it,l,(l+r)/2,s,e);
ll y= query(2*it+1,(l+r)/2+1,r,s,e);
 
return x+y;
}
 
 
void prop(ll it,ll l,ll r,ll s,ll e,ll x){
if(pr[it]){
    tr[it]+=(r-l+1)*pr[it];
    if(l!=r){
        pr[it*2]+=pr[it];
        pr[it*2+1]+=pr[it];
    }
    pr[it]=0;
}
if(e<l||s>r)return;
 
if(l>=s&&e>=r){
        tr[it]+=(r-l+1)*x;
    if(l!=r){
        pr[2*it]+=x;
        pr[2*it+1]+=x;
    }
    return;
}
 
    prop(2*it,l,(l+r)/2,s,e,x);
    prop(2*it+1,(l+r)/2+1,r,s,e,x);
 
    tr[it]=tr[2*it]+tr[2*it+1];
}
 
void build(ll it,ll l,ll r){
  if(l==r){
    tr[it]=a[l];
    return ;
  }
build(2*it,l,(l+r)/2);
build(2*it+1,(l+r)/2+1,r);
tr[it]=tr[2*it]+tr[2*it+1];
 
return;
}
 
int main (){
    ll t,cs=0;
    cin>>t;
    while(t--){
            memset(pr,0,sizeof pr);
            memset(a,0,sizeof a);
       ll key,x,y,v,n,q;
       scanf("%lld%lld",&n,&q);
       build(1,0,n-1);
       printf("Case %lld:\n",++cs);
       while(q--){
        scanf("%lld",&key);
        if(key==0){
            scanf("%lld%lld%lld",&x,&y,&v);
            prop(1,0,n-1,x,y,v);
        }
        if(key==1){
            scanf("%lld%lld",&x,&y);
            ll ans = query(1,0,n-1,x,y);
            printf("%lld\n",ans);
       }
    }
}
return 0;
}
