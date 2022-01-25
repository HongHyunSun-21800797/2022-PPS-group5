class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        bool visit[100001] = {false, };
        int n = nums.size();
        
        for(int i = 0; i < n; i++) visit[nums[i]] = true;
        for(int i = 1; i <= n; i++) {
            if(!visit[i]) ans.push_back(i);
        }
        
        return ans;
    }
};