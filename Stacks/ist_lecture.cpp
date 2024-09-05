#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    cout<<s.top()<<endl;
    if(s.empty()){
        cout<<"It is empty";
    }
    else{
        cout<<"Size is "<<s.size();
    }

}