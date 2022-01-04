#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool Reserve[31] = {false, };
    bool Lost[31] = {false, };
    
    for(auto l:lost) Lost[l] = true;
    for(auto r:reserve) Reserve[r] = true;
    
    for(int i = 1; i <= n; i++) {
        if(Lost[i] && Reserve[i]) {
            Lost[i] = false;
            Reserve[i] = false;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(!Lost[i]) answer++;
        else {
            if(i-1 >= 1 && Reserve[i-1]) answer++;
            else if(i+1 <= n && Reserve[i+1]) {
                answer++;
                Reserve[i+1] = false;
            }
        }
    }
    
    return answer;
}