#include<iostream>
using namespace std;
bool search(string s,char &ch,int &index){
    //base case
    if(index >= s.length()){
       return false;
    }
    //now we are solving the one case
    if(s[index++]==ch){
        return true;
    }
    //Rest recursion will solve and give the answer
    return search(s,ch,index);
  
}
//modifying the above code if we can have multiple occurence and we will print its index
void multiple_search(string s,char &ch,int &index){
    //base case
    if(index >= s.length()){
       return ;
    }
    //now we are solving the one case
    if(s[index]==ch){
        cout<<"Found at index "<<index<<endl;
    }
    index +=1;
    //Rest recursion will solve and give the answer
  multiple_search(s,ch,index);
  
}
int main(){
    
    string str = "adnananananana";
    int index = 0;
    char ch = 'n';
    /*if(search(str,ch,index)){
        cout<<"Found";
    }
    else{
        cout<<"Not found";
    }*/
   multiple_search(str,ch,index);
}