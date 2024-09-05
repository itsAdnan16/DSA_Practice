#include<iostream>
using namespace std;
int index(int arr[],int &low,int &high,int &target){
    //base case
    if(low>high){
        return -1;
    }
    //now we will solve the one case
    int mid = low + (high - low)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(target>arr[mid]){
        low = mid+1;
        return index(arr,low,high,target);
    }
    else{
        high = mid-1;
        return index(arr,low,high,target);
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int i = 0;
    int target = 10;
    int low = 0;
    int high = 4;
    int found = index(arr,low,high,target);
    cout<<"Found at index "<<found;
}