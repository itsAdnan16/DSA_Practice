#include<iostream>
using namespace std;
int ways(int n){
    //you did this part wrong just like the fibonacci number
    /*if(n==0 || n==1){
        return n;
    }*/
   if(n==0 || n==1){
    return 1;
   }
    int ans = ways(n-1) + ways(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the stair where you want to go "<<endl;
    cin>>n;
    cout<<"The number of ways to reach the nth stair is :"<<ways(n);
}