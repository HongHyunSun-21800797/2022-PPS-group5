class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size() - 1;
        int ans = (hi-lo)*min(height[lo], height[hi]);
        
        while(lo != hi) {
            if(height[lo] <= height[hi]) lo++;
            else hi--;
            
            ans = max(ans, (hi-lo)*min(height[lo], height[hi]));
        }
        
        return ans;
    }
};