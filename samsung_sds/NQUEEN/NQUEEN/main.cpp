//
//  main.cpp
//  NQUEEN
//
//  Created by 유병헌 on 2021/07/06.
//

#include <iostream>

using namespace std;
int n ,ans;
int chess[14][14] = {};
void recur(int line) {
    //종료 조건
    if (line == n) {
        ans ++;
        return;
    }
    for (int i = 0; i < n; i ++) {
        if (chess[line][i] != -1) continue;
        chess[line][i] = line;
        for (int j = line, num = 0; j < n; j++ ,num++){
            if(chess[j][i] == -1) chess[j][i] = line;
            if(i + num < n) {
                if(chess[j][i+num] == -1) chess[j][i+num] = line;
            }
            if(i - num >= 0) {
                if(chess[j][i-num] == -1) chess[j][i-num] = line;
            }
        }
        recur(line + 1);
        for(int x = line, num = 0; x < n; x++, num++) {
            if(chess[x][i] == line) chess[x][i] = -1;
            if (i + num < n) {
                if(chess[x][i+num] == line) chess[x][i+num] = -1;
            }
            if (i - num >= 0) {
                if(chess[x][i-num] == line) chess[x][i-num] = -1;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    for(int i = 0; i < 14; i++) {
        for(int j = 0; j < 14; j++) {
            chess[i][j] = -1;
        }
    }
    scanf("%d", &n);
    recur(0);
    printf("%d", ans);
    return 0;
}
