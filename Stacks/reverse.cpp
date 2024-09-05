#include<iostream>
#include<stack>
using namespace std;
void insert_bottom(stack<int>&s,int data){
    //base case
    if(s.empty()){
        s.push(data);
        return;
    }
    //performing the one step
    int temp = s.top();
    s.pop();
    //next recursion will do
    insert_bottom(s,data);
    s.push(temp);

}
void reverse(stack<int>&s){
    //base case
    if(s.empty()){
        return;
    }
    int element = s.top();
    s.pop();
    reverse(s);
    insert_bottom(s,element);
}
void print_stack(stack<int>s){
      while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Before reversing the stack"<<endl;
    print_stack(s);
    reverse(s);
    cout<<"After reversing the stack"<<endl;
    print_stack(s);
    
}