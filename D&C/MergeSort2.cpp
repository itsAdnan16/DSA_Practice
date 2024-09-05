



#include<iostream>
#include<vector>
using namespace std;
int  Merge(vector<int>&arr,vector<int>&temp,int start,int end){
    int mid = (start + end)/2;
    int i = start;
    int j = mid+1;
    int k = start;
    int inversion = 0;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            inversion += mid - i+ 1;
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    for(int i=start;i<=end;i++){
        arr[i]=temp[i];
    }
    return inversion;

}
int MergeSort(vector<int>&arr,vector<int>&temp,int start,int end){
    int inversion = 0;
    if(start<end){
        //int inversion = 0;
        int mid = (start + end)/2;
        inversion += MergeSort(arr,temp,start,mid);
        inversion += MergeSort(arr,temp,mid+1,end);
        inversion += Merge(arr,temp,start,end); 
    }
    return  inversion;
    
}
int main(){
    vector<int>arr = {8,4,2,1};
    vector<int>temp(arr.size(),0);
    int start = 0;
    int end = arr.size()-1;
    int inversion;
    inversion = MergeSort(arr,temp,start,end);
    cout<<"Number of inversion are "<<inversion<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}