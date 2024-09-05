#include<iostream>
using namespace std;
/*void print(int &number){
    if(number<=0){
        return;
    }
    
    int digit = number%10;
    cout<<digit<<" ";
    number = number/10;
    print(number);
}*/
void print(int &number){
    if(number<=0){
        return;
    }
    number = number/10;
    print(number);
    int digit = number%10;
    cout<<digit<<" ";
}
void print(int &number){
    if(number<=0){
        return;
    }
    
    int digit = number%10;
    cout<<digit<<" ";
    number = number/10;
    print(number);
}
int main(){
    int n = 647;
    print(n);
}