#include <cstdio>
#include <vector>
using namespace std;

bool che[1000001];
int n, a[100];
vector<int> prime;
int cnt[100][80000];  
int totalCount[80000];  // 전체 숫자에서 소수가 나타난 횟수
int gcdCount[80000];    // gcd가 될 것 같은 횟수
int answer1, answer2;   // 가장 큰 점수, 최소 횟수

int main() {
    for (int i = 2 ; i <= 1000000 ; i++) {
        if (che[i]) continue;
        // i is prime
        for (int j = i + i ; j <= 1000000 ; j += i) {
            che[j] = true;
        }
    }
    for (int i = 2 ; i <= 1000000 ; i++) {
        if (!che[i]) {
            prime.push_back(i);
        }
    }

    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0 ; i < n ; i++) {
        int num = a[i];
        for (int j = 0 ; j < prime.size() ; j++) {
            while (num % prime[j] == 0) {
                cnt[i][j]++;
                totalCount[j]++;
                num /= prime[j];
            }
        }
    }
    for (int i = 0 ; i < prime.size() ; i++) {
        gcdCount[i] = totalCount[i] / n;
    }
    answer1 = 1;
    for (int i = 0 ; i < prime.size() ; i++) {
        for (int j = 0 ; j < gcdCount[i] ; j++) {
            answer1 *= prime[i];
        }
        for (int j = 0 ; j < n ; j++) {
            if (cnt[j][i] < gcdCount[i]) {
                answer2 += gcdCount[i] - cnt[j][i];
            }
        }
    }
    printf("%d %d", answer1, answer2);

}
