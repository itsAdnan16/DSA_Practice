#include<iostream>
#include<vector>
using namespace std;
class Circular{
    private:
    int front;
    int rear;
    int n;
    vector<int>arr;

    public:
    Circular(int n){
        this->n = n;
        arr.resize(n);
        front = -1;
        rear = -1;
    }
    //now rear is not pointing to the next free space now it is pointing to the place where the last element was filled
    void push(int data){
        //check for full
        //circular nature
        //first element
        //normal case
        if((front==0 && rear==n-1) ||(rear+1==front)){
            cout<<"Overflow message";
            return -1;
        }
        else if(rear == n && front!=0){
            rear = 0;
            arr[rear] = data;
        }
        else if(front ==-1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        
        }
    }
    void pop(){
        //empty
        //circular nature
        //single element
        //normal case
        if(front == -1){
            cout<<"Underflow";
        }
        else if(rear>=0 && front==n-1){
            front = 0;
        }
        else if(front  == rear){
            front =-1;
            rear = -1;
        }
        else{
            front ++;
        }
    }

}