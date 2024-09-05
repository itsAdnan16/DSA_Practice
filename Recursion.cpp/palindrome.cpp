#include<iostream>
using namespace std;
bool isPalin(string str,int i,int j){
    if(i>=j){
        return true;
    }
    //now we will solve the one case
    if(str[i] != str[j]){
        return false;
    }
    return isPalin(str,i+1,j-1);
}
int main(){
    string str = "mango";
    int i = 0;
    int j = str.length()-1;
    if(isPalin(str,i,j)){
        cout<<"It is palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome";
    }
}