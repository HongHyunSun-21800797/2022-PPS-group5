#include <iostream>

using namespace std;

int N;
int S;
int arr[100001];
int INF = 987654321;

int main() {
    int lo;
    int hi;
    int curr; // current part sum
    int result = INF; // length of part sum

    cin >> N >> S;

    for(int i = 1; i <= N; i++) cin >> arr[i];
    
    curr = arr[1];
    lo = 1;
    hi = 1;

    while(lo <= hi && hi <= N) {
        if(curr >= S && hi - lo + 1 < result) result = hi - lo + 1;

        if(curr >= S) curr -= arr[lo++];
        else curr += arr[++hi];
    }

    if(result === INF) cout << "0";
    else cout << result;

    return 0;
}