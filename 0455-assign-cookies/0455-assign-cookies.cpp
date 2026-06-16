class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        // grid factor chota hona chahiye  cookie k size se!!
        sort(g.begin(),g.end()); //1.2.3
        sort(s.begin(),s.end()); //1,1
        int i=0;
        int j =0;
        int cnt =0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};