class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int le =0;
        int ri = n-1;
        int pos = n-1;
        while(le<=ri){
            int l = nums[le]*nums[le];
            int r = nums[ri]*nums[ri];
            if(l>r){
                ans[pos]=l;
                le++;
            }
            else{
                ans[pos]= r;
                ri--;
            }
            pos--;
        }
       return ans; 
    }
};