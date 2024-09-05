0#include <iostream>
#include <vector>
using namespace std;
int Merge(vector<int>& arr, int start, int end) {
    int mid = (end + start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int* left = new int[len1];
    int* right = new int[len2];
    int k = start;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }
    int i = 0, j = 0, inversion = 0;
    int mi = start;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[mi++] = left[i++];
        } else {
            inversion += (mid - start + 1);
            
            arr[mi++] = right[j++];
        }
    }
    while (i < len1) {
        arr[mi++] = left[i++];
    }
    while (j < len2) {
        arr[mi++] = right[j++];
    }
    delete[] left;
    delete[] right;
    return inversion;
}

int MergeSort(vector<int>&arr,int start,int end){
    int inversion = 0;
    if(start<end){
         int mid = (start + end)/2;
        //sorting the left array
        inversion += MergeSort(arr,start,mid);
        //sorting the right array
        inversion += MergeSort(arr,mid+1,end);
        //calling the merge function to merge two sorted array
        inversion += Merge(arr,start,end);
       
    }
    return inversion;
   

}
int main(){
    vector<int>arr = {5,4,1,6};
    int inversion = 0;
  
   inversion = MergeSort(arr,0,arr.size()-1);
    cout<<"Number of Inversion are "<<inversion<<endl;
    for(auto value:arr){
        cout<<value<<" ";
    }
}