/*class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() -1;
        int j = num2.length()-1;
        int carry =0;
        string output = "";
        while(i>=0 || j>=0 || carry>0){
        
            int sum = ((i >= 0) ? (num1[i] - '0') : 0) + ((j >= 0) ? (num2[j]-'0') : 0) + carry;
            //2nd meethod to do this
            //int sum = ((i >= 0) ? stoi(string(1, num1[i])) : 0) + ((j >= 0) ? stoi(string(1, num2[j])) : 0) + carry;

            carry = sum/10;
            sum = sum %10;
            //carry = sum/10; bhosdk sum ko update karne se pehla carry nikalna
            output =  to_string(sum) + output;
            i--;
            j--;
        }
        return output;
    }
};*/
//now we will write the recursive code
#include<iostream>
#include<string>
using namespace std;

void add_strings(string & num1,string &num2,int &i,int &j,string &output,int &carry){
    if(i<0 && j<0 && carry==0){
        return ;
    }
    //now we will solve the one step
     int sum = ((i >= 0) ? (num1[i] - '0') : 0) + ((j >= 0) ? (num2[j]-'0') : 0) + carry;
     carry = sum /10;
     sum = sum %10;
     output = to_string(sum) + output;
     i--;
     j--;
     //rest recursion will solve
     add_strings(num1,num2,i,j,output,carry);
}
int main(){
    string num1 = "123";
    string num2 = "191";
    string output = "";
    int i = num1.length()-1;
    int j = num2.length()-1;
    int carry = 0;
    add_strings(num1,num2,i,j,output,carry);
    cout<<output;
}
