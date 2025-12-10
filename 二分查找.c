# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define number 10
int binary_search(int [],int,int);
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
    int target;
    int location;
    scanf("%d",&target);
    location=binary_search(array,number,target);
    if(location>0){
        printf("%d",location);
    }else{
        printf("NOT FOUND");
    }
    return 0;
}
int binary_search(int array[],int n,int target){
    int location=-1;
    int flag=0;
    int left=0;
    int right=n-1;
    while(!flag&&left<=right){
        int middle=(int)((left+right)/2);
        if(target==array[middle]){
            location=middle+1;
            flag=1;
        }else if(target>array[middle]){
            left=middle+1;
        }else{
            right=middle-1;
        }
    }
    return location;
}
