class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> ls;
        string temp = "";
        for (int i = 0; i < n; i++) {

            if (s[i] != ' ') {
                temp += s[i];
            } else {
                if (!temp.empty()) { // 3. Khali strings ko skip karne ke liye
                    ls.push_back(temp);
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            ls.push_back(temp);
        }
        reverse(ls.begin(), ls.end());
        string ans = "";
        for (int i = 0; i < ls.size(); i++) {
            if (i != ls.size() - 1) {
                ans += ls[i] + " ";
            } else {
                ans += ls[i];
            }
        }
        return ans;
    }
};