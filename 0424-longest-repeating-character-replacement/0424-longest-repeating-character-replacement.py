class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        i = 0
        j=0
        maxFre =0
        maxlen =0
        freq=[0]*26
        while j<n:
            idx_j = ord(s[j]) - ord('A')
            freq[idx_j]+=1
            maxFre = max(maxFre,freq[idx_j])
            # shrink:
            while (j-i+1)-maxFre>k:
                idx_i = ord(s[i]) - ord('A')
                freq[idx_i ]-=1
                i+=1
            maxlen = max(maxlen,j-i+1)
            j+=1
        return maxlen
