#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>&arr,int i){
    int index = i;
    while(index >1){
        int parent = i/2;
        int left = 2*i;
        int right = 2*i+1;
        int largest = index;
        if(left <arr.size() && arr[largest]<arr[left]){
            largest=left;
        }
        // arr[left]<arr[right]
        if(right<arr.size() && arr[largest]<arr[right] ){
            largest = right;
        }
        if(index == largest){
            return;
        }
        else{
            swap(arr[index],arr[largest]);
            index = largest;
        }
    }
}
void build(vector<int>&arr){
    int n =arr.size();
    for(int i=n/2;i>=1;i--){
        heapify(arr,i);
    }
}
void print(vector<int>arr){
    for(int i=1;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}