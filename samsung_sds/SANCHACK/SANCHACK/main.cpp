//
//  main.cpp
//  SANCHACK
//
//  Created by 유병헌 on 2021/07/09.
//

#include <iostream>
int h, w, n;
int hw[10][10];
int main(int argc, const char * argv[]) {
    scanf("%d%d%d", &h, &w, &n);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            scanf("%d", &hw[i][j]);
        }
    }

    
    return 0;
}
