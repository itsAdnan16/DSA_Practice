#include<iostream>
#include <vector>
using namespace std;
class Deque{
    private:
    int front;
    int rear;
    int n;
    vector<int>arr;

    public:
    Deque(int n){
        this->n = n;
        front = -1;
        rear = -1;
        arr.resize(n);
    }
    //push rear - normal case
    void push_back(int data){
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

    //pop from front - normal case
    void pop_front(){
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

    //push front = new case
     void push_front(int data){
        //check for full
        //circular nature
        //first element
        //normal case
        if((front==0 && rear==n-1) ||(rear+1==front)){
            cout<<"Overflow message";
            return -1;
        }
        else if(front ==0 && rear!=n-1){
            front  = n-1;
            arr[front] = data;
        }
        else if(front ==-1 && rear == -1){
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else{
            front--;
            arr[front] = data;
        
        }
    }

    //pop_back new case (now we erase elements form the back)
     void pop_back(){
        //empty
        //circular nature
        //single element
        //normal case
        if(front == -1){
            cout<<"Underflow";
        }
        else if(rear==0){
            rear = n-1;
        }
        else if(front  == rear){
            front =-1;
            rear = -1;
        }
        else{
             rear--;
        }
    }



}