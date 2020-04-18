
/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
   
 */




#include<bits/stdc++.h>
using namespace std;
#define sz 100009
int tree[4*sz+5];
int l,r,summ;
int a[sz+5];
 
int query(int at,int left,int right)
{
    if(r<left||right<l)return INT_MAX;
if(l<=left&&right<=r)return tree[at];
     if(left==right)return INT_MAX;
   int mid =(left+right)/2;
  int x=  query(2*at,left,mid);
   int y= query(2*at+1,mid+1,right);
return min(x,y);
}
 
int build(int at, int left ,int right){
    if(left==right){
        tree[at]=a[left];
        return tree[at];
    }
    int mid=(left+right)/2;
    int x = build(2*at,left,mid);
    int y = build(2*at+1,mid+1,right);
    tree[at] = min(x,y);
return tree[at];
}
 
 
int main (){
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
int t,cs=0;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    for(int i=0,x;i<n;i++)
    cin>>a[i];
 
    build(1,0,n-1);
 
    cout<<"Case "<<++cs<<":"<<endl;
    while(m--){
    cin>>l>>r;
    l--,r--;
   int res = query(1,0,n-1);
    cout<<res<<endl;
}
 
}
return 0;
}
