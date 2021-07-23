
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> numbers;

int solution(int number) {
    int result = 0;
    if(number == 0) return 1;
    if(number < 0) return 0;
    
    result = solution(number-1) + solution(number -2) + solution(number - 3);
    return result;
}
// 1. 1로만
// 2. 1과 2로만 (1의 개수중에 2개 선택)
// 3. 1과 3로만 (1의 개수중에
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        int temp;
        scanf("%d", &temp);
        numbers.push_back(temp);
    }
    for(int i = 0; i < n; i ++) {
        printf("%d\n", solution(numbers[i]));
    }
}
