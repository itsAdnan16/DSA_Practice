#include<string>
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str = "adnan";
    stack <char> s;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    for(int i=0;i<str.size();i++){
        str[i] = s.top();
        s.pop();
    }
    cout<<str;
}