# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define number 10
int bubble_sort(int [],int);
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
    flag=0;
    for(int i=0;i<number;i++){
        if(flag){
            printf(" ");
        }
        printf("%d",array[i]);
        flag=1;
    }printf("\n");
    printf("%d",move);
    return 0;
}
int bubble_sort(int array[],int n){
    int move=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(array[i]>array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                move++;
            }
        }
    }
    return move;
}
