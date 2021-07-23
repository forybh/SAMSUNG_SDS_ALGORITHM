//
//  main.cpp
//  FINDNUMBER
//
//  Created by 유병헌 on 2021/07/05.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n;
int m;
map<int, int> mp;

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        mp.insert(make_pair(temp, 0));
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        printf("%d\n", (int)mp.count(temp));
    }
    return 0;
}
