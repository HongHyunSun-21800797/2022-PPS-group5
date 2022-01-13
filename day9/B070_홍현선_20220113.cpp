class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001] = {0, };
        dp[1] = cost[0];
        dp[2] = cost[1];
        
        for(int i = 3; i <= cost.size(); i++) {
            dp[i] = cost[i-1] + min(dp[i-1], dp[i-2]);
        }
        
        return min(dp[cost.size()], dp[cost.size()-1]);
    }
};