//
//  main.cpp
//  FINDMID
//
//  Created by 유병헌 on 2021/07/07.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;
int n;
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int a;

        scanf("%d", &a);
        if (min_pq.size() == max_pq.size()) {
            max_pq.push(a);
        }
        else {
            min_pq.push(a);
        }
        if (!min_pq.empty() && !max_pq.empty() && min_pq.top() < max_pq.top()) {
            int min_value = min_pq.top();
            min_pq.pop();
            int max_value = max_pq.top();
            max_pq.pop();
            max_pq.push(min_value);
            min_pq.push(max_value);
            
        }
        printf("%d\n", max_pq.top());
    }
    return 0;
}
