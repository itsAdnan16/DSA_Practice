#include<iostream>
#include<vector>
using namespace std;
int max_peices(int l,int x,int y,int z){
    //Base case
    if(l == 0){
        return 0;
    }
    if(l <0){
        return INT_MIN;
    }
    int ans1 = max_peices(l-x,x,y,z);
    int ans2 = max_peices(l-y,x,y,z);
    int ans3 = max_peices(l-z,x,y,z);

    int final_ans = 1 + max(max(ans1,ans2),ans3);
    return final_ans;
}
int main(){
    int l = 17;
    int x = 11;
    int y = 3;
    int z = 10;
    int ans = max_peices(l,x,y,z);
    if(ans<0){
        cout<<0;
    }
    else{
        cout<<"The number of peices are "<<ans;
    }
}