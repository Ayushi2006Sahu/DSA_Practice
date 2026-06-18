class Solution {
public:

    void solve(vector<int>&nums,vector<int>&curr,vector<bool>&vis,vector<vector<int>>&ans){
        // means ek permutation taiyay hogaya !!
        if(curr.size()==nums.size()){
            ans.push_back(curr);

        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                // to usko lo 
                vis[i]= true;
                curr.push_back(nums[i]);
                solve(nums,curr,vis,ans);
                // backtracking 

                curr.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>>res;
      vector<int>curr; // curr_permutations
      vector<bool>vis(nums.size(),false);

      solve(nums,curr,vis,res);
      return res;

    }
};