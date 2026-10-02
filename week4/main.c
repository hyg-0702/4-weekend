#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&a[i], &a[min_idx]);
        }
    }
}

int binary_search(const int a[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == key) { 
            return mid;
        }
        if (a[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main(void) {
    int scores[5];
    int target;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &scores[i]);
    }

    scanf("%d", &target);

    selection_sort(scores, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d", scores[i]);
        if (i < 4) {
            printf(" ");
        }
    }
    printf("\n");

    int result_index = binary_search(scores, 5, target);
    printf("%d\n", result_index);

    return 0;
}
