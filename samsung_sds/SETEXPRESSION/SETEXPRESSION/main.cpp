//
//  main.cpp
//  SETEXPRESSION
//
//  Created by 유병헌 on 2021/07/21.
//

#include <iostream>

using namespace std;

int n, m, op, a, b;
int group[1000001];


int findGroup(int x) {
    if(group[x] == -1) {
        return x;
    }
    else {
        group[x] =findGroup(group[x]);
        return group[x];
    }
}

void unionGroup(int x, int y) {
    int gx = findGroup(x);
    int gy = findGroup(y);
    if(gx == gy) {
        return;
    }
    else {
        group[gy] = gx;
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++) {
        group[i] = -1;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &op, &a, &b);
        if(op == 0) {
            unionGroup(a, b);
        }
        else {
            if (findGroup(a) == findGroup(b)) {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
    return 0;
}
