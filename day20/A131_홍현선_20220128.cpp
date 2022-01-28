#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t;
    vector<int> ans;
    cin >> t;

    while(t--) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long long dx = x1-x2;
        long long dy = y1-y2;

        if(r1 > r2) swap(r1, r2);
        long long add = r1 + r2;
        long long sub = r2 - r1;
        add = add * add;
        sub = sub * sub;
        long long d = dx*dx + dy*dy;

        if(d < add && d > sub) ans.push_back(2);
        else if(d == add || (d == sub && d != 0)) ans.push_back(1);
        else if(d < sub || d > add) ans.push_back(0);
        else if(d == 0) {
            if(r1 == r2) ans.push_back(-1);
            else cout << 0;
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}