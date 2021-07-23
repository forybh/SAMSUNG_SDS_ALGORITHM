//
//  main.cpp
//  GAEDDONGBULRE
//
//  Created by 유병헌 on 2021/07/08.
//

#include <iostream>
int n, h, answer, count;
int sum[500010];

int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &h);
    for(int i = 0; i < n; i++) {
        int bar;
        scanf("%d", &bar);
        if(i &1) {
            sum[h-bar+1]++;
        }
        else{
            sum[1] ++;
            sum[bar + 1] --;
        }
    }
    answer = -1;
    for (int i = 1; i <= h; i ++) {
        sum[i] += sum[i-1];
        if (answer == -1 || sum[i] < answer) {
            answer = sum[i];
            count = 1;
        }
        else if (sum[i] == answer) {
            count++;
        }
    }
    printf("%d %d", answer, count);
    return 0;
}
