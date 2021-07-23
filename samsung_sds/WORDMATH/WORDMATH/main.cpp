//
//  main.cpp
//  WORDMATH
//
//  Created by 유병헌 on 2021/07/06.
//

#include <iostream>
#include <vector>

using namespace std;
int n, alpha_cnt, ans;
int mapping[10];
char word[10][10];
bool check[128];
bool used[10];
vector<char> alpha;

int toNum(char c) {
    for (int i = 0; i < alpha_cnt; i++) {
        if(alpha[i] == c) {
            return mapping[i];
        }
    }
    return 0;
}
int getNum(int k) {
    int res = 0;
    for (int i = 0; word[k][i] !=0; i++){
        int num = toNum(word[k][i]);
        res *= 10; res += num;
    }
    return res;
}
int calc() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += getNum(i);
    }
    return sum;
}
// 알파벳에 매핑할 숫자 경우를 완전탐색으로 구해보는 것
void bf(int who) {
    if ( who == alpha_cnt) {
        int tmp = calc();
        if (ans < tmp) {
            ans = tmp;
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (used[i]) continue;
        used[i] = true;
        mapping[who] = i;
        bf(who + 1);
        mapping[who] = 0;
        used[i] = false;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
            scanf("%s", word[i]);
            // 문자열 끝까지 읽는 다는 뜻(마지막 값은 0임 C++에서)
            for (int j = 0 ; word[i][j] != 0 ; j++) {
                if (!check[word[i][j]]) {
                    alpha_cnt++;
                    check[word[i][j]] = true;
                    alpha.push_back(word[i][j]);
                }
            }
        }
    bf(0);
    printf("%d", ans);
    return 0;
}
