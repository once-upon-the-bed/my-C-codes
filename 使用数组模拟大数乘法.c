# include<stdio.h>
int main()
{
    const int NUMBER=10000;
    int result[NUMBER];
    result[0]=1;
    int result_size=1;
    for(int i=2;i<=100;i++){
        int carry=0;
        for(int j=0;j<result_size;j++){
            int product=result[j]*i+carry;
            result[j]=product%10;
            carry=product/10;
        }
        while(carry){
            result[result_size]=carry%10;
            carry/=10;
            result_size++;
        }
    }
    for(int i=result_size-1;i>=0;i--){
        printf("%d",result[i]);
    }
    return 0;
}
