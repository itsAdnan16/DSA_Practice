#include<iostream>
#include<vector>
using namespace std;
int min_square_helper(vector<int>&arr,int number){
    //writing the base cases
    if(number==0){
        return 0;
    }
    if(number<0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0;i<arr.size();i++){
        int ans = min_square_helper(arr,number-arr[i]);
        if(ans!=INT_MAX){
            mini = min(mini,ans);
        }
    }
    if(mini == INT_MAX){
        return 0;
    }
    return mini + 1;

}
int min_square(int number){
    vector<int>arr;
    int i = 1;
    while(i*i<=number){
        arr.push_back(i*i);
        i++;
    }
    int ans = min_square_helper(arr,number);
    return ans;
}
int main(){
    int number = 12;
    cout<<"The mini number of perfect square needed are :"<<min_square(number);
}
