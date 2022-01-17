#include <iostream>
#include <string>

using namespace std;

int N;

bool possible(int n) {
    string s = to_string(n);
    int accum = 0;

    for(int i = 0; i < s.size(); i++) accum += s[i] - '0';
    accum += n;

    if(accum == N) return true;

    return false;
}

int main() {

    int output;
    cin >> N;

    for(int i = 1; i <= 1000000; i++) {
        if(possible(i)) {
            output = i;
            break;
        }
    }

    cout << output;
    

    return 0;
}