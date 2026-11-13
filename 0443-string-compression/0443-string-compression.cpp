class Solution {
public:
    int compress(vector<char>& chars) {
        int ans =0;
        for(int i=0;i<chars.size();){
            char ch = chars[i];
            int cnt =0;
            while(i<chars.size() && chars[i] == ch ){
                cnt++;
                i++;
            }
            chars[ans++]=ch;
            if(cnt>1){
                for(char c:to_string(cnt)){
                    chars[ans++]=c;
                }
            }
        }
        return ans;
    }
};