//We will take a array which is already in the form of a heap
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>&arr,int size,int i){
    int index = i;
    while(index<=size){
        int left = 2*index;
        int right = 2*index+1;
        int largest = index;

        if(left<=size && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<=size && arr[right]>arr[largest]){
            largest = right;
        }
        if(largest == index){
            return;
        }else{
            swap(arr[index],arr[largest]);
            index = largest;
        }
    }
}
void heap_sort(vector<int>&arr){
    int size = arr.size()-1;
    while(size!=1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}
void print(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>arr = {-1,100,50,60,20,30};
    int size = arr.size();
    heap_sort(arr);
    print(arr);

}
