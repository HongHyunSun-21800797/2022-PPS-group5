#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long dp[2][2001] = {0, };
    dp[0][1] = 1, dp[1][1] = 0, dp[0][2] = 1, dp[1][2] = 1;
    
    for(int k = 3; k <= n; k++) {
        dp[0][k] = (dp[0][k-1] + dp[1][k-1])%1234567;
        dp[1][k] = (dp[0][k-2] + dp[1][k-2])%1234567;
    }
    
    answer = (dp[0][n] + dp[1][n])%1234567;
    
    return answer;
}