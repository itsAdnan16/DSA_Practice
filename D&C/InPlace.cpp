#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int start,int end,int mid){
    int i= start;
    int size = end - start + 1;
    int gap = (size)/2 + size%2;
    int j = start + gap;
    while(gap>0){
        int i= start;
         int j = start + gap;

        while(j<=end){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            i++;
            j++;
        }
      
        if(gap==1){
            gap=0;
        }
        gap = gap/2 + gap%2;
    }
}
void MergeSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    //left array sort
    MergeSort(arr,start,mid);
    //right array sort
    MergeSort(arr,mid+1,end);
    //merge two sorted array
    merge(arr,start,end,mid);


}
int main(){
    vector<int>arr = {5,4,6,3,0,10};
    int start = 0;
    int end = arr.size()-1;
    MergeSort(arr,start,end);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}