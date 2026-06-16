class Solution {
public:
    void getAllSubset(int index, vector<int>& nums, vector<int>& ans,
                      vector<vector<int>>&AllSubset) {
        if (index == nums.size()) {
            AllSubset.push_back(ans);
            return;
        }
        // include..
        ans.push_back(nums[index]);
        getAllSubset(index+1,nums,ans,AllSubset);
        ans.pop_back();
        int idx = index+1;
        // not include..
        while(idx<nums.size()&& nums[idx]==nums[idx-1]){
            idx++;
        }
        getAllSubset(idx,nums,ans,AllSubset);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> AllSubset;
        vector<int> ans;
        getAllSubset(0, nums, ans, AllSubset);
        return AllSubset;
    }
};