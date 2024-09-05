#include<iostream>>
using namespace std;
class Stack{
    private:
    int * arr;
    int size;
    int top;
    public:
    Stack(int size){
        this->size = size;
        top = -1;
        arr= new int(size);
    }
    void push(int data){
        if(size-top == 1){
            cout<<"Stack overflow";
        }
        else{
            top++;
            arr[top] = data;
        }
        return;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack underflow";
        }
        else{
            top--;
        }
        return;
    }
    int get_size(){
        return top+1;
    }
    bool empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    int get_top(){
        if(top == -1){
            cout<<"Stack underflow";
        }
        else{
            return arr[top];
        }
    }
};
int main(){
    int size = 5;
    Stack s (size);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"The size of stack is "<<s.get_size()<<endl;
    s.pop();cout<<endl;
    cout<<"The top element is "<<s.get_top()<<endl;


}