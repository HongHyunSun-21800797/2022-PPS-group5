#include <iostream>
#include <queue>

using namespace std;

int stones[100001];
int n;
int curr;
int output = 0;
bool visit[100001];

void bfs() {
    visit[curr] = true;
    output++;
    queue<int> q;
    q.push(curr);

    while(!q.empty()) {
        curr = q.front();
        q.pop();

        if(curr-stones[curr] >= 1 && !visit[curr-stones[curr]]) {
            visit[curr-stones[curr]] = true;
            output++;
            q.push(curr-stones[curr]);
        }
        if(curr+stones[curr] <= n && !visit[curr+stones[curr]]) {
            visit[curr+stones[curr]] = true;
            output++;
            q.push(curr+stones[curr]);
        } 
    }
}

int main() {

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> stones[i];
    cin >> curr;

    bfs();

    cout << output;

    return 0;
}