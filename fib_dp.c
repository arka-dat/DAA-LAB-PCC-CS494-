#include <stdio.h>
int fib_dp(int n) {
    if (n <= 1) return n; 


    int fib[n + 1];

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("Fibonacci of %d = %d\n", i, fib[i]);
    }

    return fib[n];
}

int main() {
    int num;
    printf("Enter the number for which to find Fibonacci = ");
    scanf("%d", &num);
    printf("\n The %dth Fibonacci number = %d\n", num, fib_dp(num));

    return 0;
}