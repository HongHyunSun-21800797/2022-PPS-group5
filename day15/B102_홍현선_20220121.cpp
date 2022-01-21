class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        bool found[1001] = {false, };
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++) s.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); i++) {
            if(s.find(nums2[i]) != s.end() && !found[nums2[i]]) {
                found[nums2[i]] = true;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};