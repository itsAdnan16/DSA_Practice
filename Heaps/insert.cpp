#include<iostream>
#include<vector>
using namespace std;
vector<int>arr = {-1,110,60,100,30,20,49,67,10,5,4};
void insert(int data){
    //1 pehle insert karo
    arr.push_back(data);
     
     //2 phir usko uski right position pe leke jao
     int i = arr.size()-1;
    while(i>1){
        int parent = i/2;
        if(arr[i]>arr[parent]){
            swap(arr[i],arr[parent]);
            i = parent;
        }
        else{
            break;
        }
    }
}
void dlt(){
    //root ko last element se replace karo
    arr[1] = arr[arr.size()-1];
    //last element delethm pop back babbar = size--
    arr.pop_back();
    //ab root usko right position pe leke jaana
    int index = 1;
    while(index < arr.size()){
        int largest = index;
        int left = 2*index;
        int right = 2*index + 1;
        // arr[left]>arr[right] no need to put this condition
        if(left <arr.size() && arr[largest]<arr[left]){
            largest=left;
        }
        // arr[left]<arr[right]
        if(right<arr.size() && arr[largest]<arr[right] ){
            largest = right;
        }
        if(index == largest ){
            return;
        }
        else{
            swap(arr[index],arr[largest]);
            index = largest;
        }
    }

}
void print(){
    for(int i=1;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    /*insert(57);
    insert(111);
    print();*/
    dlt();
    print();
    
}