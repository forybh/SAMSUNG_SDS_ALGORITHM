//
//  main.cpp
//  EXCHANGE
//
//  Created by 유병헌 on 2021/07/05.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int tonum(char arr[]) {
    int res = 0;
    for (int i = 0; arr[i]; i++) {
        res *= 10;
        res += arr[i] - '0';
    }
    return  res;
}

int conv(int num, int l, int r) {
    // l과 r 이 범위에 맞는지 체크
    // 처음에 num의 자리수 이용
    char buf[16];
    sprintf(buf, "%d", num);
    char tmp;
    tmp = buf[l];
    buf[l] = buf[r];
    buf[r] = tmp;
    //앞자리가 0이 아닌지 체크
    if (buf[0] == '0') return 0;
    return tonum(buf);
}


bool isok(int num){
    if (num < 10) return false;
    if (num < 100 && num % 10 == 0) return false;
    return true;
}

int get_num_len(int num) {
    int len = 0;
    while (num > 0) {
        len ++;
        num /= 10;
    }
    return len;
}

int n, k;

int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &k);
    if (n == 1000000) {
        printf("1000000");
        return 0;
    }
    if(!isok(n)) {
        printf("-1");
        return 0;
    }
    queue<int> q;
    q.push(n);
    
    for(int i = 0; i < k; i++) {
        vector<int> next_q;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            int len = get_num_len(cur);
            for (int s = 0; s< len; s++) {
                for (int e = s + 1; e < len; e++) {
                    int next_num = conv(cur, s, e);
                    if (next_num == 0) continue;
                    next_q.push_back(next_num);
                }
            }
            
        }
        sort(next_q.begin(), next_q.end());
        next_q.erase(unique(next_q.begin(), next_q.end()), next_q.end());
        for (int i =0; i < next_q.size(); i++) {
            q.push(next_q[i]);
        }
    }
    
    int ans = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (ans < cur) ans = cur;
    }
    printf("%d", ans);
    
    return 0;
}
