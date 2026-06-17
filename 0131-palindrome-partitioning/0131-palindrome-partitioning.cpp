class Solution {
public:
    bool pal(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
    void Sub(int idx,vector<vector<string>>&ans,vector<string>&temp,string s){
        if(idx==s.size())ans.push_back(temp);
        for(int i=idx;i<s.size();i++){
            if(pal(s,idx,i)){
               temp.push_back(s.substr(idx,i-idx+1));
                Sub(i+1,ans,temp,s);
                temp.pop_back();
            }
        }
    }
     vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        Sub(0, ans, temp, s);
        return ans;
    }
};