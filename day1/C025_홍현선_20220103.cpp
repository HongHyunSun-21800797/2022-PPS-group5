#include <string>
#include <vector>

using namespace std;

bool squreNumber[1001] = {false, };

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = 1; i*i <= 1000; i++) squreNumber[i*i] = true;
    
    for(int i = left; i <= right; i++) {
        if(squreNumber[i]) answer -= i;
        else answer += i;
    }
    
    return answer;
}