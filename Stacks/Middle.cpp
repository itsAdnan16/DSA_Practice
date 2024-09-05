#include<iostream>
#include<stack>
using namespace std;
int Find_Middle(stack<int>&s,int &total_size){
    // these are the base cases
    if(total_size == 0){
        return -1;
    }
    if(s.size() == total_size/2 + 1){
        return s.top();
    }
    //we are solving the one step
    int temp = s.top();
    s.pop();
    //now rest recursion will do
    int middle = Find_Middle(s,total_size);
    //now we will backtrack
    s.push(temp);

    return middle;
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int total_size = s.size();

    int middle = Find_Middle(s,total_size);

    cout<<"The middle element is "<<middle;

}