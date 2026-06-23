class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>>que;
        vector<int>ans;
        for(auto &m:mp){
            que.push({m.second,m.first});
        }
        while(k--){
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};