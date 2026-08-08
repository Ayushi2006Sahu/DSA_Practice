class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mp = defaultdict(int)
        mp[0]=1
        cum =0
        res =0
        for i in range(n):
            cum+=nums[i]
            if (cum-k)in mp:
                res+=mp[cum-k]
            mp[cum]+=1
        return res
        