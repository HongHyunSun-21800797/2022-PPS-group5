class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int output = max(nums[0], nums[1]);
        int dp[101] = {0, };
        dp[1] = nums[0];
        dp[2] = nums[1];
        
        for(int i = 3; i <= nums.size(); i++) {
            dp[i] = nums[i-1] + max(dp[i-2], dp[i-3]);
            if(dp[i] > output) output = dp[i];
        }
        
        return output;
    }
};