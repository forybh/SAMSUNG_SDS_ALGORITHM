//
//  main.cpp
//  BINARYSEARCHTREE
//
//  Created by 유병헌 on 2021/07/07.
//

#include <iostream>

using namespace std;

int tree[10000];

void recur(int start, int end) {
    if (start == end) {
        printf("%d\n", tree[start]);
        return;
    }
    
    else if (start > end) {
        return;
    }
    else {
        int where = start + 1;
        while (where <= end) {
            if (tree[where] > tree[start]) break;
            else where++;
        }
        recur(start+1, where -1);
        recur(where, end);
        printf("%d\n", tree[start]);
    }
}
int main(int argc, const char * argv[]) {
    freopen("./File.strings", "r", stdin);
    int i = 0;
    while(scanf("%d", &tree[i])!=-1) {
        i++;
    };
    recur(0, i-1);
    return 0;
}
