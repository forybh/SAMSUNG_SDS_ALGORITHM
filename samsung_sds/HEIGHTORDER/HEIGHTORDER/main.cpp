//
//  main.cpp
//  HEIGHTORDER
//
//  Created by 유병헌 on 2021/07/23.
//

#include <iostream>
#include <vector>

using namespace std;
int n, m, a, b, ans;
bool pm[501][501];

int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        pm[a][b] = true;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(pm[j][i] && pm[i][k]) pm[j][k] = true;
            }
        }
    }
    for(int i = 1; i <=n; i++) {
        int cnt = 0;
        for(int j = 1; j<=n; j++) {
            if(pm[i][j] || pm[j][i]) cnt ++;
        }
        if(cnt == n-1) ans++;
    }
    printf("%d\n", ans);
}
