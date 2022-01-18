class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int output;
        bool visit[10001] = {false, };
        
        for(int i = 0; i < nums.size(); i++) visit[nums[i]] = true;;
        
        for(int i = 0; i < nums.size(); i++) {
            if(!visit[i]) {
                output = i;
                break;
            }
        }
        return output;
    }
};