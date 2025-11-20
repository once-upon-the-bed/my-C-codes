#include <stdio.h>
void swap(int *a,int *b);
void permute(int arr[],int left,int right);
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    permute(arr, 0, n - 1);
    printf("\n");
    return 0;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void permute(int arr[], int left, int right) {
    if (left == right) {
        for (int i = 0; i <= right; i++) {
            printf("%d", arr[i]);
        }
        printf(" ");
    } else {
        for (int i = left; i <= right; i++) {
            swap(&arr[left], &arr[i]);
            permute(arr, left + 1, right);
            swap(&arr[left], &arr[i]);
        }
    }
}
