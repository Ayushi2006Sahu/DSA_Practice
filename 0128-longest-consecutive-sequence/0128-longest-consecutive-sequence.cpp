class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max_cnt = INT_MIN;
        int cnt=1;
        if(n==0|| n==1)return n;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                 max_cnt = max(max_cnt,cnt);
                
                continue;
            }

            else if(nums[i]==nums[i-1]+1){
                cnt++;
               
            }
            else{
                max_cnt = max(max_cnt,cnt);
                cnt =1;
            }
             max_cnt= max( max_cnt,cnt);
        }
        return max_cnt;
    }
};