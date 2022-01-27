#include <iostream>

using namespace std;

int N;
long long dp[100001] = {0, };

int main() {

    cin >> N;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 2;
    dp[7] = 1;

    for(int i = 8; i <= N; i++) {
        dp[i] = min(min(dp[i-1], dp[i-2]), min(dp[i-5], dp[i-7])) + 1;
    }

    cout << dp[N];


    return 0;
}