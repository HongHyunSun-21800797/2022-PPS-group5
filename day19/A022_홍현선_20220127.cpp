#include <iostream>

using namespace std;

int N;
int input;
int Y = 0; // 30 seconds per 10 won
int M = 0; // 60 seconds per 15 won

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        
        cin >> input;
        Y += (input/30 + 1)*10;
        M += (input/60 + 1)*15;
    }

    if(Y < M) cout << "Y" << " " << Y;
    else if (Y > M) cout << "M" << " " << M;
    else cout << "Y M " << Y;

    return 0;
}