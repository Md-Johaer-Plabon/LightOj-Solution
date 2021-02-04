/* 
Name : Johaer Plabon 
Dept: CSE, Sylhet Engineering College 
*/ 


#include<bits/stdc++.h> 
using namespace std; 

string multiply(string num1, string num2) { 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
    vector<int> result(len1 + len2, 0); 
    int i_n1 = 0;  
    int i_n2 = 0;  
    for (int i=len1-1; i>=0; i--)  { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;  
        for (int j=len2-1; j>=0; j--) { 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 

            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 

    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 

    if (i == -1) 
    return "0"; 

    string s = ""; 
      
    while (i >= 0) 
        s +=to_string(result[i--]); 
  
    return s; 
} 

int main (){ 
    ios::sync_with_stdio(0); 
    
	int t,cs=0; 
	cin>>t;
	while(t--){
		int n,arr[1005];  
		map<int,int>mp; 
		vector<int>v;
		cin>>n; 
		for(int i=0;i<n;i++){cin>>arr[i]; 
		  for(int j=2;j*j<=arr[i];j++) { 
		  	int coun=0; 
		  	if(arr[i]%j==0&&!mp[j])v.push_back(j);
		  while(arr[i]%j==0)arr[i]/=j,coun++; 
		    mp[j]=max(mp[j],coun);
		  } 
		  if(!mp[arr[i]]&&n>1)v.push_back(arr[i]),mp[arr[i]]=1;
		} 
	string num="1"; 
        int temp;
		for(int i=0;i<v.size();i++){
			 temp = pow(v[i],mp[v[i]]); 
			 num = multiply(num,to_string(temp));
		} 
		cout<<"Case "<<++cs<<": "<<num<<endl;
	}
}
  
