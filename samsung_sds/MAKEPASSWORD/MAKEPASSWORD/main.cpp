//
//  main.cpp
//  MAKEPASSWORD
//
//  Created by 유병헌 on 2021/07/15.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l, c;
char alphabet[16];
vector<vector<char>> ans;


void recur(int index, int size, vector<char> v) {
    if(size == 0) {
        int a = 0, b = 0;
        bool flag = false;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == 'a' || v[i] == 'o' || v[i] == 'e' || v[i] == 'i' || v[i] == 'u') a++;
            else b++;
            if( a>= 1 && b >= 2) {
                flag = true;
                break;
            }
        }
        if(flag) ans.push_back(v);
        return;
    }

    for(int i = index; i < c - size + 1; i++) {
        v.push_back(alphabet[i]);
        recur(i + 1, size -1, v);
        v.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d%d", &l, &c);
    
    for(int i = 0; i < c; i++) {
        scanf(" %c", &alphabet[i]);
    }
    
    sort(alphabet, alphabet + c);
    
    vector<char> v;
    recur(0, l, v);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
