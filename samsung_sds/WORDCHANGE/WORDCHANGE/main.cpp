//
//  main.cpp
//  WORDCHANGE
//
//  Created by 유병헌 on 2021/07/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

bool check_change(string str1, string str2) {
    int cnt = 0;
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i]) {
            cnt ++;
        }
    }
    return cnt == 1? true : false;
}
int findIndex(string str, vector<string> words) {
    for(int i = 0; i < words.size(); i++) {
        if(words[i] == str) return i;
    }
    return (int)words.size();
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int visited[words.size() + 1];
    for(int i = 0; i < words.size() + 1; i++) {
        visited[i] = 0;
    }
    int target_index = findIndex(target, words);
    if(findIndex(target, words) == words.size()) return 0;
    queue<string> q;
    q.push(begin);
    while(!q.empty()) {
        string str = q.front();
        cout << str << endl;
        q.pop();
        int index = findIndex(str, words);
        for(int i = 0; i < words.size(); i++) {
            if(check_change(str, words[i])) { //바꿀 수 있어
                if(i == target_index) {
                    if(visited[target_index] > visited[index] + 1) {
                        answer = visited[index] + 1;
                    }
                }
                if(visited[i] <= visited[index] + 1 && visited[i] != 0) {
                    continue;
                }
                q.push(words[i]);
                visited[i] = visited[index] + 1;
            }
        }
    }
    return visited[target_index];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << solution("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"});
    return 0;
}
