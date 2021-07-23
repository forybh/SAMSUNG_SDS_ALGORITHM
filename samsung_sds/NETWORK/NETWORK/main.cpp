#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int n, m, a, b, c, answer;

vector<pair<int, pii>> v;

int parent[10001];
int cost[10001];

int findParent(int child) {
    if(parent[child] == 0) {
        return child;
    }
    return parent[child] = findParent(parent[child]);
}

int unionSet(pair<int, pii> xy) {
    int xp = findParent(xy.second.first);
    int yp = findParent(xy.second.second);
    
    if(xp == yp) return xp;
    else {
        cost[xp] += cost[yp] + xy.first;
        parent[yp] = xp;
    }
    return xp;
}


int main(int argc, const char * argv[]) {
    scanf("%d", &n);scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        v.push_back(pair<int, pii>(c, pii(a,b)));
    }
    int p = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        p = unionSet(v[i]);
    }
    answer = cost[p];
    printf("%d", answer);
    
    return 0;
}
