class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&](int a, int b) { return nums1[a] < nums1[b]; });

        priority_queue<int, vector<int>, greater<int>> pq;
        long long current_sum = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            int curr_idx = indices[i];

            while (j < i && nums1[indices[j]] < nums1[curr_idx]) {
                pq.push(nums2[indices[j]]);
                current_sum += nums2[indices[j]];

                if (pq.size() > k) {
                    current_sum -= pq.top();
                    pq.pop();
                }
                j++;
            }

            ans[curr_idx] = current_sum;
        }

        return ans;
    }
};