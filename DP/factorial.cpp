#include<vector>
#include<climits>
class Solution {
public:
    /*int recursive_fib(int n) {
        //base case
        if(n==0 || n==1){
            return n;
        }
        int ans = recursive_fib(n-1) + recursive_fib(n-2);
        return ans;
    }*/
    //this is top down approach
    int tabulation(int n){
        //step 1 :- create a dp array
        vector<int>dp(n+1,-1);
        //step2 :- initial values fill kardo using the base case of recursion 
        dp[0]=0;
        if(n==0){
            return dp[0];
        }
        dp[1]=1;
        //step3 :- bacha hua dp array fill kardo

        for(int i=2;i<=n;i++){//loop hamesha n tk hi chalana

            //base case ka niche wala pura code copy kardo aur jidhar pe recursive calls usa replace kardo dp array se
           dp[i]= dp[i-1] + dp[i-2];//yha pe n ki jagah i se replace kardena
        }
        return dp[n];
    }
    int space_optimization(int n){
        int prev = 0;
        int current = 1;
        int ans;
        if(n==0 || n==1){
            return n;
        }
        for(int i=2;i<=n;i++){
          ans = prev + current;
          prev = current;
          current = ans;
           
        }
        return ans;
    }
    int solve_memoization(int n,vector<int>&dp){
        if(n==0 || n==1){
            return n;
        }

        //step 3 :- return the answer if it is already present int the dp array
        if(dp[n] !=-1){
            return dp[n];
        }
        //step2 store and return the answer using dp array
        dp[n] = solve_memoization(n-1,dp) + solve_memoization(n-2,dp);
        return dp[n];
    }

    int fib(int n){
        //step1 create dp array
        //vector<int>dp(n+1,-1);
        //int  ans = solve_memoization(n,dp); memoization method
        int ans = space_optimization(n);
        return ans;
    }
};