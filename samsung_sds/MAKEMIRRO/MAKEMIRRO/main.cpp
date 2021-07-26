#include <iostream>
using namespace std;

int n;
char miro[51][51];
int ans[51][51];
bool check_go(int y, int x) {
    if(miro[y][x+1] == '0' && miro[y+1][x] == '0') {
        printf("can't go : %d %d", y, x);
        return false;
    }
    return true;
}

void bfs(int y, int x, int cnt) {
    if (x >= n || y >= n) return;
    if(ans[y][x] != 0 && ans[y][x] <= cnt) return;
    ans[y][x] = cnt;
    if (x == n-1 && y == n-1) return;
    if(check_go(y, x)) {//갈 수 있을 때
        if(miro[y+1][x] == '0') {
            bfs(y, x+1, cnt);
        }
        else if(miro[y][x+1] == '0') {
            bfs(y+1, x, cnt);
        }
        else {
            bfs(y, x+1, cnt);
            bfs(y+1, x, cnt);
        }
    }
    else {
        //못갈때
        miro[y+1][x] = '1';
        bfs(y+1, x, cnt+1);
        miro[y+1][x] = '0';
        miro[y][x+1] = '1';
        bfs(y, x+1, cnt+1);
        miro[y][x+1] = '0';
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", miro[i]);
    }
    bfs(0,0,0);

    printf("%d", ans[n][n]);
    return 0;
}
