#include<iostream>
#include<vector>
using namespace std;
void max_sum(int arr[],int &n,int index,int sum ,int &ans){
    //This is the base case where we will update the ans and return
    if(index >=n){
        ans = max(ans,sum);
        return;
    }
    //first we will make the exclude call
    max_sum(arr,n,index+1,sum,ans);
    //now first add the element then make the exclude call
    sum += arr[index];
    //include call then we will update the index as well
    max_sum(arr,n,index+2,sum,ans);
}
int main(){
    int sum = 0;
    int ans = INT_MIN;
    int arr[6] ={2,1,4,9,5,20};
    int index = 0;
    int n = 6;
    max_sum(arr,n,index,sum,ans);
    cout<<"The max non adjacent sum is "<<ans;

}
