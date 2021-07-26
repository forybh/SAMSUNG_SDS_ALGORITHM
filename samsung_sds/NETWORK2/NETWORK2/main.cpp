#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
//
//
//int getParent(int set[], int x) {
//    if(set[x] == x) return x;
//    return set[x] = getParent(set, set[x]);
//}
//void union_set(int x, int y, int set[]) {
//    int xp = getParent(set, x);
//    int yp = getParent(set, y);
//    if(xp == yp) return;
//    set[yp] = xp;
//}
//
//int solution(int n, vector<vector<int>> computers) {
//    int answer = 0;
////    bool visit[n];
//    int parents[n];
//    for(int i = 0; i < n; i++) {
//        parents[i] = i;
//    }
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            if(computers[i][j] == 1) {
//                if(i > j) {
//                    union_set(i, j, parents);
//                }
//                else {
//                    union_set(j, i, parents);
//                }
//            }
//        }
//    }
//    set<int> s;
//
//    for(int i = 0; i < n; i++) {
//        if(s.find(getParent(parents, i)) != s.end()) {
//            continue;
//        }
//        else {
//            s.insert(getParent(parents, i));
//            answer ++;
//        }
//    }
//    return answer;
//}
//
//
void func1(int x[]) {
    for(int i = 0; i < 10; i++) {
        x[i] = i;
    }
}
int func2() {
    int x[10];
    func1(x);
    for(int i = 0; i < 10; i ++) {
        printf("%d" ,x[i]);
    }
    return x[0];
}

int main() {
    func2();
}
