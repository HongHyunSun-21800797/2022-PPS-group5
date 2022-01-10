#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int curr = 0;
int output = 0;
vector<pair<int, int > > v;

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        int b;

        cin >> a >> b;

        v.push_back(make_pair(b, a));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        int sp = v[i].second;
        int ep = v[i].first;

        if(curr <= sp) {
            output++;
            curr = ep;
        }
    }
    
    cout << output << "\n";

    return 0;
}