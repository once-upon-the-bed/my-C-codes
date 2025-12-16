# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define number 10
int bubble_sort(int [],int);
void print_array(int [],int);
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
    int move=bubble_sort(array,number);
    printf_array(array,number);
    printf("%d",move);
    return 0;
}
int bubble_sort(int array[],int n){
    int move=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                move++;
            }
        }
    }
    return move;
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
