#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int target, const std::vector<int>& candidates, std::vector<int>& ans, std::vector<std::vector<int>>& result, int index) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            ans.push_back(candidates[i]);
            for(int j=index;j<candidates.size();j++){
                if(i==j){
                    continue;
                }
                 solve(target - candidates[i], candidates, ans, result, j);
                 ans.pop_back();
            }
            //solve(target - candidates[i], candidates, ans, result, i);
            // Backtracking
            //ans.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> ans;
        std::vector<std::vector<int>> result;
        solve(target, candidates, ans, result, 0);
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    std::vector<std::vector<int>> result = solution.combinationSum(candidates, target);

    // Display the result
    for (const auto& vec : result) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
