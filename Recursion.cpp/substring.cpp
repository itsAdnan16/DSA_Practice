#include<iostream>
#include<string>
using namespace std;
void dlt(string &str,string &part){
    int found = str.find(part);
    //now we write the base case when we have to return when we do not find the substring
    if(found == string::npos){
        return;
    }
    else{
        string left_part = str.substr(0,found);
        string right_part = str.substr(found+part.size(),str.size());
        str = left_part + right_part;
        dlt(str,part);
    }
}
int main(){
    string str = "daabcbaaabcbc";
    string part = "abc";
    dlt(str,part);
    cout<<str;
}