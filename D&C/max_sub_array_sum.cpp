#include <iostream>
#include <vector>
using namespace std;
int max_sum(vector<int>&arr,int start,int end){
    //base case
    if(start==end)
    return arr[start];

    int mid = (start + end)/2;

    int left_sum = INT_MIN;
    int right_sum = INT_MIN;

    //finding left_subarray sum
    left_sum = max_sum(arr,start,mid);

    //finding_right_subarray sum
    right_sum = max_sum(arr,mid+1,end);

    //finding cross boarder sum
    int max_left_boarder_sum = INT_MIN;
    int max_right_boarder_sum = INT_MIN;
    int left_boarder = 0;
    int right_boarder = 0;
    for(int i=mid;i>=start;i--){
        left_boarder += arr[i];
        if(left_boarder>=max_left_boarder_sum){
            max_left_boarder_sum = left_boarder;
        }
    }
     for(int i=mid+1;i<=end;i++){
        right_boarder += arr[i];
        if(right_boarder>=max_right_boarder_sum){
            max_right_boarder_sum = right_boarder;
        }
    }
    int cross_boarder= max_left_boarder_sum  + max_right_boarder_sum ;

    //return the max of three sum
    return max(max(left_sum,right_sum),cross_boarder);
}
int main(){
    vector<int>arr = {-2,-3,4,-1,-2,1,5,-3};
    cout<<"max subarray sum is "<<max_sum(arr,0,arr.size()-1);
}
//this algo works for subswquence but here we need to solve for subarray
/*solution when we use include exclude and use backtracking for sum variable
 #include<iostream>
#include<vector>
#include <climits> 
using namespace std;
void max_sum(vector<int>&arr,int &sum,int &maxi,int index){
    //base case
    if(index >=arr.size()){
        maxi = max(maxi,sum);
        return;
    }
    //include 
    sum += arr[index];
    max_sum(arr,sum,maxi,index+1);
    //backtracking call
    sum -= arr[index];
    max_sum(arr,sum,maxi,index+1);
}
int main(){
    vector<int>arr = {5,4,-1,7,8};
    int sum = 0;
    int maxi = INT_MIN;
    int index = 0;
    max_sum(arr,sum,maxi,index);
    cout<<"Maximum sum is "<<maxi;
}
*/