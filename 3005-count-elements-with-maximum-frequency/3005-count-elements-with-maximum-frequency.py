class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mp = {}
        n = len(nums)  
        
        # Frequency count karna
        for i in nums:
            mp[i] = mp.get(i, 0) + 1

        # Max frequency nikalna
        maxi = 0
        for i in mp:
            if mp[i] > maxi:
                maxi = mp[i]
                
        # Maximum frequency waale elements count karna
        maxi_ele = 0
        for i in mp:
            if mp[i] == maxi:  # Corrected comparison operator (==)
                maxi_ele += 1   
                
        return maxi_ele * maxi