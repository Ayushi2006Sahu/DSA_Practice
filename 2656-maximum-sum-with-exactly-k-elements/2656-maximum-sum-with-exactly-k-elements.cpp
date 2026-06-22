class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
       sort(nums.rbegin(),nums.rend());
        int sum= 0;
       while (k--){
        sum+=nums[0];
           nums[0]= nums[0]+1;
       }
        return sum;
    }
};