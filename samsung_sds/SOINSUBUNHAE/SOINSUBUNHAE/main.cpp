//
//  main.cpp
//  SOINSUBUNHAE
//
//  Created by 유병헌 on 2021/07/08.
//

#include <iostream>
#include <vector>
using namespace std;
bool che[3200];
vector<int> prime;
int n;

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 2; i < 3200; i++) {
        if(che[i]) continue;
        for (int j = i + i; j < 3200; j += i) {
            che[j] = true;
        }
    }
    for (int i = 2; i < 3200; i ++) {
        if(!che[i]) {
            prime.push_back(i);
        }
    }
    if (n == 1) {
        return 0;
    }
    for (int i = 0; i < prime.size(); i++) {
        while( n % prime[i] == 0) {
            printf("%d\n", prime[i]);
            n /= prime[i];
        }
    }
    if (n > 1) {
        printf("%d\n", n);
    }
    return 0;
}
