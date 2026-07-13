class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;

        int iniColor = image[sr][sc];
        
        queue<pair<int, int>> que;
       
        if (iniColor == color)
            return ans;
        que.push({sr, sc});
        ans[sr][sc] = color;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while (!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
           
            for (int d = 0; d < 4; d++) {
                int nr = dx[d] + r;
                int nc = dy[d] + c;
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    image[nr][nc] == iniColor &&  ans[nr][nc] != color) {
                         ans[nr][nc] = color;
                    que.push({nr, nc});
                }
            }
        }
        return ans;
    }
};