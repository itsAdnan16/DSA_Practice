//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	bool is_safe(vector<string>&ans,string&s){
	    for(int i=0;i<ans.size();i++){
	        if(ans[i]==s){
	            return false;
	        }
	    }
	    return true;
	}
	void solve(string s,vector<string>&ans,int index){
	    if(index>=s.size()){
	        if(is_safe(ans,s)){
	            ans.push_back(s);
	        }
	      
	        return;
	    }
	    for(int j=index;j<s.size();j++){
	        swap(s[index],s[j]);
	        solve(s,ans,index+1);
	        //backtracking
	        swap(s[j],s[index]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    int index = 0;
		    solve(S,ans,index);
		    return ans;
 
		    // Code here there
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends










//Method 2:- Using hashmap 
/*class Solution {
public:
   void solve(vector<int>&nums,int i,vector<vector<int>>&result){
       if(i>=nums.size()){
           result.push_back(nums);
           return;
       }
       unordered_map<int,bool>check_repeat;
       for(int j=i;j<nums.size();j++){
           if(check_repeat.find(nums[j])!= check_repeat.end()){
               continue;
           }
            check_repeat[nums[j]] = true;
            swap(nums[i],nums[j]);
            solve(nums,i+1,result);
            //backtrack
            swap(nums[i],nums[j]); 
       }
   }
   
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        int i=0;
        solve(nums,i,result);
        return result;
        
    }
};*/