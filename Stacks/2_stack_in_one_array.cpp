#include<iostream>
using namespace std;
class Stack{
    private:
    int size;
    int top1;
    int top2;
    int * arr;

    public:
    Stack(int size){
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int(size);
    }
    void push1(int data){
        if(top2-top1 == 1){
            cout<<"Stack overflow";
        }
        else{
            top1 ++;
            arr[top1] = data;
        }
    }
     void push2(int data){
        if(top2-top1 == 1){
            cout<<"Stack overflow";
        }
        else{
            top2 --;
            arr[top1] = data;
        }
    }
    void pop1(){
        if(top1 == -1){
            cout<<"stack underflow";
        }
        else{
            top1--;
        }
    }
    void pop2(){
        if(top2 == size){
            cout<<"Stack underflow";
        }
        else{
            top2++;
        }
    }
    int get_top1(){
        if(top1 == -1){
            cout<<"No element in the stack"<<endl;
            return -1;
        }
        else{
            return arr[top1];
        } 
    }
};
int main(){
    int size = 4;
    Stack s(size);
    s.push1(1);
    s.push1(2);
    s.push2(3);
    s.push2(4);
    s.push1(5);
    s.pop1();
    s.push1(10);
    cout<<s.get_top1();

    
}