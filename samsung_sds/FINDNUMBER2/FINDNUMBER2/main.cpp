//
//  main.cpp
//  FINDNUMBER2
//
//  Created by 유병헌 on 2021/07/06.
//

#include <iostream>
#include <vector>

using namespace std;
int n, m, sum, ans;
vector<long> a;

int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    vector<long>::iterator it;
    for (it = a.begin(); it != a.end(); it++) {
        sum += *it;
        if (sum == m) {
            ans++;
            long tmp = a.front();
            a.erase(a.begin());
            sum -= tmp;
            it --;
        }
        if ( sum > m) {
            while(sum >= m) {
                long tmp = a.front();
                a.erase(a.begin());
                sum -= tmp;
                if (sum == m) {
                    ans ++;
                }
                it --;
            }
        }
//        for (int j = i; j <n; j++) {
//            sum += a[j];
//            if (sum == m) {
//                ans ++;
//                break;
//            }
//            else if (sum > m) {
//                break;
//            }
//        }
        
    }
    printf("%d", ans);
    return 0;
}
