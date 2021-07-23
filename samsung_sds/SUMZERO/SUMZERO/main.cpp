//
//  main.cpp
//  SUMZERO
//
//  Created by 유병헌 on 2021/07/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a, b, c, d;
vector<int> ab;
vector<int> cd;
typedef long long ll;


int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
        scanf("%d", &temp);
        b.push_back(temp);
        scanf("%d", &temp);
        c.push_back(temp);
        scanf("%d", &temp);
        d.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    ll answer = 0;
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int index = (int)ab.size() - 1;
    ll cnt = 0;
    for (int i = 0; i < ab.size(); i++) {
        int target = -ab[i];
        if(0 < i && ab[i] == ab[i-1]) {
            answer += cnt;
        }
        else {
            while(0 < index && target < cd[index]) {
                index--;
            }
            cnt = 0;
            while (0 <= index && target == cd[index]) {
                cnt++;
                index--;
            }
            answer += cnt;
        }
    }
    printf("%lld", answer);
   
    return 0;
}
