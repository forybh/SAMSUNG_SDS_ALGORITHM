
#include <iostream>
#include <vector>
using namespace std;

int n, t;
int a[100000];
char b[50002];
int cnt;

void solution(int idx, vector<char> v) {
    if(v.size() == n) {
        vector<char> a1;
        for(int i = 0; i < t; i++) {
            a1.push_back('0');
        }
        vector<char> a2;
        for(int i = 0; i < n; i++) {
            a1.push_back(v[i]);
            a2.push_back(v[i]);
        }
        for(int i = 0; i < t; i++) {
            a2.push_back('0');
            a2.erase(a2.begin());
            a1.pop_back();
        }
        bool flag = true;
        for(int i = 0; i < n; i++) {
            char res = '1';
            if(a1[i] == '0' && a2[i] =='0') {
                res = '0';
            }
            else {
                res = '1';
            }
            if(b[i] == res) continue;
            else flag = false;
        }
        if (flag) {
            for(int i = 0; i < v.size(); i++) {
                cout << a[i];
            }
        }
        cnt++;
        return;
    }
    for(int i = idx; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            v.push_back(j);
            solution(i, v);
            v.pop_back();
        }
    }
}
    
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cnt = 0;
        cin >> n >> t;
        cin >> b;
        cout << "Case #" << test_case+1 << "\n";
        
        
        if(cnt == 0) {
            vector<char> v;
            solution(0, v);
        }
        else {
            cout << "\n";
            break;
        }
        
    }
    return 0;
}
