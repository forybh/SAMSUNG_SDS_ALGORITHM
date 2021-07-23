//
//  main.cpp
//  RUN
//
//  Created by 유병헌 on 2021/07/08.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int tr[1<<20];
int n;
pii player[500000];

int seg_sum(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if(l <= s && e <= r) {
        return tr[node];
    }
    else {
        return seg_sum(node * 2, s, (s + e)/ 2, l, r) + seg_sum(node * 2 + 1, (s+e) / 2 + 1 , e, l, r);
    }
    return 0;
}

void update(int node, int s, int e, int idx, int v) {
    if (idx < s || e < idx) return;
    if (s == e) {
        tr[node] = v;
    }
    else {
        update(node * 2, s, (s+e)/2, idx, v);
        update(node * 2 + 1, (s+e) / 2 + 1, e, idx, v);
        tr[node] = tr[node*2] + tr[node * 2 + 1];
    }
}

bool comp(pii p1, pii p2) {
    return p1.second < p2.second;
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i <  n; i++) {
        int power;
        scanf("%d", &power);
        player[i].first = i;
        player[i].second = power;
    }
    sort(player, player+n, comp);
    
    for (int i = 0; i < n; i++) {
        player[i].second = i+1;
    }
    sort(player, player + n);
    
    
    for (int i = 0; i < n; i++) {
        int curpower = player[i].second;
        int count = 0;
        if (curpower >= 1) {
            count = seg_sum(1, 1, n, 1, curpower -1);
        }
        update(1, 1, n, curpower, 1);
        printf("%d\n", i + 1 - count);
    }
    
    return 0;
}
