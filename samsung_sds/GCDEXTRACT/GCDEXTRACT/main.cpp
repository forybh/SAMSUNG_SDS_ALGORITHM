//
//  main.cpp
//  GCDEXTRACT
//
//  Created by 유병헌 on 2021/07/08.
//

#include <iostream>

typedef long long LL;
int n;
LL number[1000002];
LL leftGcd[1000002], rightGcd[1000002];
LL answer, who;
LL gcd(LL a, LL b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &number[i]);
    }
    for(int i = 1; i <= n; i++) {
        leftGcd[i] = gcd(leftGcd[i-1], number[i]);
    }
    for(int i = n; i >= 1; i--) {
        rightGcd[i] = gcd(rightGcd[i+1], number[i]);
    }
    answer = -1;
    for (int i = 1; i <= n; i++) {
        LL curGcd = gcd(leftGcd[i-1], rightGcd[i+1]);
        if (number[i] %curGcd == 0) continue;
        if( answer < curGcd) {
            answer = curGcd;
            who = number[i];
        }
    }
    if (answer == -1) {
        printf("%lld", answer);
    }
    else {
        printf("%lld %lld", answer, who);
    }
    return 0;
}
