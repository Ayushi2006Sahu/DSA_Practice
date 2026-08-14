class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        strt =0
        curr =0
        tot =0
        for i in range(n):
            res = gas[i]-cost[i]
            curr+=res
            tot+=res
            if curr<0:
                strt=i+1
                curr = 0
        if tot<0:
            return -1
        return strt