#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int W, H;
int map[51][51];
bool visit[51][51];
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
vector<int> ans;

void bfs(int h, int w) {
    queue<pair<int, int> > q;

    visit[h][w] = true;
    map[h][w] = 0;
    q.push(make_pair(h, w));

    while(!q.empty()) {
        h = q.front().first;
        w = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int next_h = h + dy[i];
            int next_w = w + dx[i];

            if(next_h > H || next_h < 1 || next_w > W || next_w < 1 || visit[next_h][next_w]) continue;

            visit[next_h][next_w] = true;
             
             if(map[next_h][next_w] == 1) {
                 map[next_h][next_w] = 0;
                 q.push(make_pair(next_h, next_w));
             }
        }
    }
}  

int main() {

    while(true) {
        cin >> W >> H;
        if(W == 0 || H == 0) break;

        for(int h = 1; h <= H; h++) {
            for(int w = 1; w <= W; w++) {
                cin >> map[h][w];
                visit[h][w] = false;
            }
        }

        int result = 0;
        
       for(int h = 1; h <= H; h++) {
            for(int w = 1; w <= W; w++) {
                if(map[h][w] == 1) {
                    result++;
                    bfs(h, w);
                }
            }
        }
        ans.push_back(result);
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}