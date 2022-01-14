class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int output = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 1; i += 2) output += nums[i];
        
        return output;
    }
};