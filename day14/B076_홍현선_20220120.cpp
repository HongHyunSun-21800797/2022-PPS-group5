#include <iostream>

using namespace std;

int n;
int dp[2][1001] = {0, };
int ans = 0;

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> dp[0][i];
        dp[1][i] = dp[0][i];

        for(int j = 1; j < i; j++) {
            if(dp[0][j] > dp[0][i] && dp[1][j] + dp[0][i] > dp[1][i]) {
                dp[1][i] = dp[1][j] + dp[0][i];
            }
        }
        ans = max(ans, dp[1][i]);
    }

    cout << ans;

    return 0;
}