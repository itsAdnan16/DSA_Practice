#include<iostream>
#include<string>
using namespace std;
void rev(string & str,int i,int j){
    if(i>=j){
        return;
    }
    //one step
    swap(str[i],str[j]);
    rev(str,i+1,j-1);
}
int main(){
    string str = "anas";
    int i = 0;
    int j = str.length() -1;
    rev(str,i,j);
    cout<<"The reversed string is "<<str;

}
