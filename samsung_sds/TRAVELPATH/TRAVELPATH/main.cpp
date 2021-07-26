//
//  main.cpp
//  TRAVELPATH
//
//  Created by 유병헌 on 2021/07/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<string> answer;

int flag = 0;
void dfs(string str, vector<string> v, vector<vector<string>> tickets) {
    if(flag == 1) return;
    if(tickets.size() == 0) {
        flag = 1;
        answer = v;
        return;
    }
    priority_queue<string, vector<string>, greater<string>> pq;
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == str) {
            pq.push(tickets[i][1]);
        }
    }
    while (!pq.empty()) {
        string now = pq.top();
        pq.pop();
        v.push_back(now);
        for(int i = 0; i < tickets.size(); i++) {
            if(tickets[i][0] == str && tickets[i][1] == now) {
                tickets.erase(tickets.begin() + i);
                break;
            }
        }
        dfs(now, v, tickets);
        v.pop_back();
        vector<string> tmp;
        tmp.push_back(str);
        tmp.push_back(now);
        tickets.push_back(tmp);
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    answer.clear();
    answer.push_back("ICN");
    flag = 0;
    dfs("ICN", answer, tickets);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> tickets;
    vector<string> t = {"ICN", "SFO"};
    tickets.push_back({"ICN", "ATL"});
    tickets.push_back({"SFO", "ATL"});
    tickets.push_back({"ATL", "ICN"});
    tickets.push_back({"ICN", "SFO"});
    tickets.push_back({"ATL", "SFO"});
    
    vector<string> v = solution(tickets);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}
