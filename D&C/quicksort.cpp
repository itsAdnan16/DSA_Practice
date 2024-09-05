#include <iostream>
#include <vector>
using namespace std;
int Partition(vector<int>&arr,int start,int end){
    int pivot = start;
    int count = 0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=arr[pivot]){
             count++;
            
        }
    }
    int right_position = count + start;
    swap(arr[right_position],arr[pivot]);
    int i =start;
    int j= end;
    while(i<right_position && j>right_position){
        while(arr[i]<=arr[right_position]){
            i++;
        }
        while(arr[j]>arr[right_position]){
            j--;
        }
        if(i<j){
            //swap(arr[i++],arr[j++]); you should not increment i and j here
            swap(arr[i],arr[j]);
        }
    }
    return right_position;
}
void QuickSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = Partition(arr,start,end);
    QuickSort(arr,start,pivot-1);
    QuickSort(arr,pivot+1,end);
}
int main(){
    vector<int>arr = {4,2,1,5,8,20,10,30};
    int s = 0;
    int e = arr.size()-1;
    QuickSort(arr,s,e);
    for(auto value:arr){
        cout<<value<<" ";
    }
}