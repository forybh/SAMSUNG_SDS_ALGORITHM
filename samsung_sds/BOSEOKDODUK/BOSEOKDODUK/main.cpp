//
//  main.cpp
//  BOSEOKDODUK
//
//  Created by 유병헌 on 2021/07/08.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> p;
typedef long long ll;
p boseok[1000000];
int n ,k;
int gabang[300000];
ll answer;
int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        int m;
        int v;
        scanf("%d%d", &m, &v);
        boseok[i] = p(m, v);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &gabang[i]);
    }
    sort(boseok, boseok+n);
    sort(gabang, gabang+k);
    int posBoseok = 0;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        int cur = gabang[i];
            while(posBoseok < n && boseok[posBoseok].first <= cur) {
                pq.push(boseok[posBoseok].second);
                posBoseok++;
            }

            if (!pq.empty()) {
                answer += pq.top();
                pq.pop();
        }
    }
    printf("%lld", answer);
    
    return 0;
}
