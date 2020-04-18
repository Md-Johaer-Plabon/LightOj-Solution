
/* Name : Johaer Plabon
   11th batch(2017-18),
   Dept of CSE,SEC.
 
 */




#include<bits/stdc++.h>
using namespace std;
#define sz 100009
string a;
long long pr[4*sz+5];
void query(int it,int l,int r,int s){
 
if(pr[it]){
    if(l!=r){
        pr[it*2]+=pr[it];
        pr[2*it+1]+=pr[it];
        pr[it]=0;
    }
   
}
 
if(s>r||s<l)return ;
 
if(l==r){
//  cout<<pr[it]<<endl;
        if(pr[it]%2==1){
//cout<<" yes1"<<endl;
        if(a[l]=='0')
        a[l]='1';
        else a[l]='0';
        }
        pr[it]=0;
    return;
}
 
query(2*it,l,(l+r)/2,s);
query(2*it+1,(l+r)/2+1,r,s);
}
 
 
void propagate(int i,int l,int r,int s,int e){
 
    if(e<l||s>r)return;
   
    if(s<=l&&r<=e){
        pr[i]++;
        return;
    }
    propagate(2*i,l,(l+r)/2,s,e);
    propagate(2*i+1,(l+r)/2+1,r,s,e);
    return;
}
int main (){
    int t,cs=0,n;
    scanf("%d",&t);
   
    while(t--){
        memset(pr,0,sizeof pr);
        cin>>a;
    scanf("%d",&n);
    int x,y;
   
    printf("Case %d:\n",++cs);
    while(n--){
    char key[2];
   scanf("%s",&key);
    if(key[0]=='I'){
        scanf("%d%d",&x,&y);
    propagate(1,0,a.size()-1,x-1,y-1);
    }
   else if(key[0]=='Q'){
        scanf("%d",&x);
    query(1,0,a.size()-1,x-1);
    printf("%c\n",a[x-1]);
    }
  }
}
return 0;
}
