#include<iostream>
#include<vector>
using namespace std;
void max_prof(vector<int>&prices,int index,int &buy_price,int & max_profit){
    if(index>=prices.size()){
        return;
    }
    //one step
    buy_price = min(buy_price,prices[index]);
    int profit = prices[index] - buy_price;
    max_profit = max(profit,max_profit);
    //now recursion will solve
    index += 1;
   max_prof(prices,index,buy_price,max_profit);
}
int main(){
    vector<int>prices = {7,1,5,3,6,4};
    int buy_price = prices[0];
    int max_profit = 0;
    int index = 0;
    max_prof(prices,index,buy_price,max_profit);
    cout<<max_profit;

    /*for(int i=0;i<prices.size();i++){
        buy_price = min(buy_price ,prices[i]);
        int profit = prices[i] - buy_price;
        max_profit = max(max_profit,profit);

    }
    if(max_profit <0){
        cout<<0;
    }else{
        cout<<"The maximum profit is "<<max_profit;
    }*/
}

