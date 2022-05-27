/*
Author : Johaer Plabon
Dept : CSE, Sylhet Engineering College
Topic : Sparse Table (3D).
Complexity : 0(n^2*log(n) + q). --> {n = row = column ; q = Queries.}
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() { 
//	cout<<(1<<2-1)<<endl;
	int t,cs=0;
	cin>>t; 
	while(t--){
		printf("Case %d:\n",++cs);
		int n,m;
		cin>>n>>m; 
		int a[n+15][n+15],st[n+15][n+15][15]; 
		
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++) 
				cin>>a[i][j]; 
		
		for(int i=0;i<=n+10;i++) 
			for(int j=0;j<=n+10;j++) 
				for(int k=0;k<=12;k++)
					st[i][j][k]=0; 
					
		for(int i=0;(1<<i)<=n;i++){
			for(int j=0;j+(1<<i)-1<n;j++){
				for(int k=0;k+(1<<i)-1<n;k++){
					if(i==0)st[j][k][i]=a[j][k];
					else{ 
						st[j][k][i] = max(st[j][k][i-1],st[j][k+(1<<i-1)][i-1]); 
						st[j][k][i] = max({st[j][k][i],st[j+(1<<i-1)][k][i-1],st[j+(1<<i-1)][k+(1<<i-1)][i-1]}); 
					
					}
				}
			}
		} 
		
		while(m--){
			int x,y,z; 
			scanf("%d%d%d",&x,&y,&z); 
			int sz = log2(z); 
			x--,y--;
			int res = max(st[x][y][sz],st[x][y+z-(1<<sz)][sz]); 
			res = max({res,st[x+z-(1<<sz)][y][sz],st[x+z-(1<<sz)][y+z-(1<<sz)][sz]}); 
			
			printf("%d\n",res);
		}
	}
	return 0;
}
