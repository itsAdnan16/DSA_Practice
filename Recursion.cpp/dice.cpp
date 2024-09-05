#include<iostream>
using namespace std;

int possible_ways(int n,int k,int t){
    //now we have to configure the base cases
    if(n==0 && t==0) return 1;
    if(n==0 && t!=0) return 0;
    if(n!=0 && t==0) return 0;
    
    int ans = 0;
    //now we will solve solve the one case that is to throw the first dice for all the possible outcomes 
    for(int i=1;i<=k;i++){
        ans += possible_ways(n-1,k,t-i);
    }
    return ans;
}
int main(){
    int n = 3;
    int k = 2;
    int t = 4;
    int outcome = possible_ways(n,k,t);
    cout<<"Total number of the possible ways: "<<outcome;
}