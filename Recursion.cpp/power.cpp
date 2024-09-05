#include<iostream>
using namespace std;

int find_exponent(int number,int power){
    if(power == 0){
        return 1;
    }
    int ans = 2 * find_exponent(number,power-1);
    return ans;
}
int main(){
    cout<<find_exponent(2,4);
}