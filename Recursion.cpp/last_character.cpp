#include<iostream>
#include<vector>
using namespace std;
void last_occur(string str,int &last,int n,int index,char ch){
    if(index>=n){
        return;
    }
    //now we will solve the case rest recursion will solve
    if(str[index]==ch){
        last = index;
    }
    //now recursion will solve
    last_occur(str,last,n,index+1,ch);
}
//better approach will be from going right to left
int main(){
    string str = "adnanhasan";
    int index = 0;
    int last = -1;
    char ch = 'a';
    int n = str.length();
    last_occur(str,last,n,index,ch);

}