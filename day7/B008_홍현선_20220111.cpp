class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int mi = (lo + hi)/2;
        
        while( hi >= lo) {
            mi = (lo+hi)/2;
            
            
            if(hi != lo) {
            if(nums[mi] == target) return mi;
            else if(target < nums[mi]) hi = mi -1;
            else lo = mi +1;
        
            if(hi < lo) return mi;
            else if( lo > hi) return lo;
            }
            else {
                if(target == nums[mi]) return mi;
                else if(target < nums[mi]) return mi;
                else return mi+1;
            }
    }
        return 0;
    }
};