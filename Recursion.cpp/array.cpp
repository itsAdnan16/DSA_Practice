#include<iostream>
using namespace std;
void print(int arr[],int &n,int & index){
    //base case
    if(index>=n){
        return;
    }
    //we are solving for the one 
    cout<<arr[index++]<<endl;
    print(arr,n,index);
}
void maximum(int arr[],int &n,int & index,int &maxi){
    //base case
    if(index>=n){
        return ;
    }
    //we are solving for the one 
    maxi = max(arr[index++],maxi);
    maximum(arr,n,index,maxi);
}

int main(){
    int arr[4] = {1,2,3,4};
    int n = 4;
    int index = 0;
    //print(arr,n,index);
    int maxi = INT_MIN;
    maximum(arr,n,index,maxi);
    cout<<"The maximum number is: "<<maxi;
}