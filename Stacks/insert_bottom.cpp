#include<iostream>
#include<stack>
using namespace std;

void print_stack(stack<int>s){
      while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
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
int main(){
    stack<int>s;
    s.push(20);
    s.push(20);
    s.push(30);
    cout<<"after pushing an element at the end of linked list"<<endl;
    insert_bottom(s,10);
    print_stack(s);

}