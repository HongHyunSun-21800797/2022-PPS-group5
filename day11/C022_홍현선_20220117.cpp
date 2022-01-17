#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool shieve[5001];
int output = 0;
int N;

void dfs(int nums[], int idx, int cnt, int accum) {
    if(cnt == 3) {
        if(shieve[accum]) output++;
        return;
    }
    if(idx == N) return;
    
    dfs(nums, idx+1, cnt+1, accum+nums[idx]);
    dfs(nums, idx+1, cnt, accum);
}

int solution(int nums[], size_t nums_len) {
    
    N = nums_len;
    
    for(int i = 1; i <= 5000; i++) shieve[i] = true;
    
    for(int i = 2; i <= 5000; i++) {
        if(shieve[i]) {
            for(int j = i + i; j <= 5000; j += i) shieve[j] = false;
        }
    }
    
    dfs(nums, 0, 0, 0);
    
           
    return output;
}