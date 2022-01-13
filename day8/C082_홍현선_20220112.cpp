class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        priority_queue<pair<int, int>> pq;
        vector<int> output;
        
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            }
            else m[nums[i]]++;
        }
        
        for(auto iter = m.begin(); iter != m.end(); iter++) {
            pq.push(make_pair(iter->second, iter->first));
        }
        
        for(int i = 0; i < k; i++) {
            output.push_back(pq.top().second);
            pq.pop();
        }
        
        return output;
    }
};