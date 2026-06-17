class Solution {
public:
    void solve(vector<int>& candidates, int target, int strt, vector<int>& temp,
               vector<vector<int>>& ans) {
        // Base case: combination found
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = strt; i < candidates.size(); i++) {
            // Skip duplicates in the same recursion level to avoid duplicate
            // combinations
            if (i > strt && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }

            // Include the current element
            temp.push_back(candidates[i]);

            // Move to the next index with the reduced target
            solve(candidates, target - candidates[i], i + 1, temp, ans);

            // Backtrack to explore other paths
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};