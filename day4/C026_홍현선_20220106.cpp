#include <iostream>
#include <string>   // brute force, there is no greedy algorithm.

using namespace std;

string N;
int M;
int output;
int hi = 1;
int lo = 0;
bool broken[10] = {false, };

bool possible(string n) {
    for(int i = 0; i < n.size(); i++) {
        if(broken[n[i]-'0']) return false;
    }
    return true;
}

int main() {

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int input;
        cin >> input;
        broken[input] = true;
    }

    output = abs(100 - stoi(N));

    for(int i = 0; i <= 1000000; i++) {
        if(possible(to_string(i))) {
            output = min(output, int(to_string(i).size() + abs(i-stoi(N))));
        }
    }

    cout << output << "\n"; 

    return 0;
}