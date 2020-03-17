#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
 
using namespace std;
bool save [10000000];
vector <int> result;
 
void sievePrime (void) {
    memset(save, true , sizeof(save));
    save[0]= false;
    save[1]= false;
   
    int temp=(int)((sqrt(10000000))+1.0);
   
    for(int i=4;i<10000000; i+=2) save[i]= false;
    for(int i=3;i<temp; i+=2) {
        if(save[i]==true) {
            for(int j=i*i; j<10000000; j+=i) save[j]=false;
        }
    }
   
    for(int i=2; i<10000000; i++) {
        if(save[i]==true) result.push_back(i);
    }
}
 
int main (void) {
    sievePrime();
   
    int test;
    scanf("%d", &test);
   
    for(int a=1; a<=test; a++) {
        int temp;
        scanf("%d", &temp);
       
        int flag=result.size();
        int counter=0;
        int atto = temp/2;
        for(int i=0; i<flag; i++) {
            if(result[i]>atto) break;
            if(save[temp-result[i]]==true) counter++;
        }
       
        printf("Case %d: %d\n", a, counter);
   
    }
    return 0;
}
