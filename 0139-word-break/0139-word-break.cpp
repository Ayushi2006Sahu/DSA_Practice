class Solution {
public:

// bool wordBreakHelper(string& s,vector<string>&wordDict,int start){
     
//       if(start==s.length())return true;
//         for(const string& word:wordDict){
//             int len = word.length();
//             int end = start+len;
//             if(end>s.length())
//                 continue;
//         if(s.substr(start,len)==word){
//             if(wordBreakHelper(s,wordDict,start+len))
//                 return true;
//         }
//         }
//         return false;
// }

    bool wordBreak(string s, vector<string>& dict) {
       vector<bool> t(s.length() + 1, false);
        t[0] = true; // Initial state
        
        for (int i = 0; i < s.length(); i++) {
            if (!t[i]) 
                continue;
            
            for (const string& word : dict) {
                int len = word.length();
                int end = i + len;
                
                if (end > s.length()) 
                    continue;
                
                if (t[end]) 
                    continue;
                
                if (s.substr(i, len) == word) {
                    t[end] = true;
                }
            }
        }
        return t[s.length()];
    }
};