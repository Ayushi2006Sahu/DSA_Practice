class Solution {
public:
void solve(int index,vector<int>& candidates,vector<int>temp,int target,vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(index == candidates.size() || target<0)return;
    // include
    temp.push_back(candidates[index]);
    solve(index,candidates,temp,target-candidates[index],ans);
    temp.pop_back();
    // exclude
    solve(index+1,candidates,temp,target,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates,temp,target,ans);
        return ans;
    }
};