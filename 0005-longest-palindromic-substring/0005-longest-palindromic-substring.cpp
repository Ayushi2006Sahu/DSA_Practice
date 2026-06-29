class Solution {
public:
int expandArCentre(string s,int left,int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left -- ;
        right++;
    }
    return right-left-1;
}
    string longestPalindrome(string s) {
        int strt = 0 ;
        int maxLen = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int len1 = expandArCentre(s,i,i);
            int len2 = expandArCentre(s,i,i+1);
            int len = max(len1,len2);
            if(len>maxLen){
                maxLen = len ;
                strt = i-(len-1)/2;
            }
        }
        return s.substr(strt,maxLen);
    }
};