//
//  main.cpp
//  GAME
//
//  Created by 유병헌 on 2021/07/06.
//

#include <iostream>

using namespace std;
int n, m, ans, limit;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int max_count[50][50];
char board[50][51];

void dfs(int y, int x, int cnt) {
    if (ans < cnt) ans = cnt;
    if (ans > limit) return;
    if(y < 0 || n <= y || x < 0 || m <= x || board[y][x] == -1) return;
    if (cnt <= max_count[y][x]) return;
    max_count[y][x] = cnt;
    int mul = board[y][x];
    for (int i = 0; i < 4; i ++) {
        dfs(y + dy[i] * mul, x + dx[i] * mul, cnt+1);
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_count[i][j] -= 1;
        }
    }
    for (int i = 0; i < n; i ++) {
        scanf("%s", board[i]);
        for (int j = 0; j < m; j++) {
            if(board[i][j] == 'H') board[i][j] = -1;
            else board[i][j] -= '0';
        }
    }
    limit = n * m;
    dfs(0,0,0);
    if (ans > limit) ans = -1;
    printf("%d", ans);
    return 0;
}
