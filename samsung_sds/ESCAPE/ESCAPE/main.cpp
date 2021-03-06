//
//  main.cpp
//  ESCAPE
//
//  Created by 유병헌 on 2021/07/05.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
int r, c;
char forest[50][51];
queue<pii> water_q;
queue<pii> ddg_q;
pii ddg;
pii biber;
vector<pii> water;
int water_vt[50][50] = {0,}, ddg_vt[50][50] = {0,};
int dr[] = {-1,1,0,0}, dc[] = {0, 0, -1, 1};
int ans;

bool check_rc(int param_r, int param_c){
    return 0 <= param_r && param_r < r && 0 <= param_c && param_c < c;
    
    
}

int main(int argc, const char * argv[]) {
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> forest[i];
    }
    
//    for(int i = 0; i< R; i++) {
//        for(int j = 0; j < R; j++) {
//            if(forest[i][j] == 'S') {
//                ddg = pii(i, j);
//            }
//            if(forest[i][j] == '*') {
//                water.push_back(pii(i,j));
//            }
//            if(forest[i][j] == 'D') {
//                bib = pii(i,j);
//            }
//        }
//    }
//
//
//    for(int i = 0; i < water.size(); i++) {
//        pii cur_water = water[i];
//        water_q.push(cur_water);
//        water_visited[cur_water.first][cur_water.second] = 1;
//    }
//    ddg_q.push(ddg);
//    ddg_visited[ddg.first][ddg.second] = 1;
//
//    while (!ddg_q.empty()) {
//        cout << "ddg queue : " << ddg_q.front().first << " " << ddg_q.back().second;
//        int water_qsz = (int)water_q.size();
//        for(int i = 0; i < water_qsz; i++) {
//            pii cur_water = water_q.front();
//            water_q.pop();
//            for(int j = 0; j < 4; j++) {
//                int new_r, new_c;
//                new_r = cur_water.first + dr[j];
//                new_c = cur_water.second + dc[j];
//                if (!check_rc(new_r, new_c)) continue;
//                if(forest[new_r][new_c] == 'D' || forest[new_r][new_c] == 'X' || water_visited[new_r][new_c] != 0) continue;;
//                water_visited[new_r][new_c] = water_visited[cur_water.first][cur_water.second] + 1;
//                water_q.push(pii(new_r,new_c));
//            }
//        }
//
//        int ddg_qsz = (int)ddg_q.size();
//        for(int i = 0; i < ddg_qsz; i++) {
//            pii cur_ddg = ddg_q.front();
//            ddg_q.pop();
//            for(int j = 0; j < 4; j++) {
//                int new_r, new_c;
//                new_r = cur_ddg.first + dr[j];
//                new_c = cur_ddg.second + dc[j];
//                if (!check_rc(new_r, new_c)) continue;
//                if(forest[new_r][new_c] == 'X' || water_visited[new_r][new_c] != 0) continue;;
//                if(forest[new_r][new_c] == 'D') {
//                    int answer = ddg_visited[cur_ddg.first][cur_ddg.second] + 1;
//                    answer --;
//                    cout << answer;
//                    return 0;
//                }
//                else {
//                    ddg_visited[new_r][new_c] = ddg_visited[cur_ddg.first][cur_ddg.second] + 1;
//                    ddg_q.push(pii(new_r,new_c));
//                }
//            }
//        }
//    }
    for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                if (forest[i][j] == 'S') {
                    ddg = pii(i, j);
                    // 어짜피 S는 하나일테니까. 필요하면 중단하는것을 넣어도 됨
                }
                if (forest[i][j] == '*') {
                    water.push_back(pii(i, j));
                }
                if (forest[i][j] == 'D') {
                    biber = pii(i, j);
                }
            }
        }

        // 물
        for (int i = 0 ; i < water.size() ; i++) {
            pii cur_water = water[i];
            water_q.push(cur_water);
            water_vt[cur_water.first][cur_water.second] = 1;
        }

        // 두더 지
        ddg_q.push(ddg);
        ddg_vt[ddg.first][ddg.second] = 1;

        // 물과 두더지를 탐색하면서 갈수 있는지 없는지 판단
        // 두더지가 비버의 굴을 탐색하면 거리를 출력하고 끝
        // 두더지가 더이상 탐색을 못하면 KAKTUS를  출력하고 끝
        while (!ddg_q.empty()) {
            // 물 이동
            // q에서 하나를 꺼내고 상/하/좌/우로 이동
            // 비버의 목적지는 가지말고
            // 돌멩이도 가지 말고
            // 두더지??? 가도됨
            int water_qsz = water_q.size();
            for (int i = 0 ; i < water_qsz ; i++) { // 현재에 q에 있었던 만큼만 탐색을 할꺼다...
                pii cur_water = water_q.front();
                water_q.pop();
                for (int j = 0 ; j < 4 ; j++) { // 상/하/좌/우 순서대로 좌표를 얻는다
                    int new_r, new_c;
                    new_r = cur_water.first + dr[j];
                    new_c = cur_water.second + dc[j];
                    if (!check_rc(new_r, new_c)) continue;
                    if (forest[new_r][new_c] == 'D' || forest[new_r][new_c] == 'X' || water_vt[new_r][new_c] != 0) continue;
                    water_vt[new_r][new_c] = water_vt[cur_water.first][cur_water.second] + 1;
                    water_q.push(pii(new_r, new_c));
                }
            }

            // 두더지 이동
            // queue에서 하나를 꺼내고 상/하/좌/우로 이동
            // 물은 가지 말고
            // 돌멩이도 가지말고
            // 목적지였으면?? 찾은것
            int ddg_qsz = ddg_q.size();
            for (int i = 0 ; i < ddg_qsz ; i++) {
                pii cur_ddg = ddg_q.front();
                ddg_q.pop();
                for (int j = 0 ; j < 4 ; j++) {
                    int new_r, new_c;
                    new_r = cur_ddg.first + dr[j];
                    new_c = cur_ddg.second + dc[j];
                    if (!check_rc(new_r, new_c)) continue;
                    if (forest[new_r][new_c] == 'X' || water_vt[new_r][new_c] != 0) continue;

                    if (forest[new_r][new_c] == 'D') {
                        // 찾았다
                        ans = ddg_vt[cur_ddg.first][cur_ddg.second] + 1;
                        ans--;  // 왜냐면 처음 시작을 1로 했으니까.....
                        printf("%d", ans);
                        return 0;
                    }
                    else {
                        if (ddg_vt[new_r][new_c] != 0) {
                            continue;
                        }
                        ddg_vt[new_r][new_c] = ddg_vt[cur_ddg.first][cur_ddg.second] + 1;
                        ddg_q.push(pii(new_r, new_c));
                    }
                }
            }

        }
    cout << "KAKTUS";
    return 0;
}
