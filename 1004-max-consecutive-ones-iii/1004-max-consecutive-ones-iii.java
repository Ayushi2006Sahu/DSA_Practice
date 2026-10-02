class Solution {
    public int longestOnes(int[] nums, int k) {
     int i =0;
     int n = nums.length;
     int zeroCnt =0;
     int maxLen =0;
     for(int j=0;j<n;j++){
        if(nums[j]==0)zeroCnt++;
        while(zeroCnt>k ){
           if(nums[i]==0)zeroCnt--;
            i++;
        }
        maxLen = Math.max(j-i+1,maxLen);
     }  
     return maxLen; 
    }
}