#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
int mini_coins(vector<int>&coins,int target){
    if(target ==0){
        return 0;
    }
    if(target <0){
        return -1;
    }
    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
      int ans = mini_coins(coins,target-coins[i]);
      if(ans !=-1){
          mini = min(ans,mini);
      }
    }
    if(mini == INT_MAX){
        return -1;
    }
    return mini +1 ;
}
int main(){
    vector<int>coins = {1,2,3,4,5};
    int target = 25;
    cout<<mini_coins(coins,target);
}
/*Second Method
 class Solution {

public:
    void mini(vector<int>&coins,int target,int steps,int &ans){
        if(target==0){
            ans = min(steps,ans);
        }
        if(target<0){
            return;
        }
        for(int i=0;i<coins.size();i++){
            mini(coins, target - coins[i], steps + 1, ans);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int steps = 0;
        int ans = INT_MAX;
        mini(coins,amount,steps,ans);
        if(ans ==INT_MAX){
            return -1;
        }
        return ans;
        
    } 
};
*/
    