

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int n;
vector<string> op;
typedef long long LL;
LL max_num = 1000000000;
stack<LL> s;

string goStack(LL number) {
    s.push(number);
    int i;
    for(i = 0; i < op.size(); i++) {
        if(op[i] == "NUM") {
            s.push(LL(stoi(op[i + 1])));
            i++;
        }
        if(s.size() == 0) {
            return "Error";
        }
        if(op[i] == "POP") {
            s.pop();
        }
        else if(op[i] == "INV") {
            LL temp = s.top();
            s.pop();
            s.push(-temp);
        }
        else if(op[i] == "DUP") {
            s.push(s.top());
        }
        else if (op[i] == "SWP") {
            LL first = s.top();
            s.pop();
            if(s.size() == 0) {
                return "ERROR";
            }
            LL second = s.top();
            s.pop();
            s.push(first);
            s.push(second);
        }
        else if (op[i] == "ADD") {
            LL first = s.top();
            s.pop();
            if(s.size() == 0){
                return "ERROR";
            }
            LL second = s.top();
            s.pop();
            LL result = first + second;
            if(result > max_num || result < -max_num){
                return "ERROR";
            }
            s.push(first+second);
        }
        else if (op[i] == "SUB") {
            LL first = s.top();
            s.pop();
            if(s.size() == 0){
                return "ERROR";
            }
            LL second = s.top();
            s.pop();
            LL result = second - first;
            if(result < -max_num || result > max_num){
                return "ERROR";
            }
            s.push(second - first);
        }
        else if (op[i] == "MUL") {
            LL first = s.top();
            s.pop();
            if(s.size() == 0){
                return "ERROR";
            }
            LL second = s.top();
            s.pop();
            LL result = first * second;
            if(result > max_num || result < -max_num){
                return "ERROR";
            }
            s.push(first*second);
        }
        else if (op[i] == "DIV") {
            LL first = s.top();
            s.pop();
            if(s.size() == 0) {
                return "ERROR";
            }
            if(first == 0){
                return "ERROR";
            }
            LL second = s.top();
            s.pop();
            LL res = abs(second) / abs(first);
            if(abs(res) > max_num) return "ERROR";
            if((first < 0 && second > 0) || (first > 0 && second <0)) res = -res;
            s.push(res);
        }
        else if (op[i] == "MOD") {
            LL first = s.top();
            s.pop();
            if(first == 0){
                return "ERROR";
            }
            if(s.size() == 0){
                return "ERROR";
            }
            LL second = s.top();
            LL res = abs(second) % abs(first);
            s.pop();
            
            if(abs(res) > max_num) return "ERROR";
            if(second < 0) res = -res;
        
            s.push(res);
        }
        
    }
    if(s.size() != 1) {
        return "ERROR";
    }
    
    return to_string(s.top());
}

int main() {
    
    string str;
    freopen("File.strings", "r", stdin);
    while(true){
        op.clear();
        vector<string>().swap(op);
        while (true) {
            cin >> str;
            if(str == "QUIT") return 0;
            if(str == "END") break;
            op.push_back(str);
            if(str == "NUM") {
                cin >> str;
                op.push_back(str);
            }
        }
        cin >> n;
        for(int i = 0; i < n; i++) {
            LL temp;
            cin >> temp;
            cout << goStack(temp) << endl;
            while(!s.empty()) {
                s.pop();
            }
            
        }
        cout << endl;
    }
    
    return 0;
}
