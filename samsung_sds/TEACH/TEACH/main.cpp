//
//  main.cpp
//  TEACH
//
//  Created by 유병헌 on 2021/07/12.
// wx y z

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n, k, ans;
char words[50][16];
bool visit[26] = {false, };
bool alph[26] = {false, };
vector<char> alpha;

int canRead() {
    int cnt = 0;
//    for(int i = 0; i < 26; i++) {
//        if(visit[i]) printf("%c ", i + 'a');
//    }
//    printf("\n\n");
    for(int j = 0; j < n; j++) {
        bool res = true;
        for(int i = 4; i < strlen(words[j])-4; i++) {
            if(visit[words[j][i] - 'a']) continue;
            else {
                res = false;
                break;
            }
        }
        if(res) {
            cnt ++;
        }
    }
    return cnt;
}
void chooseAlpha(int size, int index) {
    if (size == 0) {
        int res = canRead();
        if(res > ans) {
            
            ans = res;
        }
        return;
    }
    for(int i = index; i < alpha.size() - size + 1; i++) {
        if(visit[alpha[i] - 'a']) continue;
        else {
            visit[alpha[i] - 'a'] = true;
            chooseAlpha(size - 1, i+1);
            visit[alpha[i] - 'a'] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    freopen("File.strings", "r", stdin);
    visit['a'-'a'] = true;
    visit['c'-'a'] = true;
    visit['i'-'a'] = true;
    visit['n'-'a'] = true;
    visit['t'-'a'] = true;
    alph['a'-'a'] = true;
    alph['c'-'a'] = true;
    alph['i'-'a'] = true;
    alph['n'-'a'] = true;
    alph['t'-'a'] = true;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s", words[i]);
        for(int j = 4; j < (int)strlen(words[i])- 4; j++) {
            if(alph[words[i][j] - 'a']) continue;
            else {
                alph[words[i][j] - 'a'] = true;
                alpha.push_back(words[i][j]);
            }
        }
    }
    if(k < 5) {
        printf("0");
        return 0;
    }
    if(k-5 >= alpha.size()) {
        for(int i =0; i < alpha.size(); i++) {
            visit[alpha[i]-'a'] = true;
        }
        printf("%d", canRead());
        return 0;
    }
    chooseAlpha(k - 5, 0);
    printf("%d", ans);
    
    
    return 0;
}
