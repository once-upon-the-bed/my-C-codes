# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define number 10
int partition_hoare(int [],int left,int right);
int partition_lomuto(int [],int left,int right);
void quick_sort(int [],int,int);
void print_array(int [],int);
void swap(int*,int*);
int main()
{
    srand(time(NULL));
    int array[number];
    for(int i=0;i<number;i++){
        array[i]=1+(int)(rand()%20);
    }
    int flag=0;
    for(int i=0;i<number;i++){
        if(flag){
            printf(" ");
        }
        printf("%d",array[i]);
        flag=1;
    }printf("\n");
    quick_sort(array,0,number-1);
    printf_array(array,number);
    return 0;
}
int partition_hoare(int array[],int left,int right){
    int pivot=array[left];
    while(left<right){
        while(array[right]>=pivot&&left<right){
            right--;
        }
        if(right!=left){
            array[left]=array[right];
            left++;
        }
        while(array[left]<=pivot&&left<right){
            left++;
        }
        if(right!=left){
            array[right]=array[left];
            right--;
        }
    }
    array[left]=pivot;
    return left;
}
int partition_lomuto(int array[],int left,int right){
    int pivot=array[right];
    int i=left-1;
    for(int j=left;j<right;j++){
        if(array[j]<=pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[right]);
    return i+1;
}
void quick_sort(int array[],int left,int right){
    int pivot;
    pivot=partition_hoare(array,left,right);
    if(left<pivot){
        quick_sort(array,left,pivot-1);
    }
    if(right>pivot){
        quick_sort(array,pivot+1,right);
    }
}
void print_array(int array[],int n){
    int flag=0;
    for(int i=0;i<n;i++){
        if(flag){
            printf(" ");
        }
        printf("%d",array[i]);
        flag=1;
    }printf("\n");
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
