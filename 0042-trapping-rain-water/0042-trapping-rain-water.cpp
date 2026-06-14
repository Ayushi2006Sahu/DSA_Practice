class Solution {
public:
    int trap(vector<int>& height) {
        int ans  = 0;
        int n = height.size();
        int max_left = INT_MIN;
        int max_right = INT_MIN;
        int l =0;
        int r = n-1;
        while(l<=r){
            if(height[l]<=height[r]){
                max_left = max(max_left,height[l]);
                ans+=(max_left-height[l]);
                l++;
            }
            else{
                max_right = max(max_right,height[r]);
                ans+=(max_right-height[r]);
                r--;
            }

        }
        return ans;
    }
};