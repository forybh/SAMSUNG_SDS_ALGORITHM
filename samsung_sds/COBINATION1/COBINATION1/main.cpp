

#include <iostream>
int n,k;
int main(int argc, const char * argv[]) {
    scanf("%d%d", &n, &k);
    int answer = 1;
    int range = n - k;
    for(int i = 0; i < range; i++) {
        answer *= n - i;
    }
    for(int i = 1; i <= range; i++) {
        answer /= i;
    }
    printf("%d", answer);
    return 0;
}
