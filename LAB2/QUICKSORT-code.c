#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 50000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, n, a[MAX], ch;
    clock_t start, end;

    while(1) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);

        for(i = 0; i < n; i++) {
            a[i] = rand() % 200;
        }

        printf("The random numbers generated are: ");
        for(i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("The sorted array is: ");
        for(i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        printf("Time taken = %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        printf("\nDo you wish to continue (0/1): ");
        scanf("%d", &ch);
        if(ch == 0) break;
    }

    return 0;
}

int partition(int a[], int low, int high) {
    int key, i, j, temp;

    key = a[low];
    i = low + 1;
    j = high;

    while(i <= j) {
        while(i <= high && a[i] <= key)
            i++;
        while(a[j] > key)
            j--;
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
        }
    }

    return j;
}

void quicksort(int a[], int low, int high) {
    if(low < high) {
        int mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}
