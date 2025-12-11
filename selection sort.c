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
        int min_value=array[i];
        int min_location=i;
        for(int j=i+1;j<n;j++){
            if(array[j]<min_value){
                min_value=array[j];
                min_location=j;
            }
        }
        if(min_value<array[i]){
            int temp=array[i];
            array[i]=min_value;
            array[min_location]=temp;
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
