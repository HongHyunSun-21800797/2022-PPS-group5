class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int output = 0;
        
        for(int i = 0; i < k; i++) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        
        for(int i = 0; i < nums.size(); i++) {
            output += nums[i];
        }
        
        return output;
        
    }
};