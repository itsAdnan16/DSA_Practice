#include<iostream>
using namespace std;
bool sorted(int arr[],int &n,int &index){
    //base case
    if(index >=n-1){
        return true;
    }
    //now we are one case
    if(arr[index]>arr[index+1]){
        return false;
    }
    index = index+1;
    //now for the rest of the array recursion will solve and return the answer
    return sorted(arr,n,index);
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int index = 0;
    int size = 5;
    if(sorted(arr,size,index)){
       cout<<"the array is sorted";
    }
    else{
        cout<<"The array is not sorted";
    }
}