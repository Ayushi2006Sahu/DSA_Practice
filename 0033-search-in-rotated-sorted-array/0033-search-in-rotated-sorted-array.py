class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        low =0
        high = n-1
        while(low<=high):
            mid = low+(high-low)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]>=nums[low]:
                if nums[mid]>=target and  nums[low]<=target:
                    high = mid-1
                else:
                    low = mid+1
            else:
                if nums[mid]<=target and nums[high]>=target:
                    low = mid+1
                else:
                    high = mid-1
        
        return -1
        