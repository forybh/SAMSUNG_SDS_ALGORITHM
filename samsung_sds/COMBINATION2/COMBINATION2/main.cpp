//
//  main.cpp
//  COMBINATION2
//
//  Created by 유병헌 on 2021/07/09.
//

#include <iostream>

int n, k;
int cache[1001][1001];
int nCr(int n, int r) {
    if (r == 0) {
        cache[n][r] = 1;
    }
    if (n < r) {
        cache[n][r] = 0;
    }
    if (n < 0 || 1000 < n || r < 0 || 1000 < r) return 0;
    
    if(cache[n][r] != -1) return cache[n][r];
    
    int tmp = (nCr(n-1, r-1) + nCr(n-1, r))% 10007;
    cache[n][r] = tmp;
    return cache[n][r];
}
int main(int argc, const char * argv[]) {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            cache[i][j] = -1;
        }
    }
    scanf("%d%d", &n, &k);
    printf("%d", nCr(n,k));
    return 0;
}
