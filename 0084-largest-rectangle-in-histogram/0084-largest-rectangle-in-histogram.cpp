class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : heights[i]);

            while (!st.empty() &&  heights[st.top()] > curr) {
                int x = heights[st.top()];
                st.pop();
                int right = i;
                int left = st.empty()?-1:st.top();
                int width = right-left-1;
                maxArea = max(maxArea,width*x);
            }
            st.push(i);
        }
        return maxArea;
    }
};