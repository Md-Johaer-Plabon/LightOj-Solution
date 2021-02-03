/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
*/ 



#include<bits/stdc++.h> 
using namespace std; 
int main (){ 
	int arr[10][7]{ 
     {0,0,0,0,0,0,0}, 
     {1,1,1,1,1,1,1}, 
     {1,2,4,8,7,5,0},
     {9,9,9,9,9,9,9}, 
     {1,4,7,0,0,0,0}, 
     {1,5,7,8,4,2,0}, 
     {9,9,9,9,9,9,9}, 
     {1,7,4,0,0,0,0}, 
     {1,8,0,0,0,0,0}, 
     {9,9,9,9,9,9,9},
};
int sz[]={0,1,6,1,3,6,1,3,2,1}; 
   int t,cs=0;
    cin>>t;
    while(t--){ 
    	printf("Case %d: ",++cs);
    string a,b; 
    cin>>a>>b; 
   int temp =0,res; 
    for(int i=0;i<a.length();i++) 
        temp+=(a[i]-'0'); 
    
    while(temp>9){ 
      res=temp; 
      temp=0; 
    while(res) 
     temp+=res%10,res/=10;
    }  
    if(temp==0){cout<<0<<endl;continue;}
    if(temp==1||b[0]=='0'){cout<<1<<endl;continue;} 
    int chk=0;
    	        res=0;
    	for (int i=0;i<b.length();i++) 
       res = (res*10 + (b[i] -'0'))%sz[temp]; 
       if(b.length()==1&&b[0]=='1')cout<<temp<<endl;
       else cout<<arr[temp][res]<<endl;
    }
	return 0;
}
