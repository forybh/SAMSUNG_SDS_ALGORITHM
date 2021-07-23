////
////  main.cpp
////  CUTTREE
////
////  Created by 유병헌 on 2021/07/06.
////
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int n, m, len;
//vector<int> namu;
//
//int binarySearch(int start, int end) {
//    sort(namu.begin(), namu.end());
//    len --;
//    vector<int>::iterator it = namu.begin();
//    if (start > end) return false;
//
//    int mid = (start + end) / 2;
//
//    if (namu[mid] == len) {
//        it = find(it, it+mid, len);
//        int cnt = n - (int)(it - namu.begin());
//        return cnt;
//    }else if (namu[mid] > len) {
//        return binarySearch(start, mid-1);
//    }else {
//        return binarySearch(mid+1, end);
//    }
//    return len;
//}
//
//int main(int argc, const char * argv[]) {
//    scanf("%d%d", &n, &m);
//    for(int i = 0; i < n; i ++) {
//        int tmp;
//        scanf("%d", &tmp);
//        namu.push_back(tmp);
//        if(namu[i] > len) len = namu[i];
//    }
//    while(m < 0) {
//        m -= binarySearch(0, n);
//    }
//    printf("%d", len);
//    return 0;
//}
#include <cstdio>

typedef long long LL;

int n, m;
LL tree[1000000];
LL answer;

bool cutok(LL h) {
    LL sum = 0;
    for (int i = 0 ; i < n ; i++) {
        if (tree[i] > h) {
            sum += tree[i] - h;
        }
        if (sum >= m) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        scanf("%lld", &tree[i]);
    }
    LL bottom = 0, top = 1000000000, mid;
    while (bottom <= top) {
        mid = (bottom + top) / 2;
        if (cutok(mid)) {
            if (answer < mid) answer = mid;
            bottom = mid + 1;
        }
        else {
            top = mid - 1;
        }
    }
    printf("%lld", answer);
}
