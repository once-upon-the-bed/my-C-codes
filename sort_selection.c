# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define number 10
int selection_sort(int [],int);
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
    int move=selection_sort(array,number);
    print_array(array,number);
    printf("%d",move);
    return 0;
}
int selection_sort(int array[],int n){
    int move=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(array[j]<array[min]){
                min=j;
            }
        }
        if(min>i){
            int temp=array[i];
            array[i]=array[min];
            array[min]=temp;
            move++;
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
