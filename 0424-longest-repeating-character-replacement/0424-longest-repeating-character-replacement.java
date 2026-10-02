class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int i=0;
        int maxFreq =0;
        int maxLen = 0;
        int[] freq = new int[26];
        for(int j=0;j<n;j++){
            freq[s.charAt(j)-'A']+=1;
            maxFreq = Math.max(freq[s.charAt(j)-'A'],maxFreq);
            while((j-i+1)-maxFreq>k){
             freq[s.charAt(i)-'A']-=1;
             i++;
            }
            maxLen = Math.max(maxLen,j-i+1);
        }
        return maxLen;
    }
}