

/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
 */
 
 #include<bits/stdc++.h>
using namespace std;
#define sz 100009
#define ll long long
ll a[sz],maxseg[4*sz+5],summ,minseg[4*sz+5];
ll machine(ll it,ll l,ll r,ll s,ll e,ll num){
    if(e<l||s>r){
      if(num==1)return INT_MAX;
      if(num==2)return 0;
    }
    if(l>=s&&r<=e){
      if(num==1) return minseg[it] ;///4 5 1 6 7 5 1
      if(num==2) return maxseg[it];
    }
  ll x= machine(2*it,l,(l+r)/2,s,e,num);
  ll y= machine(2*it+1,(l+r)/2+1,r,s,e,num);
  if(num==1) return min(x,y);
  if(num==2) return max(x,y);
}
 
void build(ll it,ll l,ll r){
    if(l==r){
        maxseg[it] = minseg[it] = a[l];
        return ;
    }
  build(2*it,l,(l+r)/2);
  build(2*it+1,(l+r)/2+1,r);
  maxseg[it]=max(maxseg[2*it],maxseg[2*it+1]);
  minseg[it]=min(minseg[2*it],minseg[2*it+1]);
  return;
}
int main (){
 
int t,cs=0;
scanf("%d",&t);
while(t--){
       // ll summ=0;
        ll n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
   build(1,1,n);
   ll i,ans=0;
   for(i=1;i+m-1<n;i++){
    ll minn = machine(1,1,n,i,i+m-1,1);
    ll maxx = machine(1,1,n,i,i+m-1,2);
    ans=max(ans,maxx-minn);
   }
   for(;i<n;i++){
   ll minn = machine(1,1,n,i,n,1);
   ll maxx = machine(1,1,n,i,n,2);
   ans=max(ans,maxx-minn);
   }
    printf("Case %d: %lld\n",++cs,ans);
}
}
 
