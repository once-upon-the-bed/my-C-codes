#include <stdio.h>
#include <math.h>

void sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    float example[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &example[i]);
    }
    sort(example, n);
    float sum = 0;
    for (int i = 1; i < n - 1; i++) {
        sum += example[i];
    }
    float average = sum / (n - 2);
    float difference = 0;
    for (int i = 1; i < n - 1; i++) {
        float diff = fabs(example[i] - average);
        if (diff > difference) {
            difference = diff;
        }
    }
    printf("%.2f %.2f", average, difference);
    return 0;
}
