//
//  main.cpp
//  POST
//
//  Created by 유병헌 on 2021/07/07.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, h[50][50], dy[] = {-1, 1, 0, 0, 1, -1, -1, 1, 1}, dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int cnt_k, y_post, x_post;
char vil[50][51];
vector<int> hhh;
typedef pair<int, int> pii;
int bfs(int low, int high) {
    int cnt = 0;
    bool vt[50][50] = {false, };
    queue<pii> q;
    q.push(pii(y_post, x_post));
    vt[y_post][x_post] = true;
    if(h[y_post][x_post] < low || high < h[y_post][x_post]) return cnt;
    while (!q.empty() && cnt < cnt_k) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i ++) {
            int nextY = cur.first + dy[i];
            int nextX = cur.second + dx[i];
            if(nextY<0 || n <= nextY || nextX <0 || n <= nextX) continue;
            if (vt[nextY][nextX]) continue;
            if (h[nextY][nextX] < low || high < h[nextY][nextX]) continue;
            if (vil[nextY][nextX] == 'K') {
                cnt++;
            }
            vt[nextY][nextX] = true;
            q.push(pii(nextY, nextX));
        }
    }
    return cnt;
}


int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%s", vil[i]);
    }
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(vil[i][j] == 'K') {
                cnt_k++;
            }
            else if(vil[i][j] == 'P') {
                y_post = i;
                x_post = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            scanf("%d", &h[i][j]);
            hhh.push_back(h[i][j]);
        }
    }
    //낮은 높이, 높은 높이를 임의로 정해서 모든 집에 배달 할 수 있는지 확인
    sort(hhh.begin(), hhh.end());
    int answer = hhh.back() - hhh[0];
    for (int low =0, high = 0; low < hhh.size() && high < hhh.size() && low <= high;) {
        if (bfs(hhh[low], hhh[high]) == cnt_k) {
            int tmp = hhh[high] - hhh[low];
            if (tmp < answer) {
                answer = tmp;
            }
            low++;
        }
        else {
            high++;
        }
    }
    printf("%d", answer);
    
    return 0;
}
