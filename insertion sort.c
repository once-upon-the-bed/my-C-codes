# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define number 10
int insertion_sort(int [],int);
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
    int move=insertion_sort(array,number);
    print_array(array,number);
    printf("%d",move);
    return 0;
}
int insertion_sort(int array[],int n){
    int move=0;
    for(int i=0;i<n;i++){
        int key=array[i];
        int j=i-1;
        while(j>=0&&array[j]>key){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
        move++;
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
