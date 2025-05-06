#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[20], count = 1;

void queens(int, int);
int place(int, int);

int main() {
    int n, k = 1;
    printf("Enter the number of queens to be placed: ");
    scanf("%d", &n);
    if (n > 20 || n < 1) {
        printf("Please enter a number between 1 and 20.\n");
        return 1;
    }
    queens(k, n);
    return 0;
}

void queens(int k, int n) {
    int i, j;
    for (j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j;
            if (k == n) {
                printf("\nSolution %d:\n", count++);
                for (i = 1; i <= n; i++) {
                    printf("Row %d <---> Column %d\n", i, x[i]);
                }
                printf("\n");
            } else {
                queens(k + 1, n);
            }
        }
    }
}

int place(int k, int j) {
    int i;
    for (i = 1; i < k; i++) {
        if (x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    }
    return 1;
}
