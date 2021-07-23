
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int Answer;
int friends[100000];

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, test_case;

    cin >> T;
    
    for(test_case = 0; test_case  < T; test_case++){
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> friends[i];
        }
        Answer = 0;
        for(int i = 0; i < N; i++) {
            if(i + friends[i] >= N) Answer++;
        }
        cout << "Case #" << test_case+1 << "\n";
        cout << Answer << "\n";
    }

    return 0;
}
// 0 1 2 3 4 5 6 7 8
// 3 5 6 7 1 4 5 6 2
