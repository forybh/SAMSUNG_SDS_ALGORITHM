//
//  main.cpp
//  GAME2
//
//  Created by 유병헌 on 2021/07/07.
//

#include <iostream>

using namespace std;

long x, y, z;

int main(int argc, const char * argv[]) {
    scanf("%ld%ld", &x, &y);
    z = y*100 / x;
    if (x == y || z == 99) {
        printf("-1");
        return 0;
    }
    long start = 0;
    long end = x;
    long mid;
    long answer = x;
    while(start <= end) {
        mid = (start + end) / 2;
        long nextZ = (y + mid) * 100 / (x + mid);
        if (nextZ > z) {
            if (mid < answer) {
                answer = mid;
            }
            end = mid -1;
        }
        else {
            start = mid + 1;
        }
    }
    
    printf("%ld", answer);
    return 0;
}
