#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int start,int end){
    int total_size = end-start+1;
    int gap = total_size/2 + total_size%2;
    while(gap>0){
        int i=start;int j=gap+start;
        while(j<=end){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            i++;j++;
        }
        gap = (gap<=1)?(0):(gap = gap/2 + gap%2);
    }
}
void merge_sort(vector<int>&arr,int start,int end){
    if(start >= end){
        return;
    }
    int mid = start + (end-start)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,end);
}
int main(){
    vector<int>arr = {8,9,3,4,0,1,99};
    int start = 0;
    int end = arr.size()-1;
    merge_sort(arr,start,end);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}