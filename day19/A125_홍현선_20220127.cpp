#include <iostream> // typical greedy problem
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int ans = 0;

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), greater<int>());

    for(int i = 0; i < N; i++) ans = max(ans, (i+1)*v[i]);

    cout << ans << "\n";

    return 0;
}