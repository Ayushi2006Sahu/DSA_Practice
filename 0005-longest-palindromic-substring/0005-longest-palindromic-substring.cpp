class Solution {
public:
    bool solve(string &s,int i,int j){
        if(i>=j)return true;
        if(s[i]==s[j]){
            return solve(s,i+1,j-1);
        }
        return false; 
    }
    
    string longestPalindrome(string s) {
    int n = s.length();
    int sp = 0;
    int max_length = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(solve(s,i,j)==true){
                if(j-i+1>max_length){
                    max_length = j-i+1;
                    sp = i;
                }
            }
        }
    }
    return s.substr(sp,max_length);
    }
};