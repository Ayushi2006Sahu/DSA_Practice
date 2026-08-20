class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num<=1:
            return False
        tot_sum = 1 
        for i in range(2,int(num**0.5)+1):
            if num%i==0:
                tot_sum +=i
                if i*i!=num:
                    tot_sum+=num//i
        return tot_sum == num