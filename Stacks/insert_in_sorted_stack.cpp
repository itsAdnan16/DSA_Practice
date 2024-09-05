#include<stack>
#include<iostream>
using namespace std;

void insert_sorted_order(stack<int>&s,int data){
    if(data >= s.top() || s.empty()){
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insert_sorted_order(s,data);
    s.push(temp);
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
    s.push(40);
    s.push(50);

    print_stack(s);
    insert_sorted_order(s,30);
    print_stack(s);

}