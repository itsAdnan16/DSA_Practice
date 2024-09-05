#include<iostream>
#include<vector>
using namespace std;
void print_utility(int arr[],int n,int &start,int &end){
    //base case
    if(end>=n){
        return;
    }
    //now 
    for(int i =start ;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    end++;
    print_utility(arr,n,start,end);
}
//2nd function used to change the starting point of the array
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        int start = i;
        int end = i;
        print_utility(arr,n,start,end);
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    print(arr,5);
}