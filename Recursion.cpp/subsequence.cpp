#include<iostream>
using namespace std;
void print(string &str,string output,int index){
    if(index>=str.length()){
        cout<<output<<endl;
        return;
    }
    //include
    print(str,output + str[index],index+1);
    //exclude
    print(str,output,index+1);

}
int main(){
    string str = "abc";
    string output = "";
    int index = 0;
    print(str,output,index);
}