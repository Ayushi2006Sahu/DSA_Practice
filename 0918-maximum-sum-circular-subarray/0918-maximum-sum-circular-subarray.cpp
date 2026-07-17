class Solution {
public:
    int maxKadan(vector<int>& nums){
        int curr =0;
        int maxi = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            curr+=nums[i];
            maxi = max(maxi,curr);
            if(curr<0)curr=0;
        }
        return maxi;
    }
    int minKada(vector<int>&nums){
        int curr =0;
        int mini = nums[0];
        int n = nums.size();
        for(int i =0;i<n;i++){
            curr+=nums[i];
            mini = min(mini,curr);
            if(curr>0)curr=0;
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot_sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            tot_sum += nums[i];
        }
        int rem = tot_sum - minKada(nums);
        int maxk = maxKadan(nums);
        if(maxk < 0) return maxk;
        int maxi = max(maxk, rem);
        return maxi;
    }
};