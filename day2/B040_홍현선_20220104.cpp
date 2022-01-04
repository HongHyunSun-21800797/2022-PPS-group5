#include <iostream>
#include <string>

using namespace std;

int N;
int dp[2][1000001];

int main() {

    string input;
    cin >> N >> input;;

    if(input[0] == 'A') {
        dp[0][1] = 0;
        dp[1][1] = 1;
    }
    else {
        dp[0][1] = 1;
        dp[1][1] = 0;
    }

    for(int i = 2; i <= N; i++) {
        if(input[i-1] == 'A') {
            dp[0][i] = min(dp[1][i-1]+1, dp[0][i-1]);
            dp[1][i] = min(dp[1][i-1]+1, dp[0][i-1]+1);
        }
        else {
            dp[0][i] = min(dp[0][i-1]+1, dp[1][i-1]+1);
            dp[1][i] = min(dp[1][i-1], dp[0][i-1]+1);
        }
    }

    cout << dp[0][N];

    return 0;
}