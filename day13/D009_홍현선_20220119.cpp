#include <iostream>

using namespace std;

int dp[501][501];
int map[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;
int ans = 0;

bool possible(int r, int c) {
    if(r < 1 || r > n) return false;
    if(c < 1 || c > n) return false;
    
    return true;
}

int dfs(int r, int c) {

    if(dp[r][c] == -1) {
        dp[r][c] = 1;
        int best = 0;

        for(int i = 0; i < 4; i++) {
            int next_r = r + dx[i];
            int next_c = c + dy[i];

            if(possible(next_r, next_c) && map[next_r][next_c] > map[r][c]) {
                best = max(best, dfs(next_r, next_c));
            }
        }
        dp[r][c] += best;
    }

    return dp[r][c];
}

int main() {

    cin >> n;

    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= n; c++) {
            cin >> map[r][c];
            dp[r][c] = -1;
        }
    }

    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= n; c++) {
            ans = max(ans, dfs(r, c));
        }
    }

    cout << ans << "\n";

    return 0;
}