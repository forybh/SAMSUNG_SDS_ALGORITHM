
#include <iostream>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int a,b,c,d;
int main(int argc, const char * argv[]) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    int up = a * d + b * c;
    int down = b * d;
    int g = gcd(up, down);
    
    printf("%d %d", up/g, down/g);
    
}
