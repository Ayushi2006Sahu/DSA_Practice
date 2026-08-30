class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> block_cnt;
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] !=nums[i - 1]) {
                block_cnt[nums[i]]++;
            }
        }
        int ans = 0;
        for(auto& [val,blocks]:block_cnt){
            if(blocks==1){
                ans++;
            }
        }
        return ans;
    }
};