class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto &m:mp){
            pq.push({m.second,m.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};