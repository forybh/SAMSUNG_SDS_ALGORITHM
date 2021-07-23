#include <iostream>
#include <algorithm>
using namespace std;
int n;

int stairs[302];
bool visit[302];
int dp[302];

void dpSolution(){
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    
    for(int i = 4; i <= n; i++) {
        dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i], dp[i-2] + stairs[i]);
    }
}

int solution(int i, int score) {
    int res = 0;
    if(i == n) {
        return score + stairs[n];
    }
    if(i > n) {
        return -1;
    }
    if(visit[i-1] && visit[i-2]) {
        res = max(solution(i+1, score), solution(i+2, score));
    }
    else {
        visit[i] = true;
        res = max(solution(i+1, score+stairs[i]), solution(i+2, score+stairs[i]));
        visit[i] = false;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &stairs[i]);
    }
    dpSolution();
    printf("%d", dp[n]);
    
    return 0;
}
