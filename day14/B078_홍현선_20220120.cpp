class Solution {
public:
    int getMaximumGenerated(int n) {
        int dp[101] = {0, };
        dp[0] = 0;
        dp[1] = 1;
        int Max = 0;
        
        for(int i = 1; i <= n; i++) {
            if(i%2 == 0) dp[i] = dp[i/2];
            else dp[i] = dp[(i-1)/2] + dp[(i-1)/2+1];
        }
        
        for(int i = 1; i <= n; i++) {
            if(Max < dp[i]) Max = dp[i];
        }
        
        return Max;
    }
};