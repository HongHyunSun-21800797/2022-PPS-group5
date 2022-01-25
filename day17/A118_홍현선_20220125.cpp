class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool found = false;
        
        for(int i = 0; i < nums.size(); i++) {
            found = false;
            
            for(int j = 0; j < nums.size() - 1 - i; j++) {
                if(nums[j] == 0) {
                    swap(nums[j], nums[j+1]);
                    found = true;
                }
            }
            
            if(!found) break;
        }
        
    }
};