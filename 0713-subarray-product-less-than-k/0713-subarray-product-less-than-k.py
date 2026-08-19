class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        i =0
        j =0
        pro =1
        cnt =0
        while j<n:
            pro*=nums[j]
            # srinking
            while i<=j and pro>=k:
                pro//=nums[i]
                i+=1
           
            cnt+=(j-i+1)
            j+=1
        return cnt