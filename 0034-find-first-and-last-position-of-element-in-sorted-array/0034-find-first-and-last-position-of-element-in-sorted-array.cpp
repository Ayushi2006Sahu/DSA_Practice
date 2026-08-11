class Solution {
public:
int binarySearch(vector<int>& nums, int target,bool isSearchingLeft){
    int n = nums.size();
    int low=0;
    int high = n-1;
    int idx =-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]>target){
            high=mid-1;
        }
        else if(nums[mid]<target){
            low = mid+1;
        }
        else{
            idx=mid;
            if(isSearchingLeft){
                high = mid-1;
            }
            else low = mid+1;

        }
    }
    return idx;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res= {-1,-1};
        res[0]= binarySearch(nums,target,true);
        res[1]= binarySearch(nums,target,false);
        return res;

    }
};