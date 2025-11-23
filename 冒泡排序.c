void sort(int example[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(example[j] > example[j + 1]) {
                int temp = example[j];
                example[j] = example[j + 1];
                example[j + 1] = temp;
            }
        }
    }
}
