class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) continue;
            
            nums[i] = max(nums[i], nums[i] + nums[i-1]); 
        }
        
        for(int i = 0; i < nums.size(); i++) ans = max(ans, nums[i]);
        
        return ans;
    }
}