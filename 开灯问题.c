/*首先所有灯都是关的，然后，编号为1的倍数的灯开关改变，编号为2的倍数的灯开关改变……，直到n，
  求，第n轮后，还有哪几盏灯是开着的*/
//灯开着<=>开关改变奇数次<=>完全平方数
//注意输出时的空格
# include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i*i<n;i++){
        if(i*i==1){
            printf("%d",i*i);
        }else{
            printf(" %d",i*i);
        }
    }
    return 0;
}
